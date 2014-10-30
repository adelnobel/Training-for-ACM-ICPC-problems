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
#include <algorithm>

using namespace std;

typedef pair<int, int> pi;

#define X first
#define Y second

pi pos[13];

int L, N, x, y;

bool valid[13];
int popCnt[1 << 13], dp[1<<12][41][12];

int calcCost(int mask, int &f, int &s){
    int cost = 0;
    if(pos[f].X == pos[s].X){ //Same Row
        cost = 1;
        int start = min(f, s) + 1;
        int end = max(f, s);
        while(start < end) {
            if(!valid[start] || !(mask & (1<<start))) return -1;
            ++cost;
            ++start;
        }
    }else if(pos[f].Y == pos[s].Y){ //Same Col
        cost = 1;
        int start = min(f, s) + 3;
        int end = max(f, s);
        while(start < end) {
            if(!valid[start] || !(mask & (1<<start))) return -1;
            ++cost;
            start += 3;
        }
    }else if(abs(pos[f].X - pos[s].X) == 2 && abs(pos[f].Y - pos[s].Y) == 2){ //Diagonal
        int mid = (f + s) / 2;
        if(!valid[mid] || !( mask & (1<<mid) )) return -1;
        cost = 4;
    }else{
        cost = abs(pos[f].X - pos[s].X) + abs(pos[f].Y - pos[s].Y);
    }
    return cost;
}

int solve(int mask, int rem, int prev){
    if(rem < 0) return 0;
    if(rem == 0){
        if(popCnt[mask] <= 1){
            return 0;
        }
        return 1;
    }
    
    if(dp[mask][rem][prev] != -1) return dp[mask][rem][prev];
    int ret = 0;
    
    for(int i = 0; i < 12; i++){
        int nmask = mask;
        if(valid[i] && !(mask & (1<<i))){
            int cost = calcCost(nmask, prev, i);
            if(cost < 1) {
                /**
                for(int j = 0; j < 12; j++){
                    if(mask & (1<<j)){
                        cout << "C " << j / 3 << " " << j % 3 << endl; 
                    }
                }
                cout << prev << " " << i << endl;**/
                continue;
            }
            ret += solve(nmask | (1<<i) , rem - cost, i);
        }
    }
    
    return dp[mask][rem][prev] = ret;
    
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    
    for(int i = 0, to = 1<<13; i < to; i++){
        popCnt[i] = __builtin_popcount(i);
    }
    
    for(int i = 0; i < 12; i++){
        pos[i].X = i / 3;
        pos[i].Y = i % 3;
    }
    
    memset(valid, true, sizeof valid);
    /**
    valid[0] = false;
    int m = 0, f = 8, s = 0;
    cout << calcCost(m, f, s);
    
    return 0;**/
    int t;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &L, &N);
        memset(valid, true, sizeof valid);
        for(int i = 0; i < N; i++){
            scanf("%d %d", &y, &x);
            --x, --y; 
            valid[ (x*3) + y] = false;
        }
        if(L > 40){
            printf("BAD MEMORY\n");
            continue;
        }
        memset(dp, -1, sizeof dp);
        
        int tot = 0;
        for(int i = 0; i < 12; i++){
            if(valid[i]){
                tot += solve((1<<i), L, i);
            }
        }
        
        if(tot == 0){
            printf("BAD MEMORY\n");
        }else{
            printf("%d\n", tot);
        }
    }
    
    
    return 0;
}