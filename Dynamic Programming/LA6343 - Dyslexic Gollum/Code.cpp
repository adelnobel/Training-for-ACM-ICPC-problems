#include <cstdlib>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <queue>
#include <cmath>
 
using namespace std;

typedef long long ll;

#define MOD 1000000007

int dp[401][1<<11][12];
char memo[1<<11][12];


bool invalid(int mask, int k){
    if(memo[mask][k] != 'N') return memo[mask][k] == 'T';
    bool ret = true;
    for(int i = 0, to = k/2; i < to; i++){
        bool a = (mask & (1<<i)) == 0;
        bool b = (mask & (1<<(k-i-1))) == 0;
        if(  b != a  ) ret = false;
    }
    memo[mask][k] = ret ? 'T' : 'F';
    return ret;
}

int solve(int idx, int mask, int k){
    
    if(invalid(mask >> 1, k-1)) return 0;
    if(invalid(mask, k-1)) return 0;
    if(invalid(mask, k)) return 0;
    
    if(idx == 0) return 1;
    int&ret = dp[idx][mask][k];
    if(ret != -1) return ret;
    
    int x = (mask >> 1);
    ret = solve(idx-1, x | (1<<(k-1)), k) + solve(idx-1, x, k);
    ret %= MOD;
    return ret;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    //freopen("in.out2", "w", stdout);
#endif
    
    /**
    cout << 4000 << endl;
    for(int i = 1; i <= 400; i++){
        for(int j = 1; j <= 10; j++){
            cout << i << " " << j << endl;
        }
    }
    return 0;**/
    
    memset(dp, -1, sizeof dp);
    memset(memo, 'N', sizeof memo);
    int T, n, k;
    scanf("%d", &T);
    
    while(T--){
        scanf("%d %d", &n, &k);
        int ans = 0;
        if(k > n) ans = 1<<n ;
        else if(k == n){
            for(int i = 0, to = (1<<k); i < to; i++){
                if(!invalid(i, k)) ans++;
            }
        }
        else{
            k++;
            for(int i = 0, to = (1<<(k)); i < to; i++){
                ans += solve(n-k, i, k);
                ans %= MOD;
            }
        }
        printf("%d\n", ans);
    }
    
    return 0;
}