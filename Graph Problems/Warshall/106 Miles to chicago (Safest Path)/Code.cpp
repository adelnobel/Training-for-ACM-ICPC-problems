#include <algorithm>
#include <functional>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <cstring>
#include <ctime>

using namespace std;

#define N 106

int n, m,c, a , b, t;
double dp[N][N];

int main()
{
    while(1)
    {
        scanf("%d", &n);
        if(n == 0)
            break;
        scanf("%d", &m);
        
        memset(dp, 0, sizeof dp);
        
        
        for(int x = 0; x < m; x++)
        {
            scanf("%d %d %d", &a, &b, &c);
            dp[a-1][b-1] = dp[b-1][a-1] = (c / 100.0 );
            dp[a-1][a-1] = dp[b-1][b-1] = 1;
        }
        
        for(int i = 0; i < n; i++)
            for(int k = 0; k < n; k++)
                for(int j = 0; j < n; j++)
                    dp[i][j] = max(dp[i][j], dp[i][k] * dp[k][j]);
            
        printf("%.6lf percent\n", (dp[n-1][0] * 100) );
        
    }
    
    
    return 0;
}
