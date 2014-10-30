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
    
    ll n;
    
    while(1){
        scanf("%lld", &n);
        if(n == 0) break;
        ll diff = 1LL << 61;
        ll two = 1;
        for(int i = 0; i < 36; i++){
            ll tot = two;
            for(int j = 0; j < 22; j++){
                ll cDiff = tot - n;
                if(cDiff >= 0){
                    diff = min(cDiff, diff);
                    break;
                }
                tot *= 3;
            }
            if(two > n) break;
            two <<= 1;
        }
        
        cout << n + diff << endl;
        
    }
    

    return 0;
}