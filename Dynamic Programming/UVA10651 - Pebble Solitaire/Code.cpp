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

/**
DP with Bitmask
**/

short popCnt[1 << 12];
int memo[1 << 12];

char line[20];

int solve(int mask){
    if(popCnt[mask] <= 1){
        return popCnt[mask];
    }
    
    if(memo[mask] != -1) return memo[mask];
    
    int mini = popCnt[mask];
    
    for(int i = 0; i < 10; i++){
        if(!(mask&(1<<i)) && (mask&(1<<(i+1))) && (mask&(1<<(i+2)))){
            int newMask = mask|(1<<i);
            newMask &= ~(1<<(i+1));
            newMask &= ~(1<<(i+2));
            mini = min(mini, solve(newMask));
        }
        if((mask&(1<<i)) && (mask&(1<<(i+1))) && !(mask&(1<<(i+2)))){
            int newMask = mask|(1<<(i+2));
            newMask &= ~(1<<(i+1));
            newMask &= ~(1<<(i));
            mini = min(mini, solve(newMask));
        }
    }
    
    return memo[mask] = mini;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    
    for(int i = 1, to = 1 << 12; i < to; i++){
        popCnt[i] = __builtin_popcount(i);
    }
    
    memset(memo, -1, sizeof memo);
    int t;
    scanf("%d", &t);
    
    while(t--){
        scanf("%s", line);
        int c = 0, mask = 0;
        
        while(line[c]){
            mask |= ((line[c] == 'o') << c);
            c++;
        }
        printf("%d\n", solve(mask));
    }
    

    return 0;
}