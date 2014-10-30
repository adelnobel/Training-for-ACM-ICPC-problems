#include <cstdlib>
#include <iostream>
#include <vector>
#include <cstring>
#include <cassert>
#include <cstdio>
using namespace std;

#define N 2005

vector< int > adj[N];
bool vis[N];
int match[N];
bool isInMinCover[N];

int Aug(int l){
    if(vis[l]) return 0;
    vis[l] = true;
    for(int i = 0; i < adj[l].size(); i++){
        int to = adj[l][i];
        if(match[to] == -1 || Aug(match[to])){
            match[to] = l;
            match[l] = to;
            return 1;
        }
    }
    return 0;
}

void flood(int v){
     if(vis[v]) return;
     vis[v] = true;
     isInMinCover[v] = false;
     for(int i = 0; i < adj[v].size(); i++){
         int to = adj[v][i];
         if(!vis[to]){
              assert(match[to] != -1);
              isInMinCover[to] = true;
              vis[to] = true;
              flood(match[to]);
         }
     }
}

typedef pair<int, int> pi;

int main()
{
    int r, c, n, a, b;
    while(1){
         scanf("%d %d %d", &r, &c, &n);
         if(!r && !c && !n) break;
         for(int i = 0; i < N; i++) adj[i].clear();
         memset(match, -1, sizeof match);
         memset(isInMinCover, false, sizeof isInMinCover);
         for(int i = 0; i < n; i++){
             scanf("%d %d", &a, &b);
             adj[a].push_back(r+b);
             adj[r+b].push_back(a);
         }
         int tot = 0;
         for(int i = 1; i <= r; i++){
             memset(vis, 0, sizeof vis);
             tot += Aug(i);
         }
         
         memset(vis, 0, sizeof vis);
         for(int i = 1; i <= r+c; i++){
             if(match[i] == -1) flood(i);
         }
         
         vector< pi > ans;
         for(int i = 1; i <= r; i++){
             if(match[i] == -1) continue;
             int v;
             if(isInMinCover[match[i]]) ans.push_back(pi(1, match[i] - r)), v = match[i];
             else ans.push_back(pi(0, i)), v = i;
             
         }
         
         assert(tot == ans.size());
         printf("%d", tot);
         for(int i = 0; i < tot; i++){
             printf(" ");
             printf(ans[i].first ? "c" : "r");
             printf("%d", ans[i].second);
         }
         
         printf("\n");
         
    }
    
    return 0;
}
