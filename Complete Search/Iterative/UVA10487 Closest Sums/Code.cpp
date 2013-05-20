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

int a[1003];

int main()
{
    //freopen("in.in", "r", stdin);
    
    int n, m, p, cc = 1;
    
    while(1)
    {
        scanf("%d", &n);
        if(n == 0) break;
        for(int x = 0; x < n; x++)
            scanf("%d", &a[x]);
        scanf("%d", &m);
        printf("Case %d:\n", cc++);
        for(int y = 0; y < m; y++)
        {
            int bestDiff = 1000000000, bestSum;
            scanf("%d", &p);
            
            for(int x = 0; x < n; x++)
            {
                for(int z = x + 1; z < n; z++ )
                {
                    if( abs( (a[x] + a[z]) - p ) < bestDiff )
                    {
                        bestDiff = abs( (a[x] + a[z]) - p );
                        bestSum = a[x] + a[z];
                    }
                }
            }
            printf("Closest sum to %d is %d.\n", p, bestSum);
        }
    }
    
    return 0;
}