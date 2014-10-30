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

using namespace std;

int r, c, n, t;

char g[110][110];
char g2[110][110];

int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};

void makeMove(int x, int y, int aX, int aY)
{
    if(aX >= r || aY >= c || aX < 0 || aY < 0)
        return ;
    if(g[x][y] == 'P' && g[aX][aY] == 'R') g2[aX][aY] = 'P';
    else if (g[x][y] == 'R' && g[aX][aY] == 'S') g2[aX][aY] = 'R';
    else if (g[x][y] == 'S' && g[aX][aY] == 'P') g2[aX][aY] = 'S';
}

int main()
{
    //freopen("in2.in", "r", stdin);
    int cc = 0;
    scanf("%d", &t);
    while(t--)
    {
        cc++;
        scanf("%d %d %d", &r, &c, &n);
        for(int x = 0; x < r; x++)
            scanf("%s", g[x]);
        if(cc > 1) printf("\n");
        memcpy(g2, g, sizeof(g));
        while(n--)
        {
            for(int x = 0; x < r; x++)
            {
                for(int y = 0; y < c; y++)
                {
                    for(int a = 0; a < 4; a++)
                    {
                        makeMove(x, y, x+dx[a], y+dy[a]);
                    }
                }
            }
            memcpy(g, g2, sizeof(g));
        }
        
        for(int x = 0; x < r; x++)
            printf("%s\n", g[x]);
        
        
    }
    
    

    return 0;
}