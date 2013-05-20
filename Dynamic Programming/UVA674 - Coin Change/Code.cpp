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

int domi[] = {1, 5, 10, 25, 50};

typedef long long ll;

ll dp[5][7495];

ll solve(int cur, int money)
{
    if(money == 0) return 1;
    if(money < 0) return 0;
    if(cur < 0) return 0;
    
    if(dp[cur][money] != -1) {
        return dp[cur][money];
    }
    dp[cur][money] = solve(cur, money - domi[cur]) + solve(cur-1, money);
    
    return dp[cur][money];
}

ll ans[7495];


int main()
{
    //freopen("in.in", "r", stdin);
    memset(dp, -1, sizeof(dp));
    for(int x = 0; x <= 7489; x++)
    {
        ans[x] = solve(4, x);
    }
    
    int n;
    
    while(scanf("%d", &n) != EOF)
    {
        ll ret;
        if(n < 0) ret = 0;
        else ret = ans[n];
        printf("%lld\n", ret);
    }
    
    return 0;
}