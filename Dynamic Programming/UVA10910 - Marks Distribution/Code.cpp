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


int dp[71][71];

int N, T, P;

int solve(int remainingPoints, int curSubject)
{
    if(remainingPoints < 0) return 0;
    if(curSubject == 0){
        if(remainingPoints >= P) return 1;
        return 0;
    }
    
    if(dp[remainingPoints][curSubject] != -1) return dp[remainingPoints][curSubject];
    
    int c = P;
    int ret = 0, ways;
    while(1){
        ways = solve(remainingPoints - c, curSubject - 1);
        if(ways == 0) break;
        c++;
        ret += ways;
    }
    
    dp[remainingPoints][curSubject] = ret;
    
    return ret;
    
}


int main()
{
    //freopen("in.in", "r", stdin);
    
    int n;
    scanf("%d", &n);
    
    while(n--)
    {
        scanf("%d %d %d", &N, &T, &P);
        memset(dp, -1, sizeof(dp));
        printf("%d\n", solve(T, N-1));
    }
    
    return 0;
}