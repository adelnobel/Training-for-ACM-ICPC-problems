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

using namespace std;

typedef long long ll;

#define INF ((int)1e8)

int A[102][102];
bool vis[102][102];
int dp[102][102];


int F, V;

int solve(int f, int v){
    if(f == F) return 0;
    if(v == V) return -INF;
    
    int&ret = dp[f][v];
    if(vis[f][v]) return ret;
    vis[f][v] = true;
    
    return ret = max(solve(f, v+1), solve(f+1, v+1) + A[f][v]);
}

void bk(int f, int v){
    if(f == F) return ;
    if(v == V) return ;

    int leave = solve(f, v+1);
    int take = solve(f+1, v+1) + A[f][v];
    if(take > leave){
        if(f != 0) printf(" ");
        printf("%d", v+1);
        bk(f+1, v+1);
    }else{
        bk(f, v+1);
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    
    
    
    scanf("%d %d", &F, &V);
    
    for(int i = 0; i < F; i++){
        for(int j = 0; j < V; j++){
            scanf("%d", &A[i][j]);
        }
    }
    
    cout << solve(0, 0) << endl;
    bk(0, 0);
    cout << endl;
    
    return 0;
}