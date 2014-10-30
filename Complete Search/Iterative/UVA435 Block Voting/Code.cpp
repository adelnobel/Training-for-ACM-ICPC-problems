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

typedef struct party
{
    int index, power, members;
};

party ar[25];

int main()
{
    //freopen("in.in", "r", stdin);
    
    int t, n;
    
    scanf("%d", &t);
    
    while(t--)
    {
        scanf("%d", &n);
        int tot = 0;
        for(int x = 0; x < n; x++)
        {
            party p;
            scanf("%d", &p.members);
            p.index = x;
            p.power = 0;
            ar[x] = p;
            tot += p.members;
        }
        
        
        int to = (1 << n) - 1;
        
        for(int mask = 0; mask <= to; mask++)
        {
            int subsetPower = 0;
            for(int a = 0; a < n; a++)
            {
                if( (1 << a) & mask )
                {
                    subsetPower += ar[a].members;
                }
            }
            for(int a = 0; a < n; a++)
            {
                if( (1 << a) & mask )
                {
                    if( subsetPower - ar[a].members <= (tot*1.) / 2 && subsetPower > (tot*1.) / 2 )
                        ar[a].power++;
                }
            }
        }
        
        for(int x = 1; x <= n; x++)
            printf("party %d has power index %d\n", x, ar[x-1].power );
        
        printf("\n");
        
    }
    
    
    return 0;
}