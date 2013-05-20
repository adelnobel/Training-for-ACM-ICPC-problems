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
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <bitset>


using namespace std;

/**
Dijkstra solution!
**/

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};



typedef struct state
{
    int x, y, cost;
    bool operator<(const state &s) const
    {
        return cost > s.cost;
    }
}state;

int costs[101][101];
char g[101][101];

int n;

int getCost(int x, int y)
{
    if(x >= n || x < 0 || y >= n || y < 0) return -11111111;
    return costs[x][y];
}

int dijkstra(int x, int y)
{
    for(int a = 0; a < n; a++)
        for(int b = 0; b < n; b++)
             costs[a][b] = 100000000;
    state s;
    s.cost = 0;
    s.x = x;
    s.y = y;
    priority_queue<state> pq;
    pq.push(s);
    
    while(!pq.empty())
    {
        state cur = pq.top(); pq.pop();
        if(cur.x >= n || cur.x < 0 || cur.y >= n || cur.y < 0) continue;
        if(g[cur.x][cur.y] == '3') {
            return cur.cost;
        }
        
        for(int a = 0; a < 4; a++)
        {
             if( getCost(cur.x + dx[a] , cur.y + dy[a]) > cur.cost + 1 )
             {
                state ne;
                ne.cost = cur.cost + 1;
                ne.x = cur.x + dx[a];
                ne.y = cur.y + dy[a];
                pq.push(ne);
                costs[ne.x][ne.y] = cur.cost + 1;
             }
        }
    }
    return 1111111;
}

int main()
{
    //freopen("in.in", "r", stdin);
    while(scanf("%d", &n) != EOF)
    {
        for(int x = 0; x < n; x++)
        {
            scanf("%s", g[x]);
        }
        
        int maxi = -111111;
        
        for(int x = 0; x < n; x++)
        {
            for(int y = 0; y < n; y++)
            {
                if(g[x][y] == '1')
                {
                    maxi = max(dijkstra(x, y), maxi);
                }
            }
        }
        
        printf("%d\n", maxi);
        
    }
    
    
    
    return 0;
}