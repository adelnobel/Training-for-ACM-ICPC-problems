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

/**
 LCS DP
 */

int a[101], b[101];

short memo[101][101];

#define INF 10000

short solve(int idx1,int idx2){
    if(idx1 < 0 || idx2 < 0 ){
        return 0;
    }
    if(memo[idx1][idx2] != -1) return memo[idx1][idx2];
    short ret;
    if(a[idx1] == b[idx2]){
        ret = 1 + solve(idx1-1, idx2-1);
    }else{
        ret = max(solve(idx1-1, idx2), solve(idx1, idx2-1));
    }
    
    return memo[idx1][idx2] = ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    
    int n1, n2, cc = 1;
    
    while(scanf("%d %d", &n1, &n2), n1 && n2){
        memset(memo, -1, sizeof(memo));
        for(int i = 0; i < n1; i++){
            scanf("%d", &a[i]);
        }

        for(int i = 0; i < n2; i++){
            scanf("%d", &b[i]);
        }
        
        printf("Twin Towers #%d\nNumber of Tiles : %d\n\n", cc++, (int)solve(n1-1, n2-1));
    }
    

    return 0;
}