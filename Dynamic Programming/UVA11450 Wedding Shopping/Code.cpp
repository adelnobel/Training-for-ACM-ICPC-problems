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

using namespace std;

int t, M, C, n;

int models[25][25];

int dp[210][25];

#define INF (1 << 30) * -1

int solve(int money, int mod)
{
    if(money < 0)
         return INF;
    if(mod < 0) 
    {
        return 0;
    }
    
    if(dp[money][mod] != -1) return dp[money][mod];
    
    int ans = INF;
    
    for(int x = 1; x <= models[mod][0]; x++)
    {
        ans = max(ans, models[mod][x] + solve(money - models[mod][x], mod-1 ));
    }
    
    dp[money][mod] = ans;
    
    return ans;
}

int main()
{
    //freopen("in2.in", "r", stdin);

    scanf("%d", &t);
    
    while(t--)
    {
        scanf("%d %d", &M, &C);
        memset(dp, -1, sizeof(dp));
        for(int x = 0; x < C; x++)
        {
            scanf("%d", &models[x][0]);
            for(int a = 1; a <= models[x][0]; a++)
            {
                scanf("%d", &models[x][a]);
            }
        }
        int maxi = solve(M, C-1);
        if( maxi < 0)
            printf("no solution\n");
        else
            printf("%d\n", maxi );
    }
    
}