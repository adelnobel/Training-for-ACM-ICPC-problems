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

long long n;
map<long long, long long> dp;

long long maxy(long long a , long long b)
{
    return (a > b ? a : b);
}

long long recur(long long number)
{
    if(number == 0)
          return 0;
    if(dp.count(number) > 0)
          return dp[number];
    
    long long best = maxy(number, recur(number / 3) + recur(number / 2) + recur(number / 4) );
    dp[number] = best;
    return best;
}

int main()
{
    
    while(scanf("%lld", &n) != EOF)
    {
           printf("%lld\n", recur(n));
    }    
    
    return 0;
}
