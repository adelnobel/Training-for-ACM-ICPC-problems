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
#include <time.h>

using namespace std;

int n, t;

int arr[200];
bool dp[60000];


int main()
{
    scanf("%d", &n);
    while(n--)
    {
        memset(arr, 0, sizeof(arr));
        memset(dp, false, sizeof(dp));
        int sum = 0;
        scanf("%d", &t);
        
        for(int x = 0; x < t;x++)
        {
            scanf("%d", &arr[x]);
            sum += arr[x];
        }
        int half = sum / 2, closestToHalf = sum / 2;
        
        dp[0] = true;
        
        for(int i = 0; i < t; i++) //For each array element
        {
            for(int j = half; j >= i; j--)
            {
                if(dp[j-arr[i]])
                {
                    dp[j] = true;
                }
            }
        }
        
        
        for(; !dp[closestToHalf] ;closestToHalf--);
        
        printf("%d\n", (sum - closestToHalf) - closestToHalf ); //(sum - closestToHalf) => Sum of the second SUBSET , closestToHalf => sum of the first subset
        
    }
     

    return 0;
}