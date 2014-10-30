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

int cuts[60];
int l, c;

int dp[1001][1001];


int solve(int left, int right)
{
    if(dp[left][right] != -1) {
        return dp[left][right];
    }
    bool canBeCut = false;
    int ret;
    
    for(int x = 0; x < c; x++){
        if(cuts[x] > left && cuts[x] < right){
            if(!canBeCut){
                canBeCut = true;
                ret = solve(left, cuts[x]) + solve(cuts[x], right) + (right - left);
            }
            else{
                int cost = solve(left, cuts[x]) + solve(cuts[x], right) + (right - left);
                if(cost < ret){
                    ret = cost;
                }
            }
        }
    }
    
    if(!canBeCut) ret = 0;
    dp[left][right] = ret;
    return ret;
}

int main()
{
    //freopen("in.in", "r", stdin);
    int prevL = 1001;
    while(1)
    {
        scanf("%d", &l);
        if(l == 0) break;
        
        for(int i = 0; i < prevL; i++){
            for(int j = 0; j < prevL; j++){
                dp[i][j] = -1;
            }
        }
        prevL = l+1;
        scanf("%d", &c);
        for(int i = 0; i < c; i++)
            scanf("%d", &cuts[i]);
        printf("The minimum cutting is %d.\n", solve(0, l));
        
        
        
    }
    
    return 0;
}