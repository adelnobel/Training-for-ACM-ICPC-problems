#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>

using namespace std;

int T, R, C, N, X, Y;
int memo[1<<16][16][4][4], cnt[1<<16];

void printMask(int &initial){
       for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                if(initial & (1 << ((i*C)+j))) cout << "*";
                else cout << ".";
            }
            cout << endl;
        }
}

int solve(int mask, int rem, int r, int c){
    if(cnt[mask] == 1) return 1;
    if(rem < 0){
        return 0;
    }
    if(memo[mask][rem][r][c] != -1) return memo[mask][rem][r][c];
    int R = r+1, C = c+1; //Just fixing
    
    int ret = 0, jmpX, jmpY, adjX, adjY, nMask;
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(!(mask & (1 << ((i * C) + j)))) continue;
            for(int x = -1; x <= 1; x++){
                for(int y = -1; y <= 1; y++){
                    if(x == 0 && y == 0) continue;
                    adjX = i + x;
                    adjY = j + y;
                    jmpX = i + (2*x);
                    jmpY = j + (2*y);
                    if(adjX < 0 || adjX == R || adjY < 0 || adjY == C) continue;
                    if(jmpX < 0 || (jmpX == R) || jmpY < 0 || jmpY == C) continue;
                    
                    if(mask & (1<<(jmpX*C + jmpY))) continue;
                    if(!(mask & (1<<((adjX * C) + adjY)))) continue;
                    nMask = mask & (~(1<<((adjX * C) + adjY)));
                    nMask &= ~(1 << ((i * C) + j));
                    nMask |= 1 << (jmpX*C + jmpY);/**
                    cout << endl;
                    printMask(mask);
                    cout << "-------" << endl;
                    printMask(nMask);
                    cout << endl << endl << endl;**/
                    ret += solve(nMask, rem-1, r, c);
                }
            }
            
        }
    }
    
    return memo[mask][rem][r][c] = ret;
}



int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    
    for(int i = 0, to = 1<<16; i < to; i++){
        cnt[i] = __builtin_popcount(i);
    }
    
    int c = 1;
    
    scanf("%d", &T);
    memset(memo, -1, sizeof memo);
    while(T--){
        scanf("%d %d %d", &R, &C, &N);
        int initial = 0;
        for(int i = 0; i < N; i++){
            scanf("%d %d", &X, &Y);
            X--, Y--;
            initial |= 1 << ((X * C) + Y);
        }
        printf("Case %d: %d\n", c++, solve(initial, N-1, R-1, C-1));
    }

    
    return 0;
}

