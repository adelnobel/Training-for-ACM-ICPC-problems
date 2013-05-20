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

typedef struct constraint
{
    int a, b , c;
}constraint;


int ar[10];

constraint con[25];

int main()
{
    //freopen("in.in", "r", stdin);
    int n, m, a ,b;
    bool valid;
    while(1)
    {
        scanf("%d %d", &n, &m);
        if(n == 0 && m == 0) break;
        for(int x = 0; x < m; x++)
        {
            constraint s;
            scanf("%d %d %d", &s.a, &s.b, &s.c);
            con[x] = s;
        }
        
        for(int x = 0; x < n; x++)
        {
            ar[x] = x;
        }
        
        int tot = 0;
        
        do
        {
            valid = true;
            for(int x = 0; x < m && valid; x++)
            {
                for(int y = 0;y < n; y++)
                {
                    if(ar[y] == con[x].a)
                        a = y;
                    if(ar[y] == con[x].b)
                        b = y;
                }
                if(con[x].c > 0)
                {
                    if(abs(a-b) > con[x].c)
                        valid = false;
                }
                else
                {
                    if(abs(a-b) < abs(con[x].c) )
                        valid = false;
                }
            }
            if(valid) tot++;
        }while(next_permutation(ar, ar+n));
        
        
        printf("%d\n", tot);
        
    }
    return 0;
}