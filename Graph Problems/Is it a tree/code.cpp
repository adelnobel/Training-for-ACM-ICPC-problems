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

int t, n, s, d, p, e; 

bool marked[10005];
map< int, vector<int> > neighb;

bool isTree(int node)
{
    //An undirected simple graph is a tree if it is CONNECTED and has n ? 1 edges. (N Nodes)
    //Use bfs or dfs to check connectivity
    
    queue<int> q;
    q.push(node);
    marked[node] = true;
    int tot = 0;
    
    while(!q.empty())
    {
        int no = q.front();
        tot++;
        q.pop();
        vector<int> ne = neighb[no];
        for(int x = 0; x < ne.size(); x++)
        {
            if(!marked[ne[x]])
            {
                q.push(ne[x]);
                marked[ne[x]] = true;
            }
        }
    }
    
    return (tot-1 == e);
}

int main()
{
    scanf("%d %d", &n, &e);
    set<int> nodes;
    int randomNode;
    for(int x = 0; x < e; x++)
    {
        scanf("%d %d", &d, &p);
        if(neighb.count(d) == 0)
            neighb[d] = vector<int>();
        if(neighb.count(p) == 0)
            neighb[p] = vector<int>();
        
        neighb[d].push_back(p);
        neighb[p].push_back(d);
        randomNode = p;
        
    }
    
    memset(marked, 0, sizeof(marked));
    bool tree = isTree(randomNode);
    
    if(tree)
        printf("YES\n");
    else
        printf("NO\n");
    
    
    
    return 0;
}
