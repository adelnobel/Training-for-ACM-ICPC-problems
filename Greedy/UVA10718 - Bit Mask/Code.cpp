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


int main(){
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    
    ll N, L, U;
    
    while(scanf("%lld %lld %lld", &N, &L, &U) == 3){
        
        int s = 0;
        for(int i = 0; i < 60; i++){
            if((1LL << i) & U) s = i;
        }
        
        ll M = 0;
        
        for(int i = s; i >= 0; i--){
            if(M < L && ((1LL<<i) & L)){
                M |= 1LL << i;
                continue;
            }
            if((M | (1LL << i)) > U) continue;
            if((1LL << i) & N) continue;
            M |= 1LL << i;
        }
        
        cout << M << endl;
        
    }
    

    return 0;
}