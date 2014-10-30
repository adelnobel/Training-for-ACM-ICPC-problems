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

#define EPS 1e-2
vector< int > H;

bool ok(double dist, int rem){
    double last = H[0] + dist;
    --rem;
    for(int i = 0; i < H.size(); i++){
        if(fabs(last - H[i]) <= dist) continue;
        last = H[i] + dist;
        --rem;
    }
    
    return rem >= 0;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    
    int t, m, n, x;
    scanf("%d", &t);
    
    while(t--){
        H.clear();
        scanf("%d %d", &m, &n);
        for(int i = 0; i < n; i++){
            scanf("%d", &x);
            H.push_back(x);
        }
        sort(H.begin(), H.end());
        
        double lo = 0, hi = H[H.size() - 1], best = 0;
        
        
        while(hi - lo > EPS){
            double mid = (lo+hi) / 2;
            if(ok(mid, m)){
                hi = mid;
                best = mid;
            }else{
                lo = mid;
            }
        }
        
        printf("%.1lf\n", best);
        
    }
    
    
    
    
    return 0;
}
