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
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <limits>
 
using namespace std;

int objectPrice[1001];
int objectWeight[1001];

int dp[1001][31];


int knapsack(int cur, int remaining)
{
    if(remaining < 0) return -(1 << 30);
    if(remaining == 0) return 0;
    if(cur < 0) return 0;
    
    if(dp[cur][remaining] != -1) return dp[cur][remaining];
    
    dp[cur][remaining] = max( objectPrice[cur] + knapsack(cur-1, remaining - objectWeight[cur]), knapsack(cur-1, remaining)  );
    
    return dp[cur][remaining];
    
}

int main()
{
    //freopen("in.in", "r", stdin);
    
    int t, n, g, cap;
    
    scanf("%d", &t);
    
    while(t--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d %d", &objectPrice[i], &objectWeight[i]);
        
        int tot = 0;
        memset(dp, -1, sizeof(dp));
        
        scanf("%d", &g);
        for(int i = 0; i < g; i++){
            scanf("%d", &cap);
            tot += knapsack(n-1, cap);
        }
        
        printf("%d\n", tot);
        
        
    }
    
    
    return 0;
}