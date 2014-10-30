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
#include <cassert>


using namespace std;

#define N 5000005


bool isComp[N];
int sum[N];
int ACC[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    
    
    for(int i = 2; i < N; i++){
        if(!isComp[i]){
            for(int j = i+i; j < N; j += i){
                isComp[j] = true;
                sum[j] += i;
            }
        }
    }
    
    for(int i = 2; i < N; i++){
        ACC[i] = ACC[i-1] + (!isComp[sum[i]]);
    }
    
    
    int a, b;
    while(scanf("%d", &a), a != 0){
        scanf("%d", &b);
        printf("%d\n", ACC[b] - ACC[a-1]);
    }
    
    
    
    
    return 0;
}
