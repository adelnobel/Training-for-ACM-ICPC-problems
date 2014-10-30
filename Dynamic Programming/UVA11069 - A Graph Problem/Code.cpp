#include <vector>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <bitset>
#include <map>
#include <complex>
#include <ctime>
#include <numeric>
#include <set>

using namespace std;

#define MAX_N 78
int dp[78];

int n;

int solve(int cur){
    if(cur <= 1){
        return 1; 
    }
    if(dp[cur] != -1) return dp[cur];
    return dp[cur] = solve(cur - 2) + solve(cur - 3);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    
    memset(dp, -1, sizeof dp);
    
    while(scanf("%d", &n) != EOF){
        printf("%d\n" , solve(n));
    }
    
    return 0;
}

