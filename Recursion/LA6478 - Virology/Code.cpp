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

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pi;

int A[15];
int cnt[15];

bool solve(int idx, int a, int b){
    if(a == 0 && b == 0){
        return true;
    }
    if(idx > 9) return false;
    if(cnt[idx] == 0) return solve(idx + 1, a, b);
    if(a > 0 && cnt[idx] >= 1 && cnt[idx + 1] >= 1 && cnt[idx + 2] >= 1){
        --cnt[idx], --cnt[idx + 1], --cnt[idx + 2];
        if(solve(idx, a - 1, b)) return true;
        ++cnt[idx], ++cnt[idx + 1], ++cnt[idx + 2];
    }
    if(cnt[idx] >= 2 && b > 0){
        cnt[idx] -= 2;
        if(solve(idx, a, b - 1)) return true;
        cnt[idx] += 2;
    }
    if(cnt[idx] == 3 && a > 0){
        cnt[idx] -= 3;
        if(solve(idx, a - 1, b)) return true;
        cnt[idx] += 3;
    }
    return false;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        memset(cnt, 0, sizeof cnt);
        for (int i = 0; i < 14; i++) {
            cin >> A[i];
            cnt[A[i]]++;
        }
        if(solve(1, 4, 1)){
            cout << "Vulnerable\n";
        }else{
            cout << "Immune\n";
        }

    }

    return 0;
}
