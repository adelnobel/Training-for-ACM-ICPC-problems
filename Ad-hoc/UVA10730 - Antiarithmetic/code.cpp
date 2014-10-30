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

#define N 10000

int occ[N];

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    
    int n, x;
    char c;
    
    while(1){
        scanf("%d ", &n);
        if(n == 0) break;
        scanf("%c", &c);
        vector< int > v;
        for(int i = 0; i < n; i++){
            scanf("%d", &x);
            v.push_back(x);
            occ[x] = i;
        }
        
        bool ok = false;
        
        for(int i = 0; i < n && !ok; i++){
            for(int j = 1; !ok ; j++){
                int a = v[i] + j;
                int b = a + j;
                if(a >= n || b >= n) break;
                if(occ[a] > i && occ[b] > occ[a]) ok = true;
            }
        }
        
        printf(!ok ? "yes\n" : "no\n");
        
    }
    

    return 0;
}