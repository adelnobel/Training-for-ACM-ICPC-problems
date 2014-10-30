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

int memo[1002][1002];

int solve(int n, int m)
{
    if(m == 0 || n == m) return 1;
    
    if(memo[n][m] != -1) return memo[n][m];
    
    return memo[n][m] = solve(n-1, m) + solve(n-1, m-1);
    
}

int main()
{
    //freopen("in.in", "r", stdin);
    
    memset(memo, -1, sizeof memo);
    int n, m;
    
    while(1){
        scanf("%d %d", &n, &m);
        if(n == 0 && m == 0) break;
        
        
        
        printf("%d things taken %d at a time is %d exactly.\n", n, m, solve(n, m));
    }
    
    return 0;
}