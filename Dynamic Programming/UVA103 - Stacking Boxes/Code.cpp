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
typedef pair<int, int> pi;

#define N 35

vector< int > adj[N];

int dp[N];

int solve(int n){
    int &ret = dp[n];
    if(ret != -1) return ret;
    ret = 1;
    for(int i = 0; i < adj[n].size(); i++){
        ret = max(ret, solve(adj[n][i]) + 1);
    }
    
    return ret;
}

int path[N];

void bk(int cur, int n){
    if(adj[n].size() == 0){
        path[cur++] = n;
        return;
    }
    int& ret = dp[n];
    for(int i = 0; i < adj[n].size(); i++){
        if(solve(adj[n][i]) + 1 == ret){
            path[cur++] = n;
            return bk(cur, adj[n][i]);
        }
    }
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif

    int k, d, x;
    
    while(scanf("%d %d", &k, &d) == 2){
        memset(dp, -1, sizeof dp);
        for(int i = 0; i < N; i++) adj[i].clear();
        vector< vector< int > > vv;
        for(int i = 0; i < k; i++){
            vector< int > v;
            for(int j = 0;j < d; j++){
                scanf("%d", &x);
                v.push_back(x);
            }
            sort(v.begin(), v.end());
            vv.push_back(v);
        }
        for(int i = 0; i < vv.size(); i++){
            for(int j = 0; j < vv.size(); j++){
                if(i == j) continue;
                bool canBeNested = true;
                for(int w = 0; w < d && canBeNested; w++){
                    if(vv[i][w] >= vv[j][w]) canBeNested = false;
                }
                if(canBeNested){
                    adj[i].push_back(j);
                }
            }
        }
        
        int ans = 0;
        for(int i = 0; i < k; i++){
            int w = solve(i);
            if(w > ans){
                ans = w;
                bk(0, i);
            }
        }
        
        cout << ans << endl;
        printf("%d", path[0]+1);
        for(int i = 1; i < ans; i++){
            printf(" %d", path[i]+1);
        }
        printf("\n");
        
    }
    

    return 0;
}