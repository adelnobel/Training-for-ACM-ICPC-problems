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

using namespace std;


vector< int > adj[1005];

int dist[1010];

int costs[1010][1010];

int main()
{
    //freopen("in.in", "r", stdin);
    int t, e, v, a, b, c, prevN = 0;
    
    scanf("%d", &t);
    
    while(t--)
    {
        for(int i = 0; i < prevN; i++)
            adj[i].clear();
        scanf("%d %d", &v, &e);
        prevN = v;
        
        for(int x = 0; x < 1010; x++)
            dist[x] = 1 << 30;
        
        for(int x = 0; x < e; x++){
            scanf("%d %d %d", &a, &b, &c);
            adj[a].push_back(b);
            costs[a][b] = c;
        }
        bool changed = true;
        for(int i = 0; i < v-1 && changed; i++){
            changed = false;
            for(int j = 0;j < v; j++){
                for(int k = 0; k < adj[j].size(); k++){
                    if(dist[adj[j][k]] > dist[j] + costs[j][adj[j][k]])  {
                        dist[adj[j][k]] = dist[j] + costs[j][adj[j][k]];
                        changed = true;
                    }
                }
            }
        }
        bool hasCycle = false;
        for(int j = 0;j < v; j++){
                for(int k = 0; k < adj[j].size(); k++){
                    if(dist[adj[j][k]] > dist[j] + costs[j][adj[j][k]])
                        hasCycle = true;
                }
        }
        
        if(hasCycle)
             printf("possible\n");
        else
            printf("not possible\n");
        
    }
    return 0;
}