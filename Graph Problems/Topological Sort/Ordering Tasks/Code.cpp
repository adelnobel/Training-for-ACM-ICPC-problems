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

int n, m, a , b;


typedef struct node
{
    int n, val;
    bool operator<(const node &no) const
    {
        return val > no.val;
    }
}node;

vector<int> adj[N];

bool marked[N];
bool present[N];
node ordering[N];

int cur_label;

void dfs(int v)
{
    marked[v] = true;
    
    for(int x = 0; x < adj[v].size(); x++)
    {
        if(!marked[adj[v][x]])
            dfs(adj[v][x]);
    }
    ordering[v].val = cur_label;
    cur_label--;
}

int main()
{
    while(1)
    {
        scanf("%d %d", &n, &m);
        if(n == 0 && m == 0)
            break;
        memset(present, false, sizeof present);
        for(int x = 0; x <= N; x++)
        {
            if(x < n)
                present[x+1] = true;
            node n;
            n.n = x;
            n.val = -1;
            ordering[x] = n;
            adj[x].clear();
        }
        for(int x = 0; x < m; x++)
        {
            scanf("%d %d", &a, &b);
            adj[b].push_back(a);
        }
        
        cur_label = N;
        memset(marked, false, sizeof marked);
        for(int x = 1; x <= n; x++)
        {
            if(!marked[x])
                dfs(x);
        }
        sort(ordering, ordering+N);
        
        int tot = 0;
        for(int x = 0; x < N; x++)
        {
            if(present[ordering[x].n])
            {
                tot++;
                if(tot != n)
                    printf("%d ", ordering[x].n);
                else
                    printf("%d", ordering[x].n);
            }
        }
        printf("\n");
        
    }
    return 0;
}