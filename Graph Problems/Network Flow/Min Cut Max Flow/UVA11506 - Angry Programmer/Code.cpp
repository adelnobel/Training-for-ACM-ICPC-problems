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

using namespace std;

const int N = 52;
const int S = N * 2 + 5;

#define NODE_IN(x) x
#define NODE_OUT(x) (x + N)


typedef struct edge{
    int to, cap, rev;
    edge(){};
    edge(int a, int b, int c): to(a), cap(b), rev(c){};
}edge;

vector< edge > adj[S];
bool vis[S];

void addEdge(int a, int b, int c){
    adj[a].push_back(edge(b, c, adj[b].size()));
    adj[b].push_back(edge(a, 0, adj[a].size() - 1));
}


int curCost;
int n, m, x, a, b;
bool dfs(int v){
    if(v == NODE_IN(n)) return true;
    if(vis[v]) return false;
    vis[v] = true;
    for(int i = 0; i < adj[v].size(); i++){
        int to = adj[v][i].to;
        if(adj[v][i].cap >= curCost && dfs(to)){
            adj[v][i].cap -= curCost;
            adj[to][ adj[v][i].rev ].cap += curCost;
            return true;
        }
    }
    return false;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);


    while(cin >> n >> m, n || m){
        for(int i = 0; i < S; i++){
            adj[i].clear();
        }
        for(int i = 2; i <= n - 1; i++){
            cin >> x;
            cin >> a;
            addEdge(NODE_IN(x), NODE_OUT(x), a);
            addEdge(NODE_OUT(x), NODE_IN(x), a);
        }

        for(int i = 0; i < m; i++){
            cin >> a >> b >> x;
            addEdge(NODE_OUT(a), NODE_IN(b), x);
            addEdge(NODE_OUT(b), NODE_IN(a), x);
        }

        int total = 0;

        for(curCost = 1 << 20; curCost > 0; curCost >>= 1){
            while(memset(vis, false, sizeof vis), dfs(NODE_OUT(1))){
                total += curCost;
            }
        }

        cout << total << endl;

    }


    return 0;
}
