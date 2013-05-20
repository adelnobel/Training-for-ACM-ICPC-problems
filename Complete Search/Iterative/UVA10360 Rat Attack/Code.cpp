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

int ar[1100][1100];

int main()
{
    //freopen("in.in", "r", stdin);
    int t, n, d , x, y, c, bestC, bestX, bestY;
    
    scanf("%d", &t);
    
    while(t--)
    {
        memset(ar, 0, sizeof ar);
        scanf("%d", &d);
        scanf("%d", &n);
        
        while(n--)
        {
            scanf("%d %d %d", &x, &y, &c);
            for(int a = max(0, x - d ), to = x + d; a <= to ; a++ )
            {
                for(int b = max(0, y - d ), to2 = y + d; b <= to2 ; b++ )
                {
                    ar[a][b] += c;
                }
            }
        }
        
        bestC = -1;
        
        for(int a = 0; a <= 1024 ; a++ )
        {
            for(int b = 0; b <= 1024 ; b++ )
            {
                if(ar[a][b] > bestC)
                {
                   bestX = a; bestY = b; bestC = ar[a][b];
                }
            }
        }

        printf("%d %d %d\n", bestX, bestY, bestC);
    }
    
    return 0;
}