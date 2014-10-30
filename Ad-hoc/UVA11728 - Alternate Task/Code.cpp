#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <cmath>
#include <iostream>
#include <bitset>
#include <map>
#include <ctime>
#include <set>
#include <complex>

using namespace std;

typedef long long ll;

#define N 1005

int factors[N];

int best[N];


int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    int n, c = 1;
    memset(best, -1, sizeof best);
    
    
    for(int i = 1; i < N; i++){
        for(int j = 1; j <= i; j++){
            if(i % j == 0){
                factors[i] += j;
            }
        }
        if(factors[i] > 1000) continue;
        best[factors[i]] = i;
    }
    
    
    
    while(scanf("%d", &n), n){
        printf("Case %d: %d\n",c++, best[n]);
    }
    
    return 0;
}