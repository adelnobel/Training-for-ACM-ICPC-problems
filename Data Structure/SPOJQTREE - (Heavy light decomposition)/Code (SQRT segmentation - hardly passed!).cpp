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

#define SIZE 100

#define N 10005
typedef pair<int ,int> pi;
vector< pi > adj[N];
int lca[N][15];
pi par[N], path[N], edges[N];
int skip[N], sz[N];
bool heavy[N];
int heavyR[N];
int depth[N];
char s[10];

void dfs(int cur, int d, int P){
    lca[cur][0] = P;
    for(int i = 1; i <= 14; i++){
        lca[cur][i] = lca[lca[cur][i-1]][i-1];
    }
    depth[cur] = d;
    sz[cur] = 1;
    for(int i = 0; i < adj[cur].size(); i++){
        int to = adj[cur][i].first;
        int cost = adj[cur][i].second;
        if(to == P) continue;
        par[to].first = cur;
        par[to].second = cost;
        dfs(to, d+1, cur);
        sz[cur] += sz[to];
    }
}

void initSkip(int cur, int P){
    skip[cur] = cur;
    if(cur != 1){
        int rootOfPath = skip[P];
        if(sz[cur] > (sz[P] / 2) && path[rootOfPath].first < SIZE){
            heavy[cur] = true;
            heavyR[P] = cur;
            skip[cur] = skip[P];
            path[rootOfPath].second = max(path[rootOfPath].second, par[cur].second);
            path[rootOfPath].first++;
        }
    }
    for(int i = 0; i < adj[cur].size(); i++){
        int to = adj[cur][i].first;
        if(to == P) continue;
        initSkip(to, cur);
    }
}

int raise(int n, int l){
    for(int i = 0; i <= 14; i++){
        if(l & (1<<i)){
            n = lca[n][i];
        }
    }
    return n;
}

int LCA(int a, int b){
    if(depth[a] > depth[b]){
        a = raise(a, depth[a] - depth[b]);
    }else{
        b = raise(b, depth[b] - depth[a]);
    }
    if(a == b) return a;
    for(int i = 14; i >= 0; i--){
        if(lca[a][i] != lca[b][i]){
            a = lca[a][i];
            b = lca[b][i];
        }
    }
    return par[a].first;
}

int getPath(int a, int b){
    int ret = 0;
    if(a == b) return ret;
    assert(depth[a] > depth[b]);
    while(a != b){
        int rootOfPath = skip[a];
        if(heavy[a] && depth[rootOfPath] >= depth[b] && depth[a] - depth[rootOfPath] == path[rootOfPath].first){
            a = rootOfPath;
            ret = max(ret, path[rootOfPath].second);
        }else{
            ret = max(ret, par[a].second);
            a = par[a].first;
        }
    }
    return ret;
}

int getMax(int a, int b){
    int root = LCA(a, b);
    return max(getPath(a, root), getPath(b, root));
}

int update(int a, int b, int val){
    par[b].second = val;
    if(heavy[b]){
        int rootOfPath = skip[a];
        path[rootOfPath].second = 0;
        int cur = rootOfPath, tot = 0;
        while(heavyR[cur] != 0){
            int to = heavyR[cur];
            path[rootOfPath].second = max(path[rootOfPath].second, par[to].second);
            assert(par[to].first == cur);
            tot++;
            cur = to;
        }
        assert(tot == path[rootOfPath].first);
    }
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    int T, a, b, c, n;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        for(int i = 0; i < n-1; i++){
            scanf("%d %d %d", &a, &b, &c);
            adj[a].push_back(pi(b, c));
            adj[b].push_back(pi(a, c));
            edges[i].first = a;
            edges[i].second = b;
        }
        
        
        dfs(1, 0, 0);
        sz[0] = 1e9;
        initSkip(1, 0);
        
        while(1){
            scanf("%s", s);
            if(s[0] == 'D') break;
            scanf("%d %d", &a, &b);
            if(s[0] == 'Q'){
                printf("%d\n", getMax(a, b));
            }else{
                if(depth[edges[a-1].first] > depth[edges[a-1].second]){
                    swap(edges[a-1].second, edges[a-1].first);
                }
                update(edges[a-1].first, edges[a-1].second, b);
            }
        }
        
        
        
        for(int i = 0; i <= n; i++){
            adj[i].clear();
            par[i].first = par[i].second = path[i].first = path[i].second = 0;
            heavy[i] = 0;
            heavyR[i] = 0;
        }
    }
    
    
    return 0;
}
