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


pair<int, int> dp[10001][101];

bool vis[10001][101];

int arr[101];

pair<int, int> solve(int remaining, int cur)
{
    if(remaining <= 0) {
        return make_pair(-remaining, 0);
    }
    if(cur < 0) return make_pair((1 << 30), 0);
    
    if(vis[remaining][cur]) return dp[remaining][cur];
    
    vis[remaining][cur] = true;
    
    dp[remaining][cur] = solve(remaining-arr[cur], cur-1); //Take It And you can NOT take it again!
    dp[remaining][cur].second++; //We add one because we took a coin!
    pair<int, int> LeaveIt = solve(remaining, cur-1); //Leave it and you can't retake it!
    
    
    if(dp[remaining][cur].first == LeaveIt.first){
        dp[remaining][cur].second = min(dp[remaining][cur].second, LeaveIt.second);
    }
    else
    {
        if(dp[remaining][cur].first > LeaveIt.first){
            dp[remaining][cur].first = LeaveIt.first;
            dp[remaining][cur].second = LeaveIt.second;
        }
    }
    
    return dp[remaining][cur];
}

int main()
{
    //freopen("in.in", "r", stdin);
    
    int t, price, n;
    
    scanf("%d", &t);
    
    while(t--)
    {
        scanf("%d", &price);
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        
        memset(vis, false, sizeof(vis));
        
        pair<int, int> solution = solve(price, n-1);
        
        printf("%d %d\n", solution.first + price, solution.second);
        
    }
    
    return 0;
}