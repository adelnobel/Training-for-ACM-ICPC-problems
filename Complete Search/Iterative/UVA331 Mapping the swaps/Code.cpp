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
int n;

typedef struct state
{
    int v[6];
    int cost;
    bool operator==(const state &s) const
    {
        for(int x = 0; x < n; x++)
            if(s.v[x] != v[x]) return false;
        return true;
    }
}state;

int best[30];

int ar[6];

int main()
{
    //freopen("in.in", "r", stdin);
    
    int cc = 1;
    
    while(1)
    {
        scanf("%d", &n);
        if(n == 0) break;
        memset(best, 0, sizeof(best));
        for(int x = 0; x < n; x++)
        {
            scanf("%d", &ar[x]);
        }
        
        queue< state > q;
        state s;
        memcpy(s.v, ar, sizeof(ar));
        s.cost = 0;
        q.push(s);
        
        
        state goal;
        memcpy(goal.v, ar, sizeof(ar));
        sort(goal.v, goal.v+n);
        
        bool inputIsAlreadySorted = true;
        
        int mini = 2000000;
        
            while(!q.empty())
            {
                state cur = q.front(); q.pop();
                if(cur == goal) 
                {
                    mini = min(mini, cur.cost);
                    if(!inputIsAlreadySorted)best[cur.cost]++;
                    continue;
                }
                inputIsAlreadySorted = false;

                if(cur.cost >= mini) continue;

                for(int x = 0; x < n - 1; x++)
                {
                    state ss;
                    memcpy(ss.v, cur.v, sizeof(cur.v));
                    int temp = ss.v[x];
                    ss.v[x] = ss.v[x+1];
                    ss.v[x+1] = temp;
                    ss.cost = cur.cost + 1;
                    q.push(ss);
                }
            }
        
        printf("There are %d swap maps for input data set %d.\n", best[mini], cc++);
        
    }
    
    
   
    return 0;
}