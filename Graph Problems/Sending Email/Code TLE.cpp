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
bool marked[20002];
int costs[20002];

#define INF 1 << 30

typedef struct Node
{
    int n;
    int cost;
    Node(int n, int c): n(n), cost(c){};
    
    bool operator<(const Node b) const
    {
        return cost > b.cost;
    }
    
}Node;

vector<int> neighbours[20002];
int main()
{

    scanf("%d", &t);
    
    for(int x = 0; x < t; x++)
    {
        scanf("%d %d %d %d", &s, &n , &l, &e);
        for(int tt= 0; tt < 20002; tt++)
            neighbours[tt].clear();
        while(n--)
        {
            scanf("%d %d %d", &d, &p, &w);
            
            di[d][p] = di[p][d] = w;
            di[d][d] = di[p][p] = 0;
            neighbours[d].push_back(p);
            neighbours[p].push_back(d);
        }
        
        memset(marked, false, sizeof marked);
        for(int tt = 0; tt < 20002; tt++)
            costs[tt] = INF;
        priority_queue<Node> q;
        
        q.push(Node(l, 0));
        
        while(!q.empty())
        {
            Node cur = q.top(); q.pop();
            
            if(marked[cur.n] || cur.n == e)
                break;
            marked[cur.n] = true;
            
            for(int w = 0; w < neighbours[cur.n].size(); w++)
            {
                int nei = neighbours[cur.n][w];
                if(!marked[nei] && costs[nei] > cur.cost + di[cur.n][nei])
                {
                    q.push(Node(nei, cur.cost + di[cur.n][nei] ));
                }
                if(costs[nei] > cur.cost + di[cur.n][nei])
                {
                    costs[nei] = cur.cost + di[cur.n][nei];
                }
            }
        }
        

        if(costs[e] == INF)
            printf("Case #%d: unreachable\n", x+1);
        else
            printf("Case #%d: %d\n", x+1, costs[e] );
    }
    

    return 0;
}
