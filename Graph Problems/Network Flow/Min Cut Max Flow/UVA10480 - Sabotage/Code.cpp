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
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <limits>
#include <tr1/unordered_map>

/**
 Min cut Max flow theoresm states that, the minimum cut in a graph == the maximum flow
 * After getting the maximum flow, the residual graph will split the graph into 2 components
 * Do a DFS from the Start node on the residual graph using edges that still has capacity > 0 and mark all reachable nodes
 * in S component
 * S component which includes the Start node and all rachable nodes from it
 * T component which includes the Sink node and all unreachable nodes from the Start!
 * Now, EVERY edge that goes from a node in S component to a Node in T component SHOULD be removed.
 * 
 */

using namespace std;

typedef long long ll;

vector<int> adj[52];

ll costs[52][52];

int parents[52];

bitset<52> vis;
bitset<52> isInComponentS;

ll pushFlow(int s, int t)
{
    vis.reset();
    queue<int> q;
    q.push(s);
    parents[s] = -1;
    
    bool found = false;
    
    while(!q.empty()){
        int cur = q.front(); q.pop();
        if(cur == t){
            found = true;
            break;
        }
        for(int i = 0; i < adj[cur].size(); i++){
            int nei = adj[cur][i];
            if(costs[cur][nei] > 0 && !vis[nei]){
                parents[nei] = cur;
                q.push(nei);
                vis[nei] = 1;
            }
        }
    }
    
    if(!found) return 0;
    
    int cur = t;
    ll mini = 1 << 30;
    mini <<= 30;
    
    while(cur != s){
        mini = min(mini, costs[parents[cur]][cur]);
        cur = parents[cur];
    }
    
    cur = t;
    
    while(cur != s){
        costs[cur][parents[cur]] += mini;
        costs[parents[cur]][cur] -= mini;
        cur = parents[cur];
    }
    
    return mini;
}

ll maxFlow()
{
    ll flow = 0;
    
    while(1){
        ll curFlow = pushFlow(1, 2);
        if(curFlow ==0) break;
        flow += curFlow; 
    }
    
    return flow;
    
}

void dfs(int v)
{
    if(vis[v]) return ;
    vis[v] = true;
    
    isInComponentS[v] = true;
    for(int i = 0; i < adj[v].size(); i++){
        if(costs[v][adj[v][i]] > 0){ //All reachable nodes
             dfs(adj[v][i]);
        }
    }
}

void markVerticesOfComponent(int s)
{
    vis.reset();
    isInComponentS.reset();
    dfs(s);
}

int main()
{
    //freopen("in.in", "r", stdin);
    int prevV = 0;
    int e, v, a, b, c;
    
    while(1){
        scanf("%d %d", &v, &e);
        if(v == 0 && e == 0) break;
        
        
        for(int i = 0; i <= prevV; i++){
            adj[i].clear();
        }
        
        memset(costs, 0, sizeof costs);
        
        prevV = v;

        for(int i = 0; i < e; i++){
            scanf("%d %d %d", &a ,&b, &c);
            adj[a].push_back(b);
            adj[b].push_back(a);
            costs[a][b] += c;
            costs[b][a] += c;
        }
        
        int maxiFlow = maxFlow();
        
        markVerticesOfComponent(1);
        
        for(int i = 1; i <= v; i++){
            if(!isInComponentS[i]) continue;
            for(int j = 0; j < adj[i].size(); j++){
                if(!isInComponentS[adj[i][j]]){ //If this edge crosses from component S to component T
                    printf("%d %d\n", i, adj[i][j]);
                }
            }
        }
        //cout << maxiFlow;
        printf("\n");
    }
    
    
    
    return 0;
}