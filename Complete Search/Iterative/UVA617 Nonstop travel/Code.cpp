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

typedef struct signal
{
    int g, y, r;
    double l;
}signal;

signal signals[10];

bool validS[70];

int main()
{
    //freopen("in.in", "r", stdin);
    
    int n, cc = 1;
    
    while(1)
    {
        scanf("%d", &n);
        if(n == -1) break;
        memset(validS, false, sizeof(validS));
        for(int x = 0; x < n; x++)
        {
            signal s;
            scanf("%lf %d %d %d", &s.l, &s.g, &s.y, &s.r);
            signals[x] = s;
        }
        
        int tot = 0, lastAccepted;
        
        for(int x = 30; x <= 60; x++)
        {
            double mps = x*1. / (60*60);
            bool valid = true;
            for(int a = 0; a < n && valid; a++)
            {
                double reachAtSecond = signals[a].l / mps;
                int lastRed = (int)( (reachAtSecond) / (signals[a].g + signals[a].y + signals[a].r) ) * (signals[a].g + signals[a].y + signals[a].r);
                if( !(reachAtSecond <= signals[a].g + signals[a].y + lastRed ) )  valid = false;
            }
            if(valid) {
                validS[x] = true;
                lastAccepted = x;
                tot++;
            }
        }
        
        int start, end;
        int x;
        
        bool flag = true;
        
        printf("Case %d: ", cc++);
        
        if(tot == 0)
            printf("No acceptable speeds.");
        else if(tot == 1)
            printf("%d", lastAccepted);
        else
        for(x = 30; x <= 60;)
        {
            if(validS[x]) {
               start = x;
               for(x = x; x <= 60 && validS[x]; x++);
               end = x-1;
               if(!flag)
               {
                   printf(", ");
               }
               if(start == end)
                   printf("%d", start);
               else
                   printf("%d-%d", start, end);
               flag = false;
            }
            else
            {
                x++;
            }
        }
        
        printf("\n");
        
    }
    
    
    return 0;
}