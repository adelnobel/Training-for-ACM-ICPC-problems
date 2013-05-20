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
#include <tr1/unordered_map>

using namespace std;

typedef long long ll;

char s[6005];

int dp[6005][6005];

int len;

int solve(int left, int right)
{
    if(left == right){
        return 0;
    }
    if(left+1 == right){
        if(s[left] == s[right]) return 0;
        return 1;
    }
    
    if(dp[left][right] != -1) return dp[left][right];
    
    
    if(s[left] == s[right]){
        dp[left][right] = solve(left+1, right-1);
    }else{
        dp[left][right] = 1 + min(solve(left, right-1), solve(left+1, right));
    }
    
    return dp[left][right];
}


void solve()
{
    for(int left = len-1; left >= 0; left--){
        for(int right = left; right < len; right++){
            
            if(left > right) continue;
            
            if(left == right){
                dp[left][right] = 0;
                continue;
            }
            if(left+1 == right){
                if(s[left] == s[right]) dp[left][right] = 0;
                else dp[left][right] = 1;
                continue;
            }
            
            if(s[left] == s[right]){
                dp[left][right] = dp[left+1][right-1];
            }else{
                dp[left][right] = 1 + min(dp[left][right-1], dp[left+1][right]);
            }
       }
    }
}


int main()
{
    //freopen("in.in", "r", stdin);
    
    int t, prevLn = 0;
    
    //memset(dp, -1, sizeof dp);
    
    scanf("%d", &t);
    
    while(t--){
        scanf("%s", s);
        /**
        for(int i = 0; i <= prevLn; i++)
            for(int j = 0; j <= prevLn; j++)
                dp[i][j] = -1;**/
        
        len = strlen(s);
        prevLn = len;
        
        solve();
        
        printf("%d\n", dp[0][len-1]);
    }
    
    return 0;
}
