#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <cmath>
#include <iostream>
#include <bitset>
#include <map>
#include <ctime>
#include <set>
#include <complex>
#include <vector>
#include <queue>

using namespace std;

typedef long long ll;
//typedef pair<int, int> pi;

#define N 10005

typedef struct pi{
    int first, second;
    pi();
    pi(int a, int b): first(a), second(b){};
    bool operator<(const pi& p) const{
        if(first != p.first) return first < p.first;
        return second < p.second;
    }
}pi;

vector< pi > adj[N];


int best[103][N];

vector< int > v;
set< pi > pq;
void dijkstra(const int& n){
    pq.clear();
    set< pi >::iterator it;
    best[n][v[n]] = 0;
    pq.insert(pi(0, v[n]));
    while(!pq.empty()){
        pi cur = pi(pq.begin()->first, pq.begin()->second); pq.erase(pq.begin());
        if(cur.first > best[n][cur.second]) continue;
        if(cur.first > 600) continue;
        for(int i = 0; i < adj[cur.second].size(); i++){
            int cost = cur.first + adj[cur.second][i].second;
            int to = adj[cur.second][i].first;
            if(best[n][to] <= cost) continue;
            it = pq.find(pi(best[n][to], to));
            if(it != pq.end())
            pq.erase(pq.find(pi(best[n][to], to)));
            best[n][to] = cost;
            pq.insert(pi(cost, to));
        }
    }
}


int vis[105];

int solve(){
    memset(best, 63, sizeof best);
    memset(vis, 63, sizeof vis);
    queue< int > q;
    vis[0] = 0;
    q.push(0);
    while(!q.empty()){
        int cur = q.front(); q.pop();
        if(cur == (v.size() - 1)) return vis[cur] - 1;
        if(best[cur][v[cur]] != 0) dijkstra(cur);
        for(int i = 0; i < v.size(); i++){
            int to = i;
            int edgeCost = best[cur][v[to]];
            int cost = vis[cur] + 1;
            if(edgeCost > 600) continue;
            if(vis[to] <= cost) continue;
            if(to == (v.size() - 1)) return cost - 1;
            vis[to] = cost;
            q.push(to);
        }
    }
    
    return -1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    //freopen("in.in", "w", stdout);
#endif
    /*for(int x = 0; x < 1; x++){
    printf("10000\n");
    printf("100");
    for(int i = 0; i < 100; i++){
        printf(" %d", 1+i);
    }
    printf("\n%d\n", 100000);
    for(int i = 0; i < 100000; i++){
        printf("%d %d %d\n", rand() % 10000 + 1, rand() % 10000 + 1, rand() % 300);
    }
    }
    
    printf("0\n");
    
    return 0;**/
    
    int n, h, x, m, a, b, c;
    while(1){
        scanf("%d", &n);
        if(n == 0) break;
        scanf("%d", &h);
        v.clear();
        v.push_back(1);
        for(int i = 0; i < h; i++){
            scanf("%d", &x);
            if(x != 1 && x != n){
                v.push_back(x);
            }
        }
        v.push_back(n);
        scanf("%d", &m);
        for(int i = 0; i < m; i++){
            scanf("%d %d %d", &a, &b, &c);
            adj[a].push_back(pi(b, c));
            adj[b].push_back(pi(a, c));
        }
        /**
        for(int i = 0; i < v.size(); i++){
            cout << v[i] << " - > ";
            for(int j = 1; j <= n; j++){
                printf("%d ", best[i][j]);
            }
            cout << endl;
        }**/
        
        
        cout << solve() << endl;
        
        for(int i = 0; i <= n; i++) adj[i].clear();
    }
    
    
    return 0;
}