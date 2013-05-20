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

/**
Iterative and recursive dp!
**/

using namespace std;

int sizes[2010];
int vals[2010];

int dp[2010][2010];


int solve(int s, int cur)
{
    if(cur < 0) return 0;
    if(s <= 0) return 0;
    
    if(dp[s][cur] != -1) return dp[s][cur];
    
    int take; 
    if(s - sizes[cur] < 0)
        take = 0;
    else
        take = vals[cur] + solve( s - sizes[cur], cur - 1 );
    int leave = solve(s, cur - 1);
    
    dp[s][cur] = max( take , leave );
    
    return dp[s][cur];
    
}

int main()
{
    //freopen("in.in", "r", stdin);
    int C, N;
    
    scanf("%d %d", &C, &N);
    
    for(int x = 0; x < N; x++)
        scanf("%d %d", &sizes[x], &vals[x]);
    
    for(int i = 0; i <= C; i++ )
    {
        for(int j = 0; j < N; j++)
        {
            int takeIt;
            if(i - sizes[j] < 0)
                takeIt = 0; //If this item can't be taken because its size is larger than the current capacity!
            else if(j - 1 < 0)
                takeIt = vals[j] + 0; //if j - 1 is negative index!
            else
                takeIt = vals[j] + dp[i - sizes[j]][j - 1]; //Take it, and if you take you can't take it again!
            int leaveIt = (j == 0) ? 0 : dp[i][j - 1]; //Leave it! if you leave it then we still have the same remaining capacity and we can't take the same item again!
            dp[i][j] = max(takeIt, leaveIt );
        }
    }
    printf("%d", dp[C][N-1]);
    
    /**
    memset(dp, -1, sizeof dp);
    printf("%d", solve(C, N-1));
        **/
    return 0;
}