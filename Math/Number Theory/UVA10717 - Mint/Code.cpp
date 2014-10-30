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

typedef long long ll;

int LCM(const int &a, const int &b){
    return a * b / __gcd(a, b);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    
    int n, t, x;
    vector< int > T, C;
    while(1){
        scanf("%d %d", &n, &t);
        if(!n && !t) break;
        T.clear();
        C.clear();
        for(int i = 0; i < n; i++){
            scanf("%d", &x);
            C.push_back(x);
        }
        for(int i = 0; i < t; i++){
            scanf("%d", &x);
            T.push_back(x);
        }
        for(int i = 0; i < T.size(); i++){
            int minLess = 2e9, minMore = 2e9;
            for(int a = 0; a < C.size(); a++){
                for(int b = a+1; b < C.size(); b++){
                    for(int c = b+1; c < C.size(); c++){
                        for(int d = c+1; d < C.size(); d++){
                            int lcm = LCM(C[a], LCM(C[b], LCM(C[c], C[d])));
                            int w = T[i] / lcm;
                            minLess = min(minLess, abs(w * lcm - T[i]));
                            minMore = min(minMore, abs((w+(T[i] % lcm != 0)) * lcm - T[i]));
                        }
                    }
                }
            }
            printf("%d %d\n", T[i] - minLess, T[i] + minMore);
        }
    }
    
    return 0;
}
