#include <cstdlib>
#include <iostream>
#include <vector>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

ll n, k;


int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    


    while(scanf("%lld %lld", &n, &k) == 2){
        ll res = 0;
        while(n >= k){
            res += n - (n % k);
            n = (n % k) + n/k;
        }
        printf("%lld\n", res+n);
    }
    
    
    return 0;
}
