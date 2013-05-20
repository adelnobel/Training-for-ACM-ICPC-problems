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

int ar[10010];
int dp[10010];

int main()
{
    //freopen("in.in", "r", stdin);
    
    int n, maxi;
    while(1)
    {
        scanf("%d", &n);
        if(n == 0) break;
        scanf("%d", &ar[0]);
        dp[0] = max(0, ar[0]);
        maxi = dp[0];
        for(int x = 1; x < n; x++)
        {
            scanf("%d", &ar[x]);
            dp[x] = max(dp[x-1] + ar[x], 0);
            maxi = max(dp[x], maxi);
        }
        
        if(maxi == 0)
            printf("Losing streak.\n");
        else
            printf("The maximum winning streak is %d.\n", maxi);
        
    }
    
    return 0;
}