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

using namespace std;

typedef long long ll;

#define INF ((int)1e8)

#define N 10005

vector< int > P, SP;
bool isComp[N];

int dp[N];

int solve(int r){
    if(r == 0) return 0;
    if(r < 0) return INF;
    
    int& ret = dp[r];
    if(ret != -1) return ret;
    
    ret = INF;
    for(int i = SP.size() - 1; i >= 0; i--){
        ret = min(ret, solve(r - SP[i]) + 1);
    }
    
    return ret;
}

void bk(int r, bool f){
    if(r == 0) return;
    if(r < 0) return;
    
    int& ret = dp[r];

    for(int i = SP.size() - 1; i >= 0; i--){
        if(solve(r - SP[i]) + 1 == ret){
            if(!f) printf(" ");
            printf("%d", SP[i]);
            bk(r - SP[i], false);
            break;
        }
    }
    
    return;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    
    isComp[0] = isComp[1] = true;
    
    for(int i = 2; i < N; i++){
        if(!isComp[i]){
            P.push_back(i);
            for(int j = i*i; j < N; j += i){
                isComp[j] = true;
            }
        }
    }    
    
    for(int i = 0; i < P.size(); i++){
        if(!isComp[i+1]) SP.push_back(P[i]);
    }
    
    memset(dp, -1, sizeof dp);
    int x;
    cin >> x;
    
    int ans = solve(x);
    if(ans > 10000){
        cout << 0 << endl;
    }else{
        cout << ans << endl;
        bk(x, true);
        cout << endl;
    }
    
    
    
    return 0;
}