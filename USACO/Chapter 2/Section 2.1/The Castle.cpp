/*
ID: adelnob1
PROG: castle
LANG: C++
*/

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
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <limits>
#include <tr1/unordered_map>

using namespace std;

typedef long long ll;

#define MAX_N 250

int M, N, c;

char g[MAX_N][MAX_N];
int vis[MAX_N][MAX_N];

int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
char dirs[] = "WNES";

int componentSize[3000];

int dfs(int curComponent, int x, int y)
{
    if(vis[x][y] != 0) return 0;
    vis[x][y] = curComponent;
    
    int ret = 0;
    if(g[x][y] == '.') ret++;
    
    for(int i = 0; i < 4; i++){
        if(g[x+dx[i]][y+dy[i]] != '#'){
            ret += dfs(curComponent, x+dx[i], y+dy[i]);
        }
    }
    
    return ret;
}

typedef struct wall{
    int first, second, dir, roomX, roomY, bestConnect;
    wall(){
        bestConnect = 0;
    };
    wall(int f, int s, int d, int x, int y){
        first = f;
        second = s;
        dir = d;
        roomX = x;
        roomY = y;
        bestConnect = 0;
    }
    
    bool operator<(const wall &w) const{
        if(bestConnect != w.bestConnect) return bestConnect > w.bestConnect;
        if(roomY != w.roomY) return roomY < w.roomY;
        if(roomX != w.roomX) return roomX > w.roomX;
        return dir < w.dir;
    }
    
}wall;

vector< wall > walls;

int main()
{
    freopen("in.in", "r", stdin);
    freopen("castle.out", "w", stdout);
    
    memset(g, '#', sizeof g);
    memset(vis, 0, sizeof vis);
    
    scanf("%d %d", &N, &M);
    
    int curRow, curCol;
    
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            curRow = 2*i + 1;
            curCol = 2*j + 1;
            scanf("%d", &c);
            g[curRow][curCol] = '.';
            for(int k = 0; k < 4; k++){
                if(c & (1 << k)){
                    g[curRow + dx[k]][curCol + dy[k]] = '#';
                    if(k == 0 || k == 3) continue;
                    walls.push_back(wall(curRow + dx[k], curCol + dy[k], k, i, j));
                }else{
                    g[curRow + dx[k]][curCol + dy[k]] = '*';
                }
            }
        }
    }
    
    
    int curComponent = 1;
    int maxi = 0;
    
    for(int i = 0; i <= M*2; i++){
        for(int j = 0; j <= (N+1) * 2; j++){
            if(!vis[i][j] && g[i][j] == '.'){
                componentSize[curComponent] = dfs(curComponent, i, j);
                maxi = max(maxi, componentSize[curComponent]);
                curComponent++;
            }
        }
    }
    
    printf("%d\n", curComponent - 1);
    printf("%d\n", maxi);
    
    int maxSize = maxi;
    

    for(int i = 0; i < walls.size(); i++){
        if(walls[i].first > 0 && vis[walls[i].first - 1][walls[i].second] != vis[walls[i].first + 1][walls[i].second]){
            if(componentSize[vis[walls[i].first - 1][walls[i].second]] +  componentSize[vis[walls[i].first + 1][walls[i].second]] >= maxSize){
                maxSize = componentSize[vis[walls[i].first - 1][walls[i].second]] + componentSize[vis[walls[i].first + 1][walls[i].second]];
                walls[i].bestConnect = maxSize;
            }
        }
        if(walls[i].second > 0 && vis[walls[i].first][walls[i].second - 1] != vis[walls[i].first][walls[i].second + 1]){
            if(componentSize[vis[walls[i].first][walls[i].second - 1]] + componentSize[vis[walls[i].first][walls[i].second + 1]] >= maxSize){
                maxSize = componentSize[vis[walls[i].first][walls[i].second - 1]] +  componentSize[vis[walls[i].first][walls[i].second + 1]];
                walls[i].bestConnect = maxSize;
            }
        }
    }
    
    
    
    
    printf("%d\n", maxSize);
    
    sort(walls.begin(), walls.end());
    
    int bestWall = 0;
    
    printf("%d %d %c\n", walls[bestWall].roomX+1, walls[bestWall].roomY+1, dirs[walls[bestWall].dir]);
    

    
    
    return 0;
}