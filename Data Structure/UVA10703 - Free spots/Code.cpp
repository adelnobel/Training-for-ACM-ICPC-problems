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
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <limits>
#include <tr1/unordered_map>
 
using namespace std;

bool grid[501][501];

int main()
{
    //freopen("in.in", "r", stdin);
    int w, h, n, x1, x2, y1, y2;
    
    while(1)
    {
        scanf("%d %d %d", &w, &h, &n);
        memset(grid, false, sizeof grid);
        
        if(w == 0 && h == 0 && n == 0) break;
        
        for(int i = 0; i < n; i++){
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            for(int x = min(x1, x2), to = max(x1, x2); x <= to; x++){
                for(int y = min(y1, y2), to2 = max(y1, y2); y <= to2; y++){
                    grid[x][y] = true;
                }
            }
        }
        
        int tot = 0;
        
        for(int x = 1; x <= w; x++){
            for(int y = 1; y <= h; y++){
                tot += !grid[x][y];
            }
        }
        
        if(tot == 0)
            printf("There is no empty spots.\n");
        else if(tot == 1)
            printf("There is one empty spot.\n");
        else
            printf("There are %d empty spots.\n", tot);
        
    }
    

    return 0;
}