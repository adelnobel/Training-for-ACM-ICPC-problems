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
#include <ctime>

using namespace std;

typedef struct edge
{
    int dist, cost;
    bool operator<(const edge &e) const
    {
        return cost > e.cost;
    }
}edge;


int t, p, n, m, a , b ,c;

bool marked[10111];

char str[50000];

void push_edges(int n, vector< vector<edge> > &v ,priority_queue<edge> &e)
{
    for(int x = 0; x < v[n-1].size(); x++)
    {
        e.push(v[n-1][x]);
    }
    marked[n] = true;
}

int main()
{
    scanf("%d", &t);
    
    while(t--)
    {
        memset(marked, false, sizeof marked);
        scanf("%d", &n);
        
        vector< vector<edge> > v;
        
        for(int w = 0; w < n; w++)
        {
            
            scanf("%s", str);
            scanf("%d", &m);
            v.push_back(vector<edge>());
            for(int y = 0; y < m; y++)
            {
                edge e1;
                scanf("%d %d", &a, &b);
                e1.dist = a; e1.cost = b;
                v[w].push_back(e1);
            }
        }
        
        
        int totLength = 0;
        int totMarked = 0;
        
        priority_queue<edge> pq;
        
        push_edges(1, v, pq);
        totMarked = 1;
        
        while(!pq.empty())
        {
            edge cur = pq.top(); pq.pop();
            if(marked[cur.dist])
                continue;
            
            
            push_edges(cur.dist, v, pq);
            totMarked++;
            totLength += cur.cost;
            
            if(totMarked == n)
                break;
        }
        
        printf("%d\n", totLength);
    }
    return 0;
}
  