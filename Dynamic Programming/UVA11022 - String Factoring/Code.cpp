#include <vector>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <bitset>
#include <map>
#include <complex>
#include <ctime>
#include <numeric>
#include <set>
#include <cassert>

using namespace std;

typedef long long ll;
typedef pair<ll, int> pi;

#define N 82

const int INF = 1e8;

char S[N];
int dp[N][N];
int solve(int s, int e){
    if(s > e){
        return INF;
    }
    if(s == e) return 1;
    int& ret = dp[s][e];
    if(ret != -1) return ret;
    int l = e - s + 1;
    ret = l;
    for(int i = 1; i <= l; i++){
        if(l % i != 0) continue;
        int part = l / i;
        bool ok = true;
        for(int j = 1; j < part && ok; j++){
            int w = j*i + s;
            for(int k = 0; k < i && ok; k++){
                if(S[w+k] != S[k+s]) ok = false;
            }
        }
        if(ok){
            ret = min(ret, solve(s, s+i-1));
        }
    }
    
    for(int i = s; i <= e; i++){
        ret = min(ret, solve(s, i) + solve(i+1, e));
    }
    
    return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    
    while(scanf("%s", S), S[0] != '*'){
        memset(dp, -1, sizeof dp);
        int l = strlen(S);
        cout <<  solve(0, l-1) << endl;
    }
    
    return 0;
}
