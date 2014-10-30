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
#include <ctime>
#include <set>

using namespace std;

typedef long long ll;

int n, m;

int conns[410][410], arr1[205], arr2[205];

bool vis[410];
int pars[410];

int findFlow(){
    memset(vis, false, sizeof vis);
    queue<int> q;
    q.push(0);
    vis[0] = true;
    pars[0] = -1;
    
    bool flowExists = false;
    
    while(!q.empty()){
        int cur = q.front(); q.pop();
        
        if(cur <= n){
            int s = n+1, e = n + m;
            if(cur == 0) s = 1, e = n;
            for(int i = s; i <= e; i++){
                if(conns[cur][i] > 0 && !vis[i]){
                    pars[i] = cur;
                    vis[i] = true;
                    q.push(i);
                }
            }
        }else{
            if(conns[cur][n+m+1] > 0){
                pars[n+m+1] = cur;
                flowExists = true;
                break;
            }
            for(int i = 1; i <= n; i++){
                if(conns[cur][i] > 0 && !vis[i]){
                    pars[i] = cur;
                    vis[i] = true;
                    q.push(i);
                }
            }
        }
    }
    
    if(!flowExists) return 0;
    
    int cur = n + m + 1;
    while(pars[cur] != -1){
        conns[pars[cur]][cur] = 0;
        conns[cur][pars[cur]] = 1;
        cur = pars[cur];
    }
    
    return 1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    
    int t, c = 1;
    
    scanf("%d", &t);
    
    while(t--){
        memset(conns, 0, sizeof conns);
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            scanf("%d", &arr1[i]);
        }
        scanf("%d", &m);
        for(int i = 0; i < m; i++){
            scanf("%d", &arr2[i]);
        }
        
        
        for(int i = 0; i < n; i++){
            conns[0][1+i] = 1;
        }
        for(int j = 0; j < m; j++){
            conns[n+j+1][n+m+1] = 1;
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if( (arr1[i] != 0 && arr2[j] % arr1[i] == 0) || (arr1[i] == 0 && arr2[j] == 0)){
                    conns[i + 1][n + j + 1] = 1;
                }
            }            
        }
        
        int totFlow = 0;
        while(1){
            int f = findFlow();
            if(f == 0) break;
            totFlow += f;
        }
        printf("Case %d: %d\n", c++, totFlow);
    }
    
    return 0;
}

