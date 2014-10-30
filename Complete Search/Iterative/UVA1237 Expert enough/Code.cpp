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

typedef struct manuf
{
    char name[22];
    int l, h;
}manuf;

manuf ar[10001];

int main()
{
    //freopen("in.in", "r", stdin);
    
    int t, n, q, cc = 1, p;
    scanf("%d", &t);
    
    while(t--)
    {
        if(cc > 1) printf("\n");
        cc++;
        scanf("%d", &n);
        for(int x = 0; x < n; x++)
        {
            manuf m;
            scanf("%s %d %d", m.name, &m.l, &m.h);
            ar[x] = m;
        }
        
        scanf("%d", &q);
        
        while(q--)
        {
            int best, tot = 0;
            scanf("%d", &p);
            for(int x = 0; x < n; x++)
            {
                if(p >= ar[x].l && p <= ar[x].h)
                {
                    best = x;
                    tot++;
                    if(tot == 2) break;
                }
            }
            if(tot == 1) printf("%s\n", ar[best].name);
            else printf("UNDETERMINED\n");
        }
        
        
        
    }
    
    
    
    return 0;
}