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

#define N 2703673

bool isComp[N];
int tot[N];
int ACC[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    
    isComp[0] = isComp[1] = true;
    int w = 0;
    for(int i = 2; i < N; i++){
        if(!isComp[i]){
            tot[i] = 1;
            for(int j = i+i; j < N; j += i){
                isComp[j] = true;
                int x = j;
                while(x % i == 0) {
                    x /= i, tot[j]++;
                }
            }
        }
        w += tot[i];
        ACC[i] = w;
    }
    int n, t = 1;
    
    while(scanf("%d", &n), n >= 0){
        printf("Case %d: ", t++);
        if(n == 0) {
            printf("0!\n");
            continue;
        }
        int lo = 0, hi = N-1, mid;
        bool ok = false;
        while(lo <= hi){
            mid = (lo+hi) >> 1;
            if(ACC[mid] == n){
                printf("%d!\n", mid);
                ok = true;
                break;
            }else if(ACC[mid] > n){
                hi = mid - 1;
            }else{
                lo = mid + 1;
            }
        }
        if(!ok) printf("Not possible.\n");
    }
    
    
    
    return 0;
}
