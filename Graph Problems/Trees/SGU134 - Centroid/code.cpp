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

#define N 16005

int ans[N], sz[N];
vector< int > adj[N];

int dfs(int n, int par){
    int& ret = sz[n];
    ret = 1;
    for(int i = 0; i < adj[n].size(); i++){
        int to = adj[n][i];
        if(to == par) continue;
        ret += dfs(to, n);
    }
    return ret;
}

void dfs2(int n, int par){
    int& res = ans[n];
    res = sz[0] - sz[n];
    for(int i = 0; i < adj[n].size(); i++){
        int to = adj[n][i];
        if(to == par) continue;
        dfs2(to, n);
        res = max(res, sz[to]);
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    
    int n, a, b;
    
    cin >> n;
    
    for(int i = 1; i < n; i++){
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    
    sz[0] = n;
    dfs(1, 0);
    dfs2(1, 0);
    
    int mini = 1e9;
    vector< int > v;
    
    for(int i = 1; i <= n; i++){
        if(ans[i] < mini){
            mini = ans[i];
            v.clear();
            v.push_back(i);
        }else if(ans[i] == mini){
            v.push_back(i);
        }
    }
    
    cout << mini << " " << v.size() << endl;
    sort(v.begin(), v.end());
    cout << v[0];
    for(int i = 1; i < v.size(); i++){
        printf(" %d", v[i]);
    }
    cout << endl;
    
    
    
    return 0;
}