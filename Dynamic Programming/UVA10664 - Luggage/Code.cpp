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

char dp[21][101];

int arr[21];

char knapsack(int cur, int remaining)
{
    if(remaining == 0) return 'T';
    if(cur < 0) return 'F';
    
    if(dp[cur][remaining] != 'U') return dp[cur][remaining];
    
    char takeIt = knapsack(cur-1, remaining - arr[cur]);
    char leaveIt = knapsack(cur-1, remaining);
    
    dp[cur][remaining] = (takeIt == 'T' || leaveIt == 'T') ? 'T' : 'F';
    
    return dp[cur][remaining];
    
}

int main()
{
    //freopen("in.in", "r", stdin);
    
    int n, m, sum;
    char c;
    
    scanf("%d", &m);
    
    while(m--)
    {
        sum = 0;
        n = 0;
        while(1)
        {
            if(scanf("%d%c", &arr[n], &c) == EOF) break;
            else{
                sum += arr[n];
                n++;
            }
            if(c != ' ') break;
        }
        
        if(sum % 2){
            printf("NO\n");
            continue;
        }
        memset(dp, 'U', sizeof(dp));
        
        if(knapsack(n-1, sum/2) == 'T')
            printf("YES\n");
        else 
            printf("NO\n");
        
    }
    
    
    return 0;
}