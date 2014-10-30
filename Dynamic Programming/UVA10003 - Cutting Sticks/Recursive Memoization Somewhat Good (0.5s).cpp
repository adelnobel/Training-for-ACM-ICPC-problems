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
        if(cuts[x] >= right) break; //If the current cut is larger than the right then we can't find any feasible cut in the rest of the loop! (Bescause its sorted! according to input constraints)
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
    
    while(1)
    {
        scanf("%d", &l);
        if(l == 0) break;
        

        scanf("%d", &c);
        cuts[0] = 0; 
        for(int i = 1; i <= c; i++)
            scanf("%d", &cuts[i]);
        cuts[++c] = l;
        
        for(int x = 0; x <= c; x++){
            for(int y = x + 1; y <= c; y++){
                dp[cuts[x]][cuts[y]] = dp[cuts[y]][cuts[x]] = -1;
            }
        }
        
        printf("The minimum cutting is %d.\n", solve(0, l));
        
        
    }
    
    return 0;
}