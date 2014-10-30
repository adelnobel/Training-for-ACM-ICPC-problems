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
    
    int  x, n;
    

    
    while(scanf("%d", &n) == 1){
        vector< int > v;
        for(int i = 0; i < n; i++){
            scanf("%d", &x);
            v.push_back(x);
        }
        
        scanf("%d", &x);
        if((x & 1) == 0){
            int tot = 0;
            for(int i = 0; i < v.size(); i++){
                if(x /2 == v[i]) tot++;
            }
            if(tot > 1){
                printf("Peter should buy books whose prices are %d and %d.\n\n", x / 2, x / 2);
                continue;
            }
        }
        
        sort(v.begin(), v.end());
        bool ok = false;
        int diff = 1e9, a, b, aa , bb;
        for(int i = 0; i < n; i++){
            if(binary_search(v.begin(), v.end(), x - v[i])){
                aa = v[i];
                bb = x - v[i];
                int cDiff = abs(aa - bb);
                if(cDiff < diff){
                    a = aa;
                    b = bb;
                    ok = true;
                    diff = cDiff;
                }
            }
        }
        
        assert(ok);
        printf("Peter should buy books whose prices are %d and %d.\n\n", a, b);
    }
    

    return 0;
}