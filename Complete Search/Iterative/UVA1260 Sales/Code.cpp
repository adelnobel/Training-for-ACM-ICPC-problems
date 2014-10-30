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

int ar[1001];

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
            scanf("%d", &ar[x]);
            for(int y = x-1; y >= 0; y--)
                if(ar[y] <= ar[x])
                    tot++;
        }
        printf("%d\n", tot);
    }
    
    
    
    return 0;
}