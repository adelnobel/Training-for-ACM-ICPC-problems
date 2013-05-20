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
 
using namespace std;

typedef struct edge{
    int cost, dist;
    
    edge(int d, int c){cost = c; dist = d;};
    
    bool operator<(const edge &e) const
    {
        return cost > e.cost;
    }
    
}edge;

vector< edge > adj[200001];

bool taken[200001];

void push_edges(int vertex, priority_queue<edge> &pq)
{
    for(int i = 0; i < adj[vertex].size(); i++)
        pq.push(adj[vertex][i]);
}

int main()
{
    //freopen("in.in", "r", stdin);
    
    int v, e, x, y, z, originalCost;
    int prevV = 0;
    
    while(1)
    {
        scanf("%d %d", &v, &e);
        if(v == 0 && e == 0) break;
        
        for(int i = 0; i < prevV; i++){
            adj[i].clear();
            taken[i] = false;
        }
        prevV = v;
        originalCost = 0;
        
        for(int i = 0; i < e; i++){
            scanf("%d %d %d", &x, &y, &z);
            adj[x].push_back(edge(y, z));
            adj[y].push_back(edge(x, z));
            originalCost += z;
        }
        
        priority_queue<edge> pq;
        
        push_edges(0, pq);
        taken[0] = true;
        int totalCost = 0;
        int totalTaken = 1;
        
        while(!pq.empty() && totalTaken < v)
        {
            edge cur = pq.top(); pq.pop();
            if(taken[cur.dist]) continue;
            push_edges(cur.dist, pq);
            taken[cur.dist] = true;
            totalCost += cur.cost;
            totalTaken++;
        }
        
        
        printf("%d\n", originalCost - totalCost);
        
        
        
    }
    
    
    return 0;
}