#include <stdio.h>
#include <cctype>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <functional>
#include <stack>
#include <iostream>
#include <queue>

using namespace std;


int n, r, k, i , j, q, w, c;

int d[101][101];
int p[101][101];

int main()
{
    int cou = 0;
    while(1)
    {
        cou++;
        //memset(d, 0x5FFFFFF, sizeof(d));
        for(int a = 0; a < 100; a++)
            for(int b = 0; b < 100;b++)
                d[a][b] = 0;
        
        scanf("%d %d", &n, &r);
        if(n == 0 && r == 0)
            break;
        
        for(int x = 0; x < r; x++)
        {
            scanf("%d %d %d", &q, &w, &c );
            d[q-1][w-1] = c;
            d[w-1][q-1] = c;
        }
        for (k=0; k < n; k++)
            for (i=0; i < n; i++)
                for (j=0; j < n; j++)
                    d[i][j] = max(d[i][j], min(d[i][k], d[k][j]));
        
        scanf("%d %d %d", &q, &w, &c);
        printf("Scenario #%d\n", cou);
        printf("Minimum Number of Trips = %.0lf\n\n", ceil( c / (double)(d[q-1][w-1] - 1) ) );
        
        
    }
    return 0;
}