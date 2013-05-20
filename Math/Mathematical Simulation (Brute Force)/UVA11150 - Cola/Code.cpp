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
#include <tr1/unordered_map>

using namespace std;

int solve(int n, int remainder)
{
    if(remainder >= 3){
        n += remainder / 3;
        remainder -= (remainder / 3) * 3;
    }
    if(n < 3){
        if(n == 2){
            if(remainder == 0) return 3;
            if(remainder == 1) return 2 + solve(1, 0);
            if(remainder == 2) return 2 + solve(1, 1);
        }
        
        if(n == 1){
            if(remainder == 0) return 1;
            if(remainder == 1) return 2;
            if(remainder == 2) return 1 + solve(1, 0);
        }
    }
    
    int tillMultOf3 = n%3;
    
    return n + solve(n/3, tillMultOf3 + remainder);
    
}

int main()
{
    //freopen("in.in", "r", stdin);
    
    int n;
    
    
    while(scanf("%d", &n) != EOF){
        printf("%d\n", solve(n, 0));
    }
    
    
    return 0;
}