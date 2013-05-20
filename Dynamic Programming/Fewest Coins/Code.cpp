#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdio>


using namespace std;

int dp[10000];
int n, a;
vector<int> coins;

int solve(int t)
{
    if(dp[t] != 0)
    {
        return dp[t];
    }
    int mini = 1 << 30;
    for(int x = 0; x < n; x++)
    {
        if(t - coins[x] > 0)
            mini = min( mini, solve(t - coins[x]) );
    }
    dp[t] = mini + 1;

    return dp[t];
}

int main()
{
    memset(dp, 0, sizeof dp);
    scanf("%d", &n);
    for(int x = 0; x < n; x++)
    {
        scanf("%d", &a);
        dp[a] = 1;
        coins.push_back(a);
    }

    while(1)
    {
        scanf("%d", &a);
        if(a == -1)
            break;
        cout << solve(a) << " Coins" << endl;
    }


    return 0;
}
