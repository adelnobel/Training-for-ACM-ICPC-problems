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
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

bool notValid[4][4][4][4];

char g[5][5];

typedef struct point 
{
    int x, y;
}point;

point ar[20];

int main()
{
    //freopen("in.in", "r", stdin);
    
    int n;
    
    while(1)
    {
        scanf("%d", &n);
        if(n == 0) break;
        
        for(int x = 0; x < n; x++)
        {
            scanf("%s", g[x]);
        }
        
        memset(notValid, false, sizeof(notValid));

        for(int x = 0; x < n; x++)
        {
            for(int a = 0; a < n; a++) //For rows!
            {
                if(g[x][a] == 'X') continue;
                for(int b = a + 1; b < n; b++)
                {
                    if(g[x][b] == 'X') break;
                    notValid[x][a][x][b] = notValid[x][b][x][a] = true;
                }
            }
            
            for(int a = 0; a < n; a++) //For columns!
            {
                if(g[a][x] == 'X') continue;
                for(int b = a + 1; b < n; b++)
                {
                    if(g[b][x] == 'X') break;
                    notValid[a][x][b][x] = notValid[b][x][a][x] = true;
                }
            }
        }
        
        int to = (1 << (n*n) ), tot, maxi = 0;
        bool valid;
        
        for(int x = 0; x < to; x++)
        {
            tot = 0, valid = true;
            for(int a = 0, nXn = n*n; a < nXn && valid ; a++)
            {
                if(x & (1 << a) )
                {
                    ar[tot].y = a / n;
                    ar[tot].x = a % n;
                    if(g[ar[tot].x][ar[tot].y] == 'X') valid = false;
                    for(int i = tot-1; i >= 0 && valid; i--)
                        if(notValid[ar[tot].x][ar[tot].y][ar[i].x][ar[i].y])
                            valid = false;
                    tot++;
                }
            }
            if(valid)
                maxi = max(maxi, tot);
        }
        
        printf("%d\n", maxi);
        
    }
    
    
    return 0;
}