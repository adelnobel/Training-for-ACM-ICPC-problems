#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

int par[30005], cnt[30005];

int parent(int x){
    return par[x] = x == par[x] ? x : parent(par[x]);
}

void join(int x, int y){
    par[parent(x)] = parent(y);
}

bool areSameSet(int x, int y){
    return parent(x) == parent(y);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    
    int t, n, m, prevN = 30004, a, b;
    
    scanf("%d", &t);
    
    while(t--){
        for(int i = 1; i <= prevN; i++){
            par[i] = i;
            cnt[i] = 0;
        }
        scanf("%d %d", &n, &m);
        prevN = n;
        
        for(int i = 0; i < m; i++){
            scanf("%d %d", &a, &b);
            //cout << a << b << endl;
            join(a, b);
        }
        int maxi = 0;
        
        for(int i = 1; i <= n; i++){
            cnt[parent(i)]++;
        }
        
        for(int i = 1; i <= n; i++){
            maxi = max(maxi, cnt[i]);
        }
        
        printf("%d\n", maxi);
        
    }
    
    
    
    return 0;
}

