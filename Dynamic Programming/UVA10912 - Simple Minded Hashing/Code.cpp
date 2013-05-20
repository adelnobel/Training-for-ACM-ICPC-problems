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


int dp[27][10001][27];

int solve(int startAlpha, int remainingPoints, int remainingLength)
{
    if(remainingLength < 0){
        if(remainingPoints == 0) return 1;
        return 0;
    }
    if(startAlpha > 26) return 0;
    
    if(dp[startAlpha][remainingPoints][remainingLength] != -1) return dp[startAlpha][remainingPoints][remainingLength];
    
    int ret = 0, ways, c = 0;
    
    while(startAlpha + c <= 26 ){
        ways = solve(startAlpha + c + 1, remainingPoints - (startAlpha + c), remainingLength - 1 );
        c++;
        ret += ways;
    }
    
    dp[startAlpha][remainingPoints][remainingLength] = ret;
    
    return ret;
}


int main()
{
    //freopen("in.in", "r", stdin);
    
    int L, S, cc = 1;
    memset(dp, -1, sizeof(dp));
    
    while(1)
    {
        
        scanf("%d %d", &L, &S);
        if(L == 0 && S == 0) break;
        
        printf("Case %d: ", cc++);
        if(L > 26) printf("0\n"); //Observation, since its in STRICTLY ascending order, we need not consider strings of lengths more than 26! also, the input constraints are tricky since L <= 10000
        else{
            printf("%d\n", solve(1, S, L-1));
        }
        
    }
    
    return 0;
}