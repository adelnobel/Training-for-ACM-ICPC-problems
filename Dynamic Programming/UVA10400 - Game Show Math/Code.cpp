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


string operators;

int t, p, target;

char dp[101][64002];

int arr[101];

bool solve(int cur, int val)
{
    if(val > 32000 || val < -32000) return false;
    if(cur == p) {
        if(val == target) return true;
        return false;
    }
    
    int fixNegative = val;
    if(val < 0) fixNegative = abs(val) + 32000;
    
    if(dp[cur][fixNegative] != 'U') return dp[cur][fixNegative] == 'F' ? false : true;
    
    bool ret = solve(cur+1, val + arr[cur]);
    if(ret){
        operators += '+';
    }
    
    if(!ret){
        ret = solve(cur+1, val - arr[cur]);
        if(ret){
            operators += '-';
        }
    }
    
    if(!ret){
        ret = solve(cur+1, val * arr[cur]);
        if(ret){
            operators += '*';
        }
    }
    
    if(!ret){
        if(val % arr[cur] == 0){
            ret = solve(cur+1, val / arr[cur]);
            if(ret){
                operators += '/';
            }
        }
    }
    
    dp[cur][fixNegative] = ret ? 'T' : 'F';
    
    return ret;
    
}


int main()
{
    //freopen("in.in", "r", stdin);
    int t;
    scanf("%d", &t);
    
    while(t--)
    {
        operators = "";
        scanf("%d", &p);
        
        for(int i = 0; i < p; i++)
            scanf("%d", &arr[i]);
        
        scanf("%d", &target);
        
        memset(dp, 'U', sizeof(dp));
        
        if(solve(1, arr[0])){
            printf("%d", arr[0]);
            for(int i = 1; i < p; i++){
                printf("%c%d", operators[operators.size() - i], arr[i]);
            }
            printf("=%d\n", target);
        }else{
            printf("NO EXPRESSION\n");
        }
        
    }
    
    
    return 0;
}