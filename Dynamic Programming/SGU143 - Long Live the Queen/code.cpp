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

/**
 
 * Passed with assumption that every node will have at most X edges (20 Edges)!! To avoid memory limit exceeded
 
 */

#define N 16003
#define X 20

short prof[N];
vector< short > adj[N];

int dp[N][X][2];

typedef struct node{
    short n, idx;
    bool taken;
    node(){};
    node(short a, short b, bool c){
        n = a, idx = b, taken = c;
    }
    bool operator<(const node& x) const{
        if(n != x.n) return n < x.n;
        if(idx != x.idx) return idx < x.idx;
        return taken < x.taken;
    }
}node;


int solve(const node& x, short par){
    int& ret = dp[x.n][x.idx][x.taken];
    if(ret != -1) {
        return ret;
    }
    
    if(x.taken) ret = 0;
    else ret = -1e9;
    
    if(x.idx == adj[x.n].size()) return ret;
    
    int take, leave, to = adj[x.n][x.idx];
    if(to == par){
        return ret = solve(node(x.n, x.idx+1, x.taken), par);
    }
    
    if(x.taken){
        take = solve(node(to, 0, true), x.n) + prof[to];
        leave = solve(node(x.n, x.idx+1, true), par);
        ret = max(ret, max(take, max(take+leave, leave)));
    }else{
        ret = max(ret, solve(node(to, 0, false), x.n));
        ret = max(ret, solve(node(to, 0, true), x.n) + prof[to]);
        ret = max(ret, solve(node(x.n, x.idx+1, false), par));
    }
    
    return ret;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    memset(dp, -1, sizeof dp);
    int n, a, b;
    cin >> n;
    for(int i = 1; i <= n; i++){
        scanf("%d", &prof[i]);
    }
    int maxi = 0;
    for(int i = 1; i < n; i++){
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
        maxi = max(maxi, (int)max(adj[a].size(), adj[b].size()));
    }
    assert(maxi < X);
    int x = solve(node(1, 0, true), 0) + prof[1];
    int y = solve(node(1, 0, false), 0);
    cout << max(x, y) << endl;
    
    return 0;
}