#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

int dp[1001][1001];
bool valid[1001][1001];

char line[4005];

/**
Counting paths in a DAG, DP!
**/

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    
    int t, r, c, y, n, cc = 1;
    scanf("%d", &t);
    
    while(t--){
        if(cc != 1){
            printf("\n");
        }
        cc++;
        scanf("%d%d", &r, &c);
        //cout << r << c << endl;
        memset(valid, true, sizeof valid);
        for(int i = 0; i < r; i++){
            line[0] = '\0';
            scanf(" %d", &n);
            gets(line);
            //cout << line << endl;
            int cur = 0, read;
            while(sscanf(line+cur, "%d%n", &y, &read) == 1){
                cur += read;
                valid[i][y-1] = false;
                dp[i][y-1] = 0;
            }
        }
        for(int i = r-1; i >= 0; i--){
            for(int j = c-1; j >= 0; j--){
                
                if(!valid[i][j]) continue;
                
                if(i == r-1 && j == c-1) {
                    dp[i][j] = 1;
                    continue;
                }
                if(j == c-1){
                    dp[i][j] = dp[i+1][j];
                    continue;
                }
                if(i == r-1){
                    dp[i][j] = dp[i][j+1];
                    continue;
                }
                dp[i][j] = dp[i+1][j] + dp[i][j+1];
            }
        }
        
        printf("%d\n", dp[0][0]);
    }
    
    
    return 0;
}

