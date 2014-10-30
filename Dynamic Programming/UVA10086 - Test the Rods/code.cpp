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

using namespace std;

#define INF (int)1e8

int T1, T2, n;
vector< pair<int, int> > sites[35];

int dp[301][35];

int solve(int t1, int idx, int t2){
    
    if(t1 < 0) return INF;
    if(t2 < 0) return INF;
    if(idx == n) return 0;
    
    
    int& ret = dp[t1][idx];
    if(ret != -1) return ret;
    ret = INF;
    
    for(int i = 0; i < sites[idx].size(); i++){
        ret = min(ret, solve(t1 - i, idx + 1, t2 - sites[idx].size() + i + 1) + 
                sites[idx][i].first + sites[idx][sites[idx].size() - i - 1].second
                );
    }
    
    return ret;
}

void bk(int t1, int idx, int t2, bool isF){
    
    if(t1 < 0) return ;
    if(t2 < 0) return ;
    if(idx == n) return;
    
    
    int& ret = dp[t1][idx];
    
    for(int i = 0; i < sites[idx].size(); i++){
        int v = solve(t1 - i, idx + 1, t2 - sites[idx].size() + i + 1) + 
                sites[idx][i].first + sites[idx][sites[idx].size() - i - 1].second;
        if(v == ret){
            if(!isF) printf(" ");
            printf("%d", i);
            return bk(t1 - i, idx + 1, t2 - sites[idx].size() + i + 1, false);
        }
    }
    
    return;
}


int main(){
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif 
    
    int m, x;
    
    while(1){
        scanf("%d %d", &T1, &T2);
        if(T1 == 0 && T2 == 0) break;
        memset(dp, -1, sizeof dp);
        for(int i = 0; i < 35; i++) sites[i].clear();
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            scanf("%d", &m);
            sites[i].push_back(make_pair(0, 0));
            for(int j = 0; j < m; j++){
                scanf("%d", &x);
                sites[i].push_back(make_pair(x, 0));
            }
            for(int j = 1; j <= m; j++){
                scanf("%d", &x);
                sites[i][j].second = x;
            }
        }
        
        cout << solve(T1, 0, T2) << endl;;
        bk(T1, 0, T2, true);
        cout << endl;
        cout << endl;
    }
    
}
