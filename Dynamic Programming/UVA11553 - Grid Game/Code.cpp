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


int n;
int g[10][10];

int dp[1<<8][1<<8][9];

int solve(int r, int c, int prev){
    bool isAlice = prev == 8;
    
    if(r == (1<<n) - 1 && c == (1<<n) - 1) return 0;
    
    int& ret = dp[r][c][prev];
    if(ret != -1) return ret;
    
    if(isAlice){
        ret = -1e9;
        for(int i = 0; i < n; i++){
            if(r & (1<<i)) continue;
            ret = max(ret, solve(r | (1<<i), c, i));
        }
    }else{
        ret = 1e9;
        for(int i = 0; i < n; i++){
            if(c & (1<<i)) continue;
            ret = min(ret, solve(r, c | (1<<i), 8) + g[prev][i]);
        }
    }
    
    return ret;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif

    
    int T;
    scanf("%d", &T);
    while(T--){
        memset(dp, -1, sizeof dp);
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                scanf("%d", &g[i][j]);
            }
        }
        
        printf("%d\n", solve(0, 0, 8));
        
    }
    

    return 0;
}