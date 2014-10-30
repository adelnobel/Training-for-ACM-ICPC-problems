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
#include <vector>
#include <algorithm>

using namespace std;

#define N 100005

int arr[N], acc[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    
    int t, n;
    
    scanf("%d", &t);
    
    while(t--){
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            scanf("%d", &arr[i]);
            acc[i] = acc[i-1] + arr[i];
        }
        acc[n+1] = 0;
        
        int besty = (1LL << 31) - 1;
        for(int i = 1; i <= n; i++){
            int toEnd = acc[n] - acc[i];
            besty = min(besty, min(2*acc[i-1] + toEnd, 2*toEnd + acc[i-1]));
        }
        
        printf("%d\n", besty);
    }
    
    return 0;
}