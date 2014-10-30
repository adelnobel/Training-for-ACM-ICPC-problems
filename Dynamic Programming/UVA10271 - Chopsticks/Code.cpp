#include <vector>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <bitset>
#include <map>
#include <complex>
#include <ctime>
#include <numeric>
#include <set>
#include <cassert>

using namespace std;

typedef long long ll;
typedef pair<ll, int> pi;

int n, k, t, x;
vector< int > v;

#define N 5005
#define K 1015

ll dp[K][N];

ll solve(int taken, int left){
    if(taken == k) return 0;
    int idx = left + taken*2;
    if(idx >= v.size()) return 1LL << 60;
    ll& ret = dp[taken][left];
    if(ret != -1) return ret;
    ret = solve(taken, left + 1);
    if(left > taken && idx+1 < v.size()){
        ll d = v[idx+1] - v[idx];
        ret = min(ret, solve(taken+1, left) + d*d);
    }
    return ret;
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    
    scanf("%d", &t);
    
    while(t--){
        memset(dp, -1, sizeof dp);
        v.clear();
        scanf("%d %d", &k, &n);
        k += 8;
        for(int i = 0; i < n; i++){
            scanf("%d", &x);
            v.push_back(x);
        }
        reverse(v.begin(), v.end());
        cout << solve(0, 0) << endl;
    }
    
    
    return 0;
}
