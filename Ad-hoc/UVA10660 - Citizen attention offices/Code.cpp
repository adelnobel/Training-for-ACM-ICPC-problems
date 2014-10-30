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

int A[5][5];

int pos[7];
int ans[7];
pi X[25];
int distancee[27][6];

int cnt;

inline int calc(){
    int ret = 0;
    for(int i = 0; i < 25; i++){
        int r = X[i].first;
        int c = X[i].second;
        int mini = distancee[i][0];
        for(int j = 1; j < 5; j++){
            if(distancee[i][j] < mini) mini = distancee[i][j];
        }
        ret += A[r][c] * mini;
    }
    return ret;
}

inline void update(const int& p){
    int rO = X[pos[p]].first, cO = X[pos[p]].second;
    for(int i = 0; i < 25; i++){
        int r = X[i].first, c = X[i].second;
        distancee[i][p] = abs(rO - r) + abs(cO - c);
    }
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    
    int n, T, r, c, v;
    
    for(int i = 0; i < 25; i++){
        X[i].first = i / 5;
        X[i].second = i % 5;
    }
    
    scanf("%d", &T);
    while(T--){
        cnt = 0;
        scanf("%d", &n);
        memset(A, 0, sizeof A);
        for(int i = 0; i < n; i++){
            scanf("%d %d %d", &r, &c, &v);
            A[r][c] = v;
        }
        int best = 1e9;
        for(int a = 0; a < 21; a++){
            pos[0] = a;
            update(0);
            for(int b = a+1; b < 22; b++){
                pos[1] = b;
                update(1);
                for(int c = b+1; c < 23; c++){
                    pos[2] = c;
                    update(2);
                    for(int d = c+1; d < 24; d++){
                        pos[3] = d;
                        update(3);
                        for(int e = d+1; e < 25; e++){
                            pos[4] = e;
                            update(4);
                            int val = calc();
                            if(val < best){
                                best = val;
                                memcpy(ans, pos, sizeof ans);
                            }
                        }
                    }
                }
            }
        }
        printf("%d", ans[0]);
        for(int i = 1; i < 5; i++){
            printf(" %d", ans[i]);
        }
        printf("\n");
        
    }
    

    return 0;
}