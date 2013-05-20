#include <cstring>
#include <string>
#include <cstdio>
#include <map>
#include <set>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <iostream>
#include <algorithm>
#include <functional>
#include <cmath>

using namespace std;

typedef long long ll;

ll dp[10010][25];

#define EPS 1e-7

ll solve(int n, int cur)
{
    if(n == 0) return 1;
    if(cur <= 0) return 0;
    if(n < 0) return 0;
    if(dp[n][cur] != -1) return dp[n][cur];
    ll tot = solve(n-pow(cur, 3), cur) + solve(n, cur-1);
    dp[n][cur] = tot;
    return tot;
}

int main()
{
    //freopen("in2.in", "r", stdin);
    int x;
    memset(dp, -1, sizeof(dp));
    while(scanf("%d", &x) != EOF)
    {
        printf("%lld\n", solve(x, 21) );
    }
    return 0;
}