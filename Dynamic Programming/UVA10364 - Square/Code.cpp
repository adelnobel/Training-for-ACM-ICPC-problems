#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

char dp[4][1<<20];
int sum = 0, sideLength, n, t, arr[21];

bool solve(int side, int mask){
    if(side < 0){
        if(mask == ((1<<n) - 1)) return true;
        return false;
    }
    if(dp[side][mask] != 'N') return dp[side][mask] == 'T';
    bool ret = false;
    int tot = 0;
    for(int i = 0; i < n; i++){
        if((1<<i) & mask) tot += arr[i];
    }
    
    for(int i = 0; i < n && !ret; i++){
        if(!((1<<i) & mask)){
            if(tot + arr[i] == ((4-side) * sideLength)){
                ret |= solve(side-1, mask|(1<<i));
            }else if(tot + arr[i] < ((4-side) * sideLength)){
                ret |= solve(side, mask|(1<<i));
            }
        }
    }
    
    dp[side][mask] = (ret ? 'T' : 'F');
    return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    
    scanf("%d", &t);
    
    while(t--){
        memset(dp, 'N', sizeof dp);
        sum = 0;
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            scanf("%d", &arr[i]);
            sum += arr[i];
        }
        
        if(sum % 4 != 0) {
            printf("no\n");
            continue;
        }
        
        sideLength = sum / 4;
        printf(solve(3, 0) ? "yes\n" : "no\n");
        
    }
    
    
    return 0;
}

