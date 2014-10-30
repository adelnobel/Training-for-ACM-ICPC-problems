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

typedef long long ll;
typedef long double ld;

const int N = 1008;

char dp[N][N];
vector< int > adj[N];

bool solve(int a, int b){
    if(a > b) swap(a, b);
    if(a == b){
        return a == 1;
    }
    char& ret = dp[a][b];
    if(ret != -1) return ret;
    ret = 0;
    for(int i = 0; i < adj[b].size() && !ret; i++){
        ret = solve(a, adj[b][i]);
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

    int n, m, a, b;
    while(cin >> n >> m){
        memset(dp, -1, sizeof dp);
        for(int i = 0; i < m; i++){
            cin >> a >> b;
            adj[b].push_back(a);
        }

        int tot = 0;

        for(int i = 1; i <= n; i++){
            for(int j = i + 1; j <= n; j++){
                tot += solve(i, j);
            }
        }

        cout << tot << '\n';

        for(int i = 0; i <= n; i++){
            adj[i].clear();
        }

    }

    return 0;
}
