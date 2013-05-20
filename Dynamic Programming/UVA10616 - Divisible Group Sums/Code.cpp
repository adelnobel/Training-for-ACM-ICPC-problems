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

long long dp[42][201][11];

int arr[201];

int n, q, d, m;

long long solve(int modedNumber, int curElement, int remaining)
{
    if(remaining == 0) {
        if(modedNumber == 0) return 1;
        return 0;
    }
    if(curElement < 0) return 0;
    
    int fixNegative = modedNumber;
    if(modedNumber < 0) fixNegative = abs(modedNumber) + 20; //To avoid negative indices, we make the dp[42] (that's two times larger than 20) to allow negative values, and for each negative value, we make its index = abs(modedNumber) + 20, so we make sure that they will have their own distinct indices and no collisions will happen!
    
    if(dp[fixNegative][curElement][remaining] != -1) return dp[fixNegative][curElement][remaining];
    
    long long takeIt = solve( (modedNumber + arr[curElement]) % d, curElement - 1, remaining - 1 );
    
    long long leaveIt = solve( modedNumber, curElement - 1, remaining );
    
    dp[fixNegative][curElement][remaining] = takeIt + leaveIt;
    
    return dp[fixNegative][curElement][remaining];
    
}

int main()
{
    //freopen("in.in", "r", stdin);
    
    int cc = 1;
    
    while(1)
    {
        
        scanf("%d %d", &n, &q);
        if(n == 0 && q == 0) break;
        
        for(int i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        
        printf("SET %d:\n", cc++);
        
        for(int i = 0; i < q; i++){
            scanf("%d %d", &d, &m);
            memset(dp, -1, sizeof(dp));
            printf("QUERY %d: %lld\n", i+1, solve(0, n-1, m));
        }
        
        
    }
    return 0;
}