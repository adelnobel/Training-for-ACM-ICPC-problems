#include <algorithm>
#include <functional>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <cstring>

using namespace std;

int t, n, s, d, p; 

typedef struct
{
    int a, b , c;
}row;

row rows[100004];

int main()
{
    int cou = 0;
    while(1)
    {
        
        scanf("%d", &n);
        if(n == 0)
            break;
        cou++;
        for(int x = 0; x < n; x++)
        {
            row r;
            scanf("%d %d %d", &r.a, &r.b, &r.c);
            rows[x] = r;
        }
        
        rows[n-1].a += rows[n-1].b; //Add value of b node to a node in the last row
        rows[n-1].c += 1 << 29; //DEAD STATE, Leads no where, COST = INFINITY to be avoided
        
        
        int minC;
        int minB;
        int minA;
        
        for(int x = n - 2; x >= 0; x--)
        {
              minC = min(rows[x+1].b, rows[x+1].c);
              rows[x].c += minC;
              minB = min(rows[x+1].b, min(rows[x+1].a, min(rows[x].c, rows[x+1].c)));
              rows[x].b += minB;
              minA = min(rows[x+1].b, min(rows[x+1].a, rows[x].b));
              rows[x].a += minA;
        }
        
        printf("%d. %d\n", cou ,rows[0].b);
        
    }
    
    return 0;
}
