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
#include <set>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    
    unsigned int n;
    
    while(scanf("%u", &n), n){
        
        int to = sqrt(n) + 1;
        int total = 1, curPrimeCount = 0;
        
        for(int i = 2; i <= to; i++){
            while(n % i == 0){
                curPrimeCount++;
                n /= i;
                to = sqrt(n) + 1;
            }
            total *= (curPrimeCount + 1);
            curPrimeCount = 0;
        }
        if(n > 1) total *= 2;
        
        if(total & 1){
            printf("yes\n");
        }else{
            printf("no\n");
        }
        
    }
    
    return 0;
}