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

/**
 I actually didn't program this problem :') but my teammate did.
I think this IS A SPOILER, so be careful to read.. =)

Try finding sums of every pair (a, b) of numbers in S, and storing them in a sorted array.
Then every pair of c and d, you can find (d-c) in the sorted array with binary search :')
That will give you O(n^2logn) and I think it's sufficient to solve the problem within the time limit.

Note: be aware that a, b, c, d must be unique.
 */

typedef struct record
{
    int a, b, sum;
    
    bool operator<(const record &r) const
    {
        return sum < r.sum;
    }
    
    bool operator>(const record &r) const
    {
        return sum > r.sum;
    }
    
    bool operator==(const record &r) const
    {
        return sum == r.sum;
    }
    
}record;

int ar[1005];

record ar2[1000000];

#define INF 2000000000

int main()
{
    //freopen("in.in", "r", stdin);
    int n;
    while(1)
    {
        scanf("%d", &n);
        if(n == 0) break;
        for(int x = 0; x < n; x++)
            scanf("%d", &ar[x]);
        
        int maxi = -INF;
        
        int c = 0;
        
        for(int x = 0; x < n; x++)
        {
            for(int y = x + 1;y < n; y++)
            {
                ar2[c].a = ar[x];
                ar2[c].b = ar[y];
                ar2[c].sum = ar[x] + ar[y];
                c++;
            }
        }
        
        sort(ar2, ar2+c);
        
        record r;
        
        int low, high;
        
        for(int x = 0; x < n; x++)
        {
            for(int y = x + 1;y < n; y++)
            {
                r.sum = ar[x] - ar[y];
                low = (int) (lower_bound(ar2, ar2+c, r) - ar2);
                high = (int) (upper_bound(ar2, ar2+c, r) - ar2);
                
                for(int a = low; a < high && ar2[a].sum == r.sum; a++)
                {
                    if( ar[x] != ar2[a].a && ar[x] != ar2[a].b && ar[y] != ar2[a].a && ar[y] != ar2[a].b )
                        maxi = max(maxi, ar2[a].sum + ar[y]);
                }
                
                r.sum = ar[y] - ar[x];
                low = (int) (lower_bound(ar2, ar2+c, r) - ar2);
                high = (int) (upper_bound(ar2, ar2+c, r) - ar2);
                
                for(int a = low; a < high && ar2[a].sum == r.sum; a++)
                {
                    if( ar[x] != ar2[a].a && ar[x] != ar2[a].b && ar[y] != ar2[a].a && ar[y] != ar2[a].b )
                        maxi = max(maxi, ar2[a].sum + ar[x]);
                }
                
            }
        }
        
        if(maxi == -INF)
            printf("no solution\n");
        else
            printf("%d\n", maxi);
        
    }
    
    return 0;
}