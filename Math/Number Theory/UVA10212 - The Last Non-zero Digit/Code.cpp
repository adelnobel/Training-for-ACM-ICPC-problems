#include <cstdlib>
#include <iostream>
#include <vector>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

char s[30];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    
    int n, m;

    while(scanf("%d %d", &n, &m) == 2){
        
        if(m == 0){
            printf("%d\n", 1);
            continue;
        }
        
        int two = 0, five = 0;
        
        ll c = 2;
        while(c <= n){
            two += n / c;
            if(c <= (n-m)) two -= (n-m) / c; 
            c *= 2;
        }
        
        c = 5;
        while(c <= n){
            five += n / c;
            if(c <= (n-m)) five -= (n-m) / c; 
            c *= 5;
        }
        
        int rem = min(two, five);
        two -= rem;
        five -= rem;
        
        ll ans = 1;
        for(int i = n-m+1; i <= n; i++){
            ll mul = i;
            while(mul % 2 == 0) mul /= 2;
            while(mul % 5 == 0) mul /= 5;
            ans *= mul;
            ans %= 10;
        }
        
        for(int i = 0; i < two; i++){
            ans *= 2;
            ans %= 10;
        }
        for(int i = 0; i < five; i++){
            ans *= 5;
            ans %= 10;
        }
        
        printf("%d\n", ans);
        
    }
    
    
    return 0;
}
