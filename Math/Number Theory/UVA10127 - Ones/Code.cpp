#include <vector>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <bitset>
#include <map>
#include <complex>
#include <ctime>
#include <numeric>

using namespace std;

typedef long long ll;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    
    int n;
    
    while(scanf("%d", &n) != EOF){
        int count = 1;
        int cur = 1;
        while(cur % n != 0){
            cur = ((cur % n) * (10 % n) + (1 % n))  % n;
            count++;
        }
        
        printf("%d\n", count);
    }
    
    return 0;
}