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

bool trToRest[25][25];
bool restToHot[25][25];
bool hotToTrav[25][25];

int tr[25], rest[25], hotels[25];

int main()
{
    //freopen("in.in", "r", stdin);
    
    int t, r, h;
    
    while(scanf("%d %d %d", &t, &r, &h) != EOF)
    {
        for(int x = 0; x < t; x++)
        {
             scanf("%d", &tr[x]);
             for(int a = 0; a < r; a++)
                 scanf("%d", &trToRest[x][a]), trToRest[x][a] ^= 1;
        }
        for(int x = 0; x < r; x++)
        {
             scanf("%d", &rest[x]);
             for(int a = 0; a < h; a++)
                 scanf("%d", &restToHot[x][a]), restToHot[x][a] ^= 1;
        }
        for(int x = 0; x < h; x++)
        {
             scanf("%d", &hotels[x]);
             for(int a = 0; a < t; a++)
                 scanf("%d", &hotToTrav[x][a]), hotToTrav[x][a] ^= 1;
        }
        
        int mini = 2000000000;
        int bestTr = -1, bestRes= -1, bestHot = -1;
        
        for(int a = 0; a < t; a++)
        {
            for(int b = 0; b < r; b++)
            {
                if(!trToRest[a][b]) continue;
                for(int c = 0; c < h; c++)
                {
                    if(!restToHot[b][c] || !hotToTrav[c][a]) continue;
                    if(tr[a] + rest[b] + hotels[c] < mini)
                    {
                        mini = tr[a] + rest[b] + hotels[c];
                        bestTr = a; bestRes = b; bestHot = c;
                    }
                }
            }
        }
        
        if(bestTr == -1)
        {
            printf("Don't get married!\n");
        }
        else
        {
            printf("%d %d %d:%d\n", bestTr, bestRes, bestHot, mini);
        }
        
    }
    
    
    return 0;
}