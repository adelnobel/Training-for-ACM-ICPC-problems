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

/**
 After 8 wrong sumbissions! very tricky!
 * http://online-judge.uva.es/board/viewtopic.php?t=7536
 */

int dp[111][11201];

int favors[111];

int prices[111];

int n, m;

int solve(int cur, int spent)
{
    if(spent > (m + 200) ) return -1000000000; //If spendings is already more than pocket money + 200 then we are sure that this is not valid!
    if(cur < 0){ //If we reach the base
        if(spent <= m) //If spendings are less or equal to pocket money, then okay this is valid
           return 0;
        if(spent > 2000 && spent <= (m + 200) ) return 0; //If spendings are more than 2000 and less than or equal to pocket money + 200 then okay this is valid
        return -1000000000; //Else no, not valid!
    }
    if(dp[cur][spent] != -1) return dp[cur][spent];
    
    dp[cur][spent] = max( favors[cur] + solve(cur-1, spent + prices[cur]), solve(cur-1, spent)  );
    
    return dp[cur][spent];
}


int main()
{
    //freopen("in.in", "r", stdin);
    
    while(scanf("%d %d", &m, &n) != EOF)
    {
        
        memset(dp, -1, sizeof(dp));
        
        for(int i = 0; i < n; i++)
        {
            scanf("%d %d", &prices[i], &favors[i]);
        }
        
        printf("%d\n", solve(n-1, 0));
    
    }
    
    
    return 0;
}