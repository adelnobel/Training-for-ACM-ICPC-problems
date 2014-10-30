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

/**
Bitmasking!
**/

using namespace std;

int ar[20];

int main()
{
    //freopen("in.in", "r", stdin);
    
    int n, cc = 0;
    
    while(1)
    {
        scanf("%d", &n);
        vector< vector<int> > vv;
        if(n == 0) break;
        if(cc > 0) printf("\n");
        cc++;
        for(int x = 0; x < n; x++)
            scanf("%d", &ar[x]);
        int to = 1 << n;
        
        for(int x = 0; x < to; x++)
        {
            int tot = 0;
            for(int a = 0; a < n; a++)
            {
                if( (1 << a) & x ) tot++;
            }
            if(tot == 6)
            {
                vector<int> v(6);
                int c = 0;
                for(int a = 0; a < n; a++)
                {
                    if( (1 << a) & x )
                    {
                        
                        v[c++] = ar[a];
                    }
                }
                vv.push_back(v);
            }
        }
        
        sort(vv.begin(), vv.end());
        for(int x = 0; x < vv.size(); x++)
        {
            printf("%d", vv[x][0]);
            for(int y = 1; y < 6; y++)
            {
                printf(" %d", vv[x][y]);
            }
            printf("\n");
        }
    }
    
    
    return 0;
}