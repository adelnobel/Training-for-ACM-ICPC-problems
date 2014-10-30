#include <cstdlib> 
#include <iostream>
#include <vector> 
#include <cstring> 
#include <cassert>
#include <cstdio> 
#include <algorithm> 
#include <map>
using namespace std;

typedef long long ll;
typedef pair<int, int> pi;

#define INF 1e8
#define MOD 20437
#define X (100*27)
int dr[] = {1, 0, -1, 0};
int dc[] = {0, 1, 0, -1};
int n, N;
pi dp[2][28][10][10];


char G[11][11];
/**
pi solve(int r, int c, int cur, int steps){
    if(cur == n) return pi(steps, 1);
    if(steps >= X) return pi(INF, 0);
    pi& ret = dp[r][c][cur][steps];
    if(vis[r][c][cur][steps]) return ret;
    vis[r][c][cur][steps] = true;
    ret = pi(INF, 0);
    for(int i = 0; i < 4; i++){
        int nr = dr[i] + r, nc = dc[i] + c;
        if(nr < 0 || nr == N || nc < 0 || nc == N) continue;
        if(G[nr][nc] == '#') continue;
        if(isalpha(G[nr][nc]) && (G[nr][nc] - 'A' > cur)) continue;
        pi res = solve(nr, nc, cur + (G[nr][nc] - 'A' == cur) , steps + 1);
        if(res.first < ret.first){
            ret = res;
            ret.second = 0;
        }
        if(res.first == ret.first){
            ret.second += res.second;
            if(res.second >= MOD) res.second %= MOD;
        }
    }
    return ret;
}
**/
pi solve(int a, int b, int c, int d){
    for(int steps = n*N*N; steps >= 0; steps--){
        int st = steps & 1;
        for(int cur = n; cur >= 1; cur --){
            for(int r = N-1; r >= 0; r--){
                for(int c = N-1; c >= 0; c--){
                    pi& ret = dp[st][cur][r][c];
                    if(cur == n) {
                        ret = pi(steps, 1);
                        continue;
                    }
                    if(steps >= n*N*N) {
                        ret = pi(INF, 0);
                        continue;
                    }
                    ret = pi(INF, 0);
                    for(int i = 0; i < 4; i++){
                        int nr = dr[i] + r, nc = dc[i] + c;
                        if(nr < 0 || nr == N || nc < 0 || nc == N) continue;
                        if(G[nr][nc] == '#') continue;
                        if(isalpha(G[nr][nc]) && (G[nr][nc] - 'A' > cur)) continue;
                        pi &res = dp[1-st][cur + (G[nr][nc] - 'A' == cur)][nr][nc];
                        if(res.first < ret.first){
                            ret = res;
                            ret.second = 0;
                        }
                        if(res.first == ret.first){
                            ret.second += res.second;
                            if(ret.second >= MOD) ret.second %= MOD;
                        }
                    }
                }
            }
        }
    }

    return dp[0][1][a][b];
}


int main() { 
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    int t = 1;
    
    while(scanf("%d", &N), N != 0){
        n = 0;
        pi s;
        for(int i = 0; i < N; i++){
            scanf("%s", G[i]);
            for(int j = 0; j < N; j++){
                if(isalpha(G[i][j])){
                    n = max(n, G[i][j] - 'A' + 1);
                    if(G[i][j] == 'A') s = pi(i, j);
                }
            }
        }
        pi res = solve(s.first, s.second, 1, 0);
        printf("Case %d: ", t++); 
        if(res.second == 0){
            printf("Impossible\n");
        }else{
            printf("%d %d\n", res.first, res.second);
        }
    }
     
    return 0; 

}