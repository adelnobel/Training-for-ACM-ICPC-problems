#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
#include <set>
#include <cassert>
#include <ctime>
#include <bitset>

using namespace std;

typedef long long ll;

ll dp[65];

ll solve(int x){
    if(x == 0 || x == 2) return 1;
    ll & ret = dp[x];
    if(ret != -1) return ret;
    int L = x - 2;
    
    ret = 0;
    for(int i = 0; i <= L; i+=2){
        ret += solve(i) * solve(L-i);
    }
    
    return ret;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    
    memset(dp, -1, sizeof dp);
    int N;
    
    cin >> N;
    N *= 2;
    
    cout << solve(N) << " " << N/2 + 1 << endl;
    
    
    return 0;
}