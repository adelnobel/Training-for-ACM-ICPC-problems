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

int ar[100005];

int binarySearch(int n, int lo, int hi)
{
    int mid;
    while(lo <= hi)
    {
        mid = (lo + hi) / 2;
        if( (ar[mid] == n && mid == 0) || (ar[mid] == n && ar[mid-1] != n))
            return mid;
        if(n > ar[mid])
            lo = mid + 1;
        else
            hi = mid - 1;
    }
    return -1;
}

int main()
{
    //freopen("in.in", "r", stdin);
    
    int n, q, cc = 1, a, pos;
    
    while(1)
    {
        scanf("%d %d", &n, &q);
        if(n == 0 && q == 0) break;
        for(int x = 0; x < n; x++)
            scanf("%d", &ar[x]);
        sort(ar, ar+n);
        printf("CASE# %d:\n", cc++);
        for(int x = 0; x < q; x++)
        {
            scanf("%d", &a);
            pos = binarySearch(a, 0, n-1);
            if(pos != -1)
            {
                printf("%d found at %d\n", a, pos+1);
            }
            else
                printf("%d not found\n", a);
        }
    }
    
    return 0;
}