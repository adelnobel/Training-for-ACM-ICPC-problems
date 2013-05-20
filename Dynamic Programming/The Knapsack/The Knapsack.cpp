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

typedef struct 
{
    int size, val;
}item;

int n, s, a , b;

item arr[3000];
int dp[60000];

int main()
{
    
    scanf("%d %d", &s, &n);
    for(int x = 0; x < 60000; x++)
        dp[x] = -1;
    
    
    for(int x = 0; x < n; x++)
    {
        scanf("%d %d", &a, &b);
        item i;
        i.size = a;
        i.val = b;
        arr[x] = i;
    }
    
    dp[0] = 0; //Initialize state of 0 to value of 0
    int maxi = 0;
    
    for(int i = 0; i < n; i++ ) //For each item
    {
        int value = arr[i].val;
        int size = arr[i].size;
        for(int j = s; j >= size; j--) //Let j = the capacity of the knapsack; and loop until j = the size of the current element
        {
            if( dp[ j - size ] != -1 && value + dp[ j - size ] > dp[j]  )
            { //dp[ j - size ] != -1 => Means, if we ever reached the state if j-size with any cost,
                //then, if the cost of that state + the value of the current item is GREATER than the cost of the state of j,
                dp[j] = value + dp[ j - size ];//Then update the state j with the new BETTER value!
                maxi = max(maxi, dp[j]);//This is a variable to keep track of the current MAXIMUM value
                
                //Note: if we cannot extend from any state; we can always extend from state 0 as its already initialized with cose = 0
                //Meaning that j will j will be equal to size and dp [j - size] = dp[0] and j will be equal to the size of the current element
            }
        }
    }
    
    printf("%d\n", maxi);

    return 0;
}