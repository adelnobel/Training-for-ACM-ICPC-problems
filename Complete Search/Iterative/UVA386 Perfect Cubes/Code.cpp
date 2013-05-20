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

#define EPS 1e-7

typedef struct item{
    
    int a, b, c, tot;
    
    bool operator<(const item &i) const
    {
        if(tot != i.tot) return tot < i.tot;
        if(a != i.a) return a < i.a;
        if(b != i.b) return b < i.b;
        return c < i.c;
    }
    
}item;

item ar[300];

int main()
{
    //freopen("in.in", "r", stdin);
    int n, cc = 1;
    
    int co = 0;
    
        int a, b, c, cA, cB, cC;
        int last = 8000000;
        
        double res;
        
        for(a = 2; a < 200; a++)
        {
            cA = pow(a, 3);
            for(b = a; b < 200; b++)
            {
                cB = pow(b, 3);
                if(cA + cB > last) break;
                for(c = b; c < 200; c++)
                {
                    cC = pow(c, 3);
                    if(cA + cB + cC > last) break;
                    res = pow(cA + cB + cC, 1.0 / 3 );
                    if( fabs( round(res) - res ) <= EPS )
                    {
                        item it;
                        it.a = a; it.b = b; it.c = c; it.tot = round(res);
                        ar[co++] = it;
                    }
                }
            }
        }
        
        sort(ar, ar+co);
        
        for(a = 0; a < co; a++)
            printf("Cube = %d, Triple = (%d,%d,%d)\n", ar[a].tot , ar[a].a , ar[a].b, ar[a].c);
        
    
   
    return 0;
}