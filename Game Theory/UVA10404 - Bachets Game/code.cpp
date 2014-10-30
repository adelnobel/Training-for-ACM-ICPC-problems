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

int n;

bool state[(int)1e6 + 15];

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    
    int n, m, x;
    
    while(scanf("%d", &n) == 1){
        //memset(state, false, sizeof state);
        scanf("%d", &m);
        vector< int > v;
        for(int i = 0; i < m; i++) {
            scanf("%d", &x);
            v.push_back(x);
        }
        
        state[0] = false;
        for(int i = 1; i <= n; i++){
            bool isWinning = false;
            for(int j = 0; j < v.size(); j++){
                int to = i - v[j];
                if(to < 0) continue;
                isWinning |= !state[to];
                if(isWinning) break;
            }
            state[i] = isWinning;
        }
        
        if(state[n]){
            printf("Stan");
        }else{
            printf("Ollie");
        }
        printf(" wins\n");
        
    }
    

}