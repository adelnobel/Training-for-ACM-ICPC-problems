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


int arr[100001];

int dp[100001];

int main()
{
    //freopen("in.in", "r", stdin);
    
    int cc = 1, i, best, maxi;
    
    while(1)
    {
        scanf("%d", &arr[0]);
        if(arr[0] == -1) break;
        i = 1;
        if(cc > 1) printf("\n");
        while(1)
        {
            scanf("%d", &arr[i]);
            if(arr[i] == -1) break;
            i++;
        }
        for(int j = 0;j < i; j++)
            dp[j] = 0;
        
        maxi = 0;
        
        for(int x = 0; x < i; x++){
            best = 0;
            for(int y = x-1; y >= 0; y--){
                if(arr[y] > arr[x])
                    best = max(best, dp[y]);
            }
            dp[x] = best + 1;
            maxi = max(maxi, dp[x]);
        }
        
        printf("Test #%d:\n", cc++);
        printf("  maximum possible interceptions: %d\n", maxi);
    }
    
    
    return 0;
}