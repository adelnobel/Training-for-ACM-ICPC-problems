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
 IMPORTANT TIPS & GOTCHAS http://www.algorithmist.com/index.php/UVa_147
 */

int domi[] = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};

typedef long long ll;

ll dp[30005][11];

ll solve(int money, int cur)
{
    if(money == 0) return 1;
    if(cur < 0) return 0;
    if(money < 0) return 0;
    
    if(dp[money][cur] != -1) return dp[money][cur];
    
    dp[money][cur] = solve(money-domi[cur], cur) + solve(money, cur-1);
    
    return dp[money][cur];
}

char s[10];

int main()
{
    //freopen("in.in", "r", stdin);
    int am1, c;
    memset(dp, -1, sizeof(dp));
    while(1)
    {
        scanf("%s", s);
        if(strcmp(s, "0.00") == 0) break;
        am1 = c = 0;
        while(s[c] != '\0')
        {
            if(isdigit(s[c]))
                am1 = (am1 * 10) + s[c] - '0';
            c++;
        }
        
        printf("%*s",6 ,s);
        printf("%*lld\n", 17, solve(am1, 10));
    }

    return 0;
}