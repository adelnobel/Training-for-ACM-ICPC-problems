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

int t, n, s, d, p, e, l, w, maxi, dist; 

vector<int> adj[105];
int marked[105];

int main()
{
    int cou = 0;

    while(1)
    {
        cou++;
        scanf("%d", &t);
        if(t == 0)
            break;
        scanf("%d", &s);
        for(int x = 0; x < 105; x++)
            adj[x].clear();
        maxi = 0;
        dist = s;
        while(1)
        {
            scanf("%d %d", &l , &e);
            if(l == 0 && e == 0)
                break;
            adj[l].push_back(e); 
        }
        
        
        memset(marked, -1, sizeof marked); 
        
        queue< pair<int, int> > q;
        
        q.push(make_pair(s, 0));
        
        while(!q.empty())
        {
            int node = q.front().first;
            int cost = q.front().second;
            q.pop();
            
            for(int y = 0; y < adj[node].size(); y++ )
            {
                if(marked[adj[node][y]] == -1 || marked[adj[node][y]] < cost + 1)
                {
                    marked[adj[node][y]] = cost + 1;
                    
                    if(maxi == marked[adj[node][y]])
                    {
                        if(dist > adj[node][y])
                        {
                            dist = adj[node][y];
                        }
                    }
                    if(maxi < marked[adj[node][y]])
                    {
                        maxi = marked[adj[node][y]];
                        dist = adj[node][y];
                    }
                    q.push(make_pair(adj[node][y], marked[adj[node][y]]));
                }
            }
            
        }
        
        printf("Case %d: The longest path from %d has length %d, finishing at %d.\n\n", cou, s, maxi, dist);
    }
    

    return 0;
}
