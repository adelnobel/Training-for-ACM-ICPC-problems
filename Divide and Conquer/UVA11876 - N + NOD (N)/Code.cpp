#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;

#define N ((int)1e6 + 10)
#define N2 ((int)1e6 + 4)

bool isComp[N];
int divi[N];
int A[N];

inline int NOD(int x){
    if(divi[x] == 0) return 2;
    
    int ret = 1;
    
    while(divi[x] != 0){
        int div = divi[x];
        int tot = 1;
        while(x % div == 0){
            tot++;
            x /= div;
        }
        ret *= tot;
    }
    if(x != 1) {
        ret *= 2;
    }
    return ret;
}



int main(){
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    
    int t = 1;
    
    for(int i = 2; i < N; i++){
        if(!isComp[i]){
            for(int j = i+i; j < N; j+=i){
                isComp[j] = true;
                if(divi[j] == 0) divi[j] = i;
            }
        }
    }
    
    int end = N2;
    
    A[0] = 1;
    A[1] = 2;
    A[2] = 4;
    for(int i = 3; i < N2; i++){
        A[i] = A[i-1] + NOD(A[i-1]);
        if(A[i] > 1000000) {
            end = i;
            break;
        }
    }
    
    int T, a, b;
    scanf("%d", &T);
    
    while(T--){
        scanf("%d %d", &a, &b);
        
        int A1, B1;
        
        int lo = 0, hi = end-1, mid;
        while(lo <= hi){
            mid = (lo+hi) / 2;
            if(A[mid] >= a){
                A1 = mid;
                hi = mid - 1;
            }else{
                lo = mid + 1;
            }
        }
        lo = 0, hi = end-1;
        while(lo <= hi){
            mid = (lo+hi) / 2;
            if(A[mid] <= b){
                B1 = mid;
                lo = mid + 1;
            }else{
                hi = mid - 1;
            }
        }
        
        printf("Case %d: %d\n", t++, B1 - A1 + 1);
        
        
    }
    

    return 0;
}