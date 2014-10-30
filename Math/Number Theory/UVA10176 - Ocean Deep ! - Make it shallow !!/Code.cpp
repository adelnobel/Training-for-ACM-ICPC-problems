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

using namespace std;

typedef long long ll;

#define MOD 131071


char s[10005];

ll powLog(int base, int pow){
    if(pow == 0) return 1;
    if(pow == 1) return base;
    
    ll ret = powLog(base, pow/2);
    ret = (ret * ret) % MOD;
    if(pow & 1) ret = (ret * base) % MOD;
    
    return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    
    while(1){
        s[0] = '\0';
        int read, cur = 0;
        while(scanf(" %s%n ", s+cur, &read) == 1){
            cur += read;
            if(s[cur-1] == '#')break;
        }
        if(s[0] == '\0') break;
        ll tot = 0;
        int l = strlen(s);
        for(int i = 0; i < l-1; i++){
            if(s[i] == '1'){
                tot = ((tot % MOD) + (powLog(2, l - i - 2) % MOD)) % MOD;
            }
        }
        
        printf(tot == 0 ? "YES\n" : "NO\n");
    }
    
    
    
    
    
    return 0;
}