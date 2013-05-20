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
    int orig, dist, cost;
    bool operator<(const edge &e) const
    {
        return cost > e.cost;
    }
}edge;

typedef struct node
{
    int n;
    vector<edge> edges;
}node;

int t, p, n, m, a , b ,c;

bool marked[2111];

void push_edges(int n, vector<node> &v ,priority_queue<edge> &e)
{
    for(int x = 0; x < v[n-1].edges.size(); x++)
    {
        e.push(v[n-1].edges[x]);
    }
    marked[n] = true;
}

int main()
{
    scanf("%d", &t);
    
    while(t--)
    {
        memset(marked, false, sizeof marked);
        scanf("%d %d %d", &p, &n, &m);
        vector<node> v;
        v.reserve(n);
        for(int x = 0; x < m; x++)
        {
            edge e1;
            edge e2;
            scanf("%d %d %d", &a, &b, &c);
            e1.orig = a; e1.dist = b; e1.cost = c;
            e2.orig = b; e2.dist = a; e2.cost = c;
            
            v[e1.orig-1].edges.push_back(e1);
            v[e2.orig-1].edges.push_back(e2);
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
        
        printf("%d\n", p * totLength);
        
        
    }
    
    
    return 0;
}
  