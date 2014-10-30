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

using namespace std;

typedef long long ll;

int dz[] = {1, -1, 0, 0, 0, 0};
int dr[] = {0, 0, 1, -1, 0, 0};
int dc[] = {0, 0, 0, 0, 1, -1};

int Z, R, C;

char g[32][32][32];

bool vis[32][32][32];

typedef struct node{
    int z, r, c, cost;
    node(){};
    node(int zz, int rr, int cc, int co){
        z = zz, r = rr, c = cc, cost = co;
    }
}node;

bool isValid(node &c){
    if(c.z < 0 || c.z == Z || c.r < 0 || c.r == R || c.c < 0 || c.c == C || vis[c.z][c.r][c.c]){
        return false;
    }
    return true;
}

int bfs(node start){
    queue< node > q;
    q.push(start);
    
    while(!q.empty()){
        node c = q.front(); q.pop();
        if(g[c.z][c.r][c.c] == 'E') return c.cost;
        for(int i = 0; i < 6; i++){
            node cur = node(c.z + dz[i], c.r + dr[i], c.c + dc[i], c.cost + 1);
            if(isValid(cur)){
                vis[cur.z][cur.r][cur.c] = true;
                q.push(cur);
            }
        }
    }
    return -1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    
    while(scanf("%d%d%d", &Z, &R, &C), Z || R || C){
        memset(vis, false, sizeof vis);
        node start;
        for(int i = 0; i < Z; i++){
            for(int j = 0; j < R; j++){
                scanf("%s", g[i][j]);
                for(int k = 0; k < C; k++){
                    if(g[i][j][k] == '#') vis[i][j][k] = true;
                    else if(g[i][j][k] == 'S') start = node(i, j, k, 0);
                }
            }
        }
        int res = bfs(start);
        if(res == -1){
            printf("Trapped!\n");
        }else{
            printf("Escaped in %d minute(s).\n", res);
        }
    }
    
    return 0;
}
