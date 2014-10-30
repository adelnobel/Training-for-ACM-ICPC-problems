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

int N, K, x;


unsigned int dp[312501];
int A[5005];

void inline sett(const int& x){
    int idx = x >> 5;
    dp[idx] |= 1 << (((1 << 5) - 1) & x);
}
bool inline gett(const int& x){
    int idx = x >> 5;
    return !(dp[idx] & (1 << (((1 << 5) - 1) & x)));
}

/**
void solve(int cur, bool f){
    if(cur > N) return;
    if(dp[cur]) return;
    if(!f) dp[cur] = true;
    int tot = cur;
    int x = cur;
    while(x > 0){
        tot += x % 10;
        x /= 10;
    }
    return solve(tot, false);
}**/

void solve(){
    for(int i = N; i >= 1; i--){
        int x = i;
        int tot = i;
        while(x > 0){
            tot += x % 10;
            x /= 10;
        }
        if(tot <= N) sett(tot);
    }
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    
    
    
    cin >> N >> K;
    vector< int > v;
    
    for(int i = 0; i < K; i++){
        scanf("%d", &x);
        v.push_back(x);
    }
    
    sort(v.begin(), v.end());
    
    /**
    for(int i = N; i > 0; i--){
        solve(i, true);
    }**/
    
    solve();
    int ans = 0, cur = 0;
    
    for(int i = 1; i <= N; i++){
        if(gett(i)) {
            ans++;
            if(ans == v[cur]){
                A[cur++] = i;
            }
        }
    }
    
    cout << ans << endl;
    
    printf("%d", A[0]);
    for(int i = 1; i < cur; i++){
        printf(" %d", A[i]);
    }

    cout << endl;

    
    return 0;
}