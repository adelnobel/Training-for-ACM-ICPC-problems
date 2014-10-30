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

int a[55];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    
    int n;
    
    while(scanf("%d", &n), n){
        for(int i = 0; i < n; i++){
            scanf("%d", &a[i]);
        }
        int tot = 0;
        for(int i = 0; i < n; i++){
            for(int j = i+1; j < n; j++){
                if(__gcd(a[i], a[j]) == 1) tot++;
            }
        }
        
        if(tot == 0) printf("No estimate for this data set.\n");
        else printf("%lf\n", sqrt((3. * (n*((n-1)))) / tot) );
    }
    
    
    return 0;
}