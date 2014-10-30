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

ll dp[68][68][2];
int n, s;
ll solve(int idx, int rem, bool prevOpened){
    if(rem < 0) return 0;
    if(idx == 0){
        return rem == 0;
    }
    ll& ret = dp[idx][rem][prevOpened];
    if(ret != -1) return ret;
    
    ll lock = solve(idx-1, rem - !prevOpened, false);
    ll open = solve(idx-1, rem, true);
    
    return (ret = lock + open);
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif

    memset(dp, -1, sizeof dp);
    while(1){
        scanf("%d %d", &n, &s);
        if(n < 0 && s < 0) break;
        cout << solve(n, s, false) << endl;
    }
    
    
    return 0;
}