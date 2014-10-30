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



int main(){
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    int n, d, r, x;
    while(1){
        scanf("%d %d %d", &n, &d, &r);
        if(!n && !d && !r) break; 
        vector< int > A, B;
        for(int i = 0; i < n; i++){
            scanf("%d", &x);
            A.push_back(x);
        }
        for(int i = 0; i < n; i++){
            scanf("%d", &x);
            B.push_back(x);
        }
        sort(A.begin(), A.end());
        sort(B.begin(), B.end(), greater<int>());
        
        int tot = 0;
        for(int i = 0; i < n; i++){
            tot += max(0, A[i] + B[i] - d) * r;
        }
        
        cout << tot << endl;
        
    }
    
    
    return 0;
}