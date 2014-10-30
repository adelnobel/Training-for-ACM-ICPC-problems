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

using namespace std;


typedef long long ll;

/**
int dp[N];
int solve(int a){
    if(a == 1) return false;
    int& ret = dp[a];
    if(ret != -1) return ret;
    ret = 0;
    int to = a;
    for(int i = 1; i < to; i++){
        ret |= !solve(max(to-i, i));
    }
    
    return ret;
}**/

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    
    /**
    memset(dp, -1, sizeof dp);
    for(int i = 1; i < N; i++){
        if(solve(i) == 0)
        printf("%d -> %d\n", i, solve(i));
    }**/
    
    unsigned int X;
    
    while(1){
        scanf("%d", &X);
        if(X == 0) break;
        X++;
        if((X & (X-1)) != 0){
            printf("Alice\n");
        }else{
            printf("Bob\n");
        }
    }
    
    

}