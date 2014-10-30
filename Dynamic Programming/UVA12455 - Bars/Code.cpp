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

int n, A[22];
char dp[1006][21];

bool solve(int rem, int cur){
    if(rem == 0) return true;
    if(rem < 0 || cur < 0) return false;
    char &ret = dp[rem][cur];
    if(ret != 'N') return ret == 'T';
    
    if(solve(rem - A[cur], cur-1) || solve(rem, cur-1)){
        ret = 'T';
        return true;
    }else{
        ret = 'F';
    }
    
    return false;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    
    int T, x, n;
    
    scanf("%d", &T);
    
    while(T--){
        memset(dp, 'N', sizeof dp);
        scanf("%d %d", &x, &n);
        assert(x <= 1000);
        assert(n <= 20);
        for(int i = 0; i < n; i++){
            scanf("%d", &A[i]);
        }
        
        printf(solve(x, n-1) ? "YES\n" : "NO\n"); 
        
    }
    

    return 0;
}