#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>
#include <tr1/unordered_set>
#include <tr1/unordered_map>

using namespace std;
using namespace tr1;

typedef pair<int, int> pi;
typedef long long ll;
typedef long double ld;

string S;
const int MOD = 1000000007;

int occ[10];
int NCR[105][105];

int ncr(int n, int r){
    if(r > n) return 0;
    if(n == r) return 1;
    if(r == 0) return 1;
    int& ret = NCR[n][r];
    if(ret != -1) return ret;
    ret = ncr(n - 1, r - 1) + ncr(n - 1, r);
    if(ret >= MOD) ret -= MOD;
    return ret;
}

ll dp[103][10][11];

ll solve(int pos, int neg, int digit, int mod){
    if(digit == 10) {
        return (pos == 0 && neg == 0 && mod == 0);
    }
    ll& ret = dp[pos][digit][mod];
    if(ret != -1) return ret;
    if(occ[digit] == 0) return ret = solve(pos, neg, digit + 1, mod);
    ret = 0;
    for(int i = 0; i <= occ[digit]; i++){
        int a = i;
        int b = occ[digit] - i;
        if(a <= pos && b <= neg){
            int nMod = digit * (-b + a) + mod + 11;
            nMod %= 11;
            if(nMod < 0) nMod += 11;
            ret += solve(pos - a, neg - b, digit + 1, nMod) % MOD * ncr(pos, a) % MOD * ncr(neg, b) % MOD;
            if(ret >= MOD) ret %= MOD;
        }
    }
    return ret;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(NCR, -1, sizeof NCR);
    while(cin >> S){
        memset(occ, 0, sizeof occ);
        for(int i = 0; i < S.size(); i++){
            occ[S[i] - '0']++;
        }
        int pos = S.size() / 2;
        int neg = pos + (S.size() & 1);
        ll total = 0;
        for(int i = 1; i <= 9; i++){
            if(occ[i] > 0){
                occ[i]--;
                memset(dp, -1, sizeof dp);
                if(S.size() & 1){
                    total += solve(pos, neg - 1, 0, 11 - i);
                }else{
                    total += solve(pos - 1, neg, 0, i);
                }
                occ[i]++;
                total %= MOD;
            }
        }
        cout << total << '\n';
    }

    return 0;
}
