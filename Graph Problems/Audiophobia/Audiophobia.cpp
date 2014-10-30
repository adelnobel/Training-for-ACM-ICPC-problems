
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


int c, s ,q, fi, la, co;

int d[101][101];
int p[101][101];

int main()
{
    int cou = 0;
    while(1)
    {
        cou++;
        scanf("%d %d %d", &c, &s, &q);
        if(c == 0 && s == 0 && q == 0)
            break;
        if(cou > 1)
            printf("\n");
        for(int a = 0; a <= 100; a++)
            for(int b = 0; b <= 100; b++)
                d[a][b] = 0x5FFFFFFF;
        for(int a = 0; a < s; a++)
        {
            scanf("%d %d %d", &fi, &la, &co);
            d[fi][la] = co;
            d[la][fi] = co;
            d[la][la] = 0;
            d[fi][fi] = 0;
        }
        
        for(int k = 1; k < 101; k++)
            for(int i = 1; i < 101; i++)
                for(int j = 1; j < 101; j++)
                    d[i][j] = min(d[i][j], max(d[i][k], d[k][j]));
                    
        
        printf("Case #%d\n", cou);
        for(int a = 0; a < q; a++)
        {
            scanf("%d %d", &fi, &la);
            if(d[fi][la] == 0x5FFFFFFF)
                printf("no path\n");
            else
                printf("%d\n", d[fi][la]);
        }
    }
    
    return 0;
}