#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

int groups[9][9][9];

int memo[1<<9][3];

int solve(int mask, int level){
    if(level < 0) return 0;
    if(memo[mask][level] != -1) return memo[mask][level];
    int ret = -10;
    
    int arr[3];
    
    for(int i = 0; i < 9; i++){
        for(int j = i+1; j < 9; j++){
            for(int k = j+1; k < 9; k++){
                if( (mask & (1 << i)) || (mask & (1 << j)) || (mask & (1 << k))) continue;
                arr[0] = i, arr[1] = j, arr[2] = k;
                sort(arr, arr+3);
                if(groups[arr[0]][arr[1]][arr[2]] != -1){
                    int val = solve(mask | (1 << i) | (1 << j) | (1 << k), level - 1);
                    if(val != -10){
                        ret = max(ret, groups[arr[0]][arr[1]][arr[2]] + val);
                    }
                }
            }
        }
    }
    
    return memo[mask][level] = ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    
    int n, s, cc = 1, arr[3];
    
    
    while(scanf("%d", &n), n){
        memset(groups, -1, sizeof groups);
        memset(memo, -1, sizeof memo);
        for(int i = 0; i < n; i++){
            scanf("%d %d %d %d", &arr[0], &arr[1], &arr[2], &s);
            arr[0]--, arr[1]--, arr[2]--;
            sort(arr, arr+3);
            groups[arr[0]][arr[1]][arr[2]] = s;
        }
        
        int ret = solve(0, 2);
        
        printf("Case %d: ", cc++);
        
        if(ret == -10){
            printf("-1\n");
        }else{
            printf("%d\n", ret);
        }
    }
    
    
    return 0;
}

