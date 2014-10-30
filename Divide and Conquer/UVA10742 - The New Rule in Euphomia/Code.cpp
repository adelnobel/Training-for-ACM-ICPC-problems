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

#define N ((int)1e6 + 20)

bool isComp[N];

vector< int > primes;

int upBound(const int &x, const int &n){
    int lo = 0, hi = primes.size() - 1, mid, best = -1;
    while(lo <= hi){
        mid = (lo+hi) / 2;
        if(primes[mid] + x <= n){
            best = mid;
            lo = mid + 1;
        }else{
            hi = mid - 1;
        }
    }
    return best;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    
    int t= 1;
    
    for(int i = 2; i < N; i++){
        if(!isComp[i]){
            for(int j = i+i; j < N; j += i) isComp[j] = true;
        }
    }
    
    
    for(int i = 2; i < N; i++){
        if(!isComp[i]) primes.push_back(i);
    }
    
    int n;
    
    while(1){
        scanf("%d", &n);
        if(n == 0) break;
        ll tot = 0;
        for(int i = 0; i < primes.size(); i++){
            if(primes[i] + 2 > n) break;
            int lo = 0;
            int hi = upBound(primes[i], n);
            //cout << primes[i] << endl;
            //cout << lo << " " << hi << endl;
            tot += hi - lo + !(hi >= i);
        }
        
        printf("Case %d: %lld\n", t++, tot>>1LL);
    }
    

    return 0;
}