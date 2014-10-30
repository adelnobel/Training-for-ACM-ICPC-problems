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
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>

using namespace std;

char str[3000];

int dp[1010][1010];

int LP(int i, int j)
{
    int ret;
    if(j == i+1) 
    {
        if(str[i] == str[j])
            return 2;
        return 1;
    }
    if(i == j) return 1;
    if(dp[i][j] != -1) return dp[i][j];
    if(str[i] == str[j]) ret = 2 + LP(i+1, j-1);
    else ret = max(LP(i+1, j), LP(i, j-1));
    dp[i][j] = ret;
    return ret;
}


int main()
{
    //freopen("in2.in", "r", stdin);
    int n;
    scanf("%d", &n);
    gets(str);
    while(n--)
    {
        memset(dp, -1, sizeof(dp));
        gets(str);
        
        cout << LP(0, strlen(str)-1) << endl;
    }

    return 0;
}