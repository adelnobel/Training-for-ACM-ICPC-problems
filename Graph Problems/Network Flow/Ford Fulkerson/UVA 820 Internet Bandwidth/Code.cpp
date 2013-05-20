#include <cstring>
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

using namespace std;

#define N 102

int caps[N][N];

int prevs[N];

bool marked[N];

int a, b, c, n, l;

int pushFlow(int s, int t)
{
    memset(marked, false, sizeof marked);
    int flow = 0;
    queue<int> q;
    q.push(s);
    marked[s] = true;
    bool found = false;
    prevs[s] = -1;
    int mini = 1 << 30;
    while(!q.empty())
    {
        int cur = q.front(); q.pop();
        if(cur == t)
        {
            found = true;
            break;
        }
        for(int x = 0; x < n; x++)
        {
            if(!marked[x] && caps[cur][x] > 0)
            {
                marked[x] = true;
                prevs[x] = cur;
                q.push(x);
            }
        }
    }
    
    if(!found) return 0;
    else
    {
        int from = prevs[t], where = t;
        while(from != -1)
        {
            mini = min(mini, caps[from][where]);
            where = from;
            from = prevs[from];
        }
        flow = mini;
        
        from = prevs[t], where = t;
        while(from != -1)
        {
            caps[from][where] -= flow;
            caps[where][from] += flow;
            where = from;
            from = prevs[from];
        }
    }
    return flow;
}


int fulkerson(int s, int t)
{
    int maxFlow = 0;
    int curFlow;
    
    while(1)
    {
        curFlow = pushFlow(s, t);
        if(curFlow == 0) break;
        maxFlow += curFlow;
    }
    
    
    return maxFlow;
}



int main() 
{
    //freopen("in2.in", "r", stdin);
    int s, t;
    int cou = 0;
    while(1)
    {
        cou++;
        memset(caps, 0, sizeof caps);
        scanf("%d", &n);
        if(n == 0) break;
        scanf("%d %d %d", &s, &t, &l);
        while(l--)
        {
            scanf("%d %d %d", &a, &b, &c);
            caps[a-1][b-1] += c;
            caps[b-1][a-1] += c;
        }

        cout << "Network " << cou << endl << "The bandwidth is " << fulkerson(s-1, t-1) << "." << endl << endl;
    }
    
    return 0;
}