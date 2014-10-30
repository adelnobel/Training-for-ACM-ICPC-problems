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
#include <cassert>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;

#define N 505

int match[N];
int M[N][N];
bool vis[N];

int L, R;

int Aug(int l){
    if(vis[l]) return 0;
    vis[l] = 1;
    for(int i = 0; i < R; i++){
        if(M[l][i] == 1){
            if(match[i] == -1 || Aug(match[i])){
                match[i] = l;
                return 1;
            }
        }
    }
    return 0;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    
    int n, t = 1, x;
    scanf("%d", &n);
    while(n--){
        
        
        scanf("%d %d", &L, &R);
        
        for(int i = 0; i < L; i++){
            for(int j = 0; j < R; j++){
                scanf("%d", &M[i][j]);
            }
        }
        memset(match, -1, sizeof match);
        int ans = 0;
        
        for(int i = 0; i < L; i++){
            memset(vis, false, sizeof vis);
            ans += Aug(i);
        }
        
        
        printf("Case %d: a maximum of %d nuts and bolts can be fitted together\n", t++, ans);
    }
    

    return 0;
}