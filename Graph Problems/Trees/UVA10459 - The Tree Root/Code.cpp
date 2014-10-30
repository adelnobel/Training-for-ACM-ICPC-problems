#include <cstdlib>
#include <iostream>
#include <vector>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

#define N 5010
#define INF 1e9

vector< int > adj[N];

int maxUp[N];
pair<int, int> maxDown[N][2];

int dfs(int v, int par){
    for(int i = 0; i < adj[v].size(); i++){
        int to = adj[v][i];
        if(to == par) continue;
        int val = dfs(to, v) + 1;
        if(val >= maxDown[v][0].first){
            swap(maxDown[v][0], maxDown[v][1]);
            maxDown[v][0].first = val;
            maxDown[v][0].second = to;
        }else{
            if(val > maxDown[v][1].first){
                maxDown[v][1].first = val;
                maxDown[v][1].second = to;
            }
        }
        
    }
    return maxDown[v][0].first;
}

void dfsUp(int v, int par){
    maxUp[v] = maxUp[par] + 1;
    if(maxDown[par][0].second == v){
        maxUp[v] = max(maxUp[v], maxDown[par][1].first + 1);
    }else{
        maxUp[v] = max(maxUp[v], maxDown[par][0].first + 1);
    }
    for(int i = 0; i < adj[v].size(); i++){
        int to = adj[v][i];
        if(to == par) continue;
        dfsUp(to, v);
    }
}



int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    
    
    int n, t, d;
    
    while(scanf("%d", &n) == 1){
        memset(maxDown, 0, sizeof maxDown);
        for(int i = 0; i < N; i++) adj[i].clear();
        for(int i = 1; i <= n; i++){
            scanf("%d", &t);
            for(int j = 0; j < t; j++){
                scanf("%d", &d);
                adj[i].push_back(d);
            }
        }
        
        maxUp[0] = -1;
        maxDown[0][0].first = -1;
        
        dfs(1, 0);
        dfsUp(1, 0);
        
        int bestHeight = INF, worstHeight = -INF;
        
        vector< int > best, worst;
        
        for(int i = 1; i <= n; i++){
            int val = max(maxUp[i], maxDown[i][0].first);
            //cout << i << " " << maxUp[i] << " " << maxDown[i][0].first << " " << maxDown[i][1].first << endl;
            if(val < bestHeight){
                bestHeight = val;
                best.clear();
            }
            if(val == bestHeight){
                best.push_back(i);
            }
            
            if(val > worstHeight){
                worstHeight = val;
                worst.clear();
            }
            if(val == worstHeight){
                worst.push_back(i);
            }
            
        }
        
        sort(best.begin(), best.end());
        sort(worst.begin(), worst.end());
        
        //cout << bestHeight << endl;
        //cout << worstHeight << endl;
        
        printf("Best Roots  :");
        for(int i = 0; i < best.size(); i++) printf(" %d", best[i]);
        printf("\nWorst Roots :");
        for(int i = 0; i < worst.size(); i++) printf(" %d", worst[i]);
        printf("\n");
    
    }
    
    
    return 0;
}
