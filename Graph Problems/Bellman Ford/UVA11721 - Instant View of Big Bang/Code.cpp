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
typedef pair<int, int> pi;

#define N 1005

vector< pi > adj[N];

int dist[N];
bool take[N];

void flood(const int n){
    if(take[n]) return;
    take[n] = true;
    for(int i = 0; i < adj[n].size(); i++){
        flood(adj[n][i].first);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    
    int n, t, m, a, b, c, T = 1;
    
    scanf("%d", &t);
    
    while(t--){
        memset(take, false, sizeof take);
        memset(dist, 0, sizeof dist);
        scanf("%d %d", &n, &m);
        for(int i = 0; i < m; i++){
            scanf("%d %d %d", &a, &b, &c);
            adj[b].push_back(pi(a, c));
        }
        
        bool cnt = true;
        for(int x = 0; x < n && cnt; x++){
            cnt = false;
            for(int i = 0; i < n; i++){
                for(int j = 0; j < adj[i].size(); j++){
                    int to = adj[i][j].first;
                    int cost = adj[i][j].second;
                    if(dist[to] > dist[i] + cost){
                        cnt = true;
                        dist[to] = dist[i] + cost;
                    }
                }
            }
        }
        
        bool cycle = false;
        
        vector< int > v;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < adj[i].size(); j++){
                int to = adj[i][j].first;
                int cost = adj[i][j].second;
                if(dist[to] > dist[i] + cost){
                    cycle = true;
                    v.push_back(i);
                    //cout << i << " ";
                }
            }
        }
        
        for(int i = 0; i < v.size(); i++){
            flood(v[i]);
        }
        
        printf("Case %d:", T++);
        if(!cycle) printf(" impossible");
        else{
            for(int i = 0; i < n; i++){
                if(take[i]) printf(" %d", i);
            }
        }
        printf("\n");
        
        for(int i = 0; i <= n; i++) adj[i].clear();

    }
    
    
    return 0;
}