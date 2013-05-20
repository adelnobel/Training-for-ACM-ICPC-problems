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

char line[1010];
int len, n;

int memo[1003][1003];

int solve(int i , int j)
{
    if(i == j){
        return 0;
    }
    if(i+1 == j){
        if(line[i] == line[j]) return 0;
        return 1;
    }
    
    if(memo[i][j] != -1){
        return memo[i][j];
    }
    
    int ret = (line[i] != line[j]) +  solve(i+1, j-1);
    ret = min(ret ,min(1 + solve(i, j-1), 1 + solve(i+1, j)));
    
    
    return memo[i][j] = ret;
    
}

int main()
{
    //freopen("in.in", "r", stdin);
    int cc = 1;
    scanf("%d", &n);
    
    while(n--){
        memset(memo, -1, sizeof memo);
        scanf("%s", line);
        len = strlen(line);
        printf("Case %d: %d\n", cc++ ,solve(0, len-1));
    }
    
    
    return 0;
}