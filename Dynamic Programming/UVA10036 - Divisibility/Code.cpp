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

char dp[10001][200];
int arr[10001];
int n, k;

bool solve(int cur, int remainder)
{
    if(cur < 0){
        if(remainder == 0) return true;
        return false;
    }
    int fixNegative = remainder;
    if(remainder < 0) fixNegative = abs(remainder) + 100; //Negative offset from 100 to 200 in dp array!
    
    if(dp[cur][fixNegative] != 'U') return dp[cur][fixNegative] == 'F' ? false : true;
    
    bool ret = solve(cur-1, (remainder + arr[cur]) % k ) || solve(cur-1, (remainder - arr[cur]) % k );
    
    dp[cur][fixNegative] = (ret) ? 'T' : 'F';
    
    return ret;
    
}


int main()
{
    //freopen("in.in", "r", stdin);
    int t;
    scanf("%d", &t);
    
    while(t--)
    {
        scanf("%d %d", &n, &k);
        for(int i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        
        memset(dp, 'U', sizeof(dp));
        
        printf( solve(n-1, 0) ? "Divisible\n" : "Not divisible\n" );
        
    }
    return 0;
}