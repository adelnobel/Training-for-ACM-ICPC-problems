#include <algorithm>
#include <functional>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <cstring>

using namespace std;

int t, n, s, d, p, e, l, w; 

int di[20002][20002];
int marked[20002];

typedef struct Edge{
    int orig, dist, cost;
    Edge(int o, int d, int c): orig(o), dist(d), cost(c){};
    bool operator<(const Edge a) const //Comparator for priority_queue
    {
        return cost > a.cost;
    }
    
}Edge;



int main()
{

    scanf("%d", &t);
    
    for(int x = 0; x < t; x++)
    {
        scanf("%d %d %d %d", &s, &n , &l, &e);
        vector<Edge> adj[20002]; //Vector of int's that maps to Edges, for every vertex, store all its edges!
        memset(marked, -1, sizeof marked);
        
        while(n--)
        {
            scanf("%d %d %d", &d, &p, &w);
            
            adj[d].push_back(Edge(d, p, w));
            adj[p].push_back(Edge(p, d, w));
            
            //marked[d] = marked[p] = 0;
            
        }
        
        priority_queue<Edge> q;
        
        q.push(Edge(l , l, 0));
        marked[l] = 0;
        
        while(!q.empty())
        {
            Edge cur = q.top(); q.pop();
            
            for(int w = 0; w < adj[cur.dist].size(); w++ ) //For Each outgoing Edge
            {
                Edge outEdge = adj[cur.dist][w];
                

                if(marked[outEdge.dist] == -1 || marked[outEdge.dist] > marked[outEdge.orig] + outEdge.cost)
                {
                    marked[outEdge.dist] = marked[outEdge.orig] + outEdge.cost ;
                    q.push(Edge(outEdge.orig, outEdge.dist, marked[outEdge.dist]));
                }
            }
        }
        

        if(marked[e] == -1)
            printf("Case #%d: unreachable\n", x+1);
        else
            printf("Case #%d: %d\n", x+1, marked[e] );
    }
    

    return 0;
}
