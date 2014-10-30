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

typedef pair<int, int> pi;
typedef long long ll;

const int N = 1005;

int n, dp[1 << 3][1 << 3][N][3];
int A[N][3];

int solve(int prevMask, int curMask, int col, int cur){
    if(cur == 3){
        return solve(curMask, 0, col + 1, 0);
    }
    if(col == n){
        return 0;
    }
    int& ret = dp[prevMask][curMask][col][cur];
    if(ret != -1) return ret;
    if(curMask & (1 << cur)) return ret = solve(prevMask, curMask, col, cur + 1);
    ret = solve(prevMask, curMask, col, cur + 1);
    if(cur < 2){
        ret = max(ret, solve(prevMask, curMask | (1 << cur) | (1 << (cur + 1)),
                 col, cur + 1) + A[col][cur] * A[col][cur + 1]
        );
    }
    if(col > 0 && !(prevMask & (1 << cur))){
        ret = max(ret, solve(prevMask, curMask | (1 << cur), col, cur + 1)
                       + A[col][cur] * A[col - 1][cur]
        );
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
    int tt = 1;

    while(cin >> n, n){
        int tot = 0;
        memset(dp, -1, sizeof dp);
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < n; j++){
                cin >> A[j][i];
                tot += A[j][i];
            }
        }
        cout << "Case " << tt++ << ": " << solve(0, 0, 0, 0) << '\n';
    }


    return 0;
}
