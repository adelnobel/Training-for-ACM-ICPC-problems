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

using namespace std;

vector< int > ans;

int dp[10000 + 5];

int solve(int n){
    if(n < 0) return 1e8;
    if(n == 0) return 0;
    int& ret = dp[n];
    if(ret != -1) return ret;
    ret = 1e8;
    for(int i = 0; i < ans.size(); i++){
        ret = min(ret, solve(n - ans[i]) + 1);
    }
    return ret;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif 
    
    int to = sqrt(10000) + 5;
    
    for(int i = 1; i < to; i++){
        ans.push_back(i*i);
    }
    
    int T, n;
    cin >> T;
    memset(dp, -1, sizeof dp);
    while(T--){
        scanf("%d", &n);
        cout << solve(n) << endl;
    }
    
}
