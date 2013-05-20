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

#define N 102

int n, m,c, a , b, t;

typedef struct
{
    int cost, dist;
}edge;

typedef struct node
{
    int n, cost;
    bool operator<(const node &no) const
    {
        return cost > no.cost;
    }
}node;



char str[2000];
char str1[2000];

bool marked[10002];
int costs[10002];
vector< node > con[10002];

void dijkstra(int v, int dist)
{
    memset(marked, false, sizeof marked);
    for(int x = 0; x < 10002; x++)
        costs[x] = 1 << 30;
    
    priority_queue<node> pq;
    
    node n;
    n.n = v;
    n.cost = 0;
    costs[v] = 0;
    
    pq.push(n);
    
    while(!pq.empty())
    {
        node cur = pq.top(); pq.pop();
        if(marked[cur.n]) //If marked before continue! (We should already had visited this vertex before with a lower cost
            continue;
        marked[cur.n] = true; //Once we reach a node mark it as visited! This is the LEAST cost we can reach this vertex with!
        if(cur.n == dist) //If we reach distination break!!
            break;
        
        for(int x = 0; x < con[cur.n].size(); x++ )
        {
            if(!marked[con[cur.n][x].n] && costs[con[cur.n][x].n] > cur.cost + con[cur.n][x].cost)
            {//IMPORTANT!! Only push if that neighbor node was never marked before and the current cost is less than its cost in the final array
                //Its cost in the final array will be initially set to 1 << 30 or Infinity!
                node n;
                n.cost = cur.cost + con[cur.n][x].cost;
                n.n = con[cur.n][x].n;
                pq.push(n);
            }
            if(costs[con[cur.n][x].n] > cur.cost + con[cur.n][x].cost)
            {
                costs[con[cur.n][x].n] = cur.cost + con[cur.n][x].cost; //If cur cost is less than the previous cost calculated => Then UPDATE the cost!
            }
        }
    }
}

int main()
{
    map<string, int> my;
    //map<int, string> my2;
    
    scanf("%d", &n);
    for(int x = 0; x < n ; x++)
    {
        my.clear();
        //my2.clear();
        scanf("%d", &c);
        for(int w = 1; w <= c; w++)
        {
            scanf("%s", str);
            my[string(str)] = w;
            //my2[w] = name;
            scanf("%d", &a);
            con[w].clear();
            while(a--)
            {
                node n;
                scanf("%d %d", &n.n , &n.cost);
                con[w].push_back(n);
            }
        }
        
        scanf("%d", &t);
        while(t--)
        {
            scanf("%s %s", str, str1);
            int dist = my[string(str1)];
            dijkstra(my[string(str)], dist);
            printf("%d\n", costs[ dist ]);
        }
    }
    
    
    return 0;
}
