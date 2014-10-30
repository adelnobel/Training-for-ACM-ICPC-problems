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

#define EPS 1e-10

int N;
int c, n;

double dp[1<<10][11], avg;
bool vis[1<<10][11];
int items[11];

double solve(int mask, int rem){
    if(rem < 0) return 1e8;
    if(mask == 0){
        if(rem == 0) return 0;
        return 1e8;
    }
    
    double &ret = dp[mask][rem];
    if(vis[mask][rem]) return ret;
    ret = 1e8;
    vis[mask][rem] = true;
    for(int i = 0; i < n; i++){
        if(!(mask & (1<<i))) continue;
        //cout << mask << " -> " << (mask ^ (1<<i)) << endl;
        
        ret = min(ret, solve(mask ^ (1<<i), rem-1) + fabs((double)items[i] - avg));
        for(int j = i+1; j < n; j++){
            if(!(mask & (1<<j))) continue;
            ret = min(ret, solve(mask ^ (1<<i) ^ (1<<j), rem-1) + fabs(items[i] + items[j] - avg));
            //cout << mask << " -> " << (mask ^ (1<<i) ^ (1<<j)) << endl;
        }
    }
    return ret;
}
int assi[11];

void bk(int mask, int rem, int cur){
    if(rem < 0) return;
    if(mask == 0){
        return ;
    }
    
    double &ret = dp[mask][rem];
    for(int i = 0; i < n; i++){
        if(!(mask & (1<<i))) continue;
        double ans = solve(mask ^ (1<<i), rem-1) + fabs((double)items[i] - avg);
        if(fabs(ans - ret) < EPS){
            assi[i] = cur;
            return bk(mask ^ (1<<i), rem-1, cur+1);
        }
        for(int j = i+1; j < n; j++){
            if(!(mask & (1<<j))) continue;
            double ans = solve(mask ^ (1<<i) ^ (1<<j), rem-1) + fabs(items[i] + items[j] - avg);
            if(fabs( ans - ret ) < EPS){
                assi[i] = assi[j] = cur;
                return bk(mask ^ (1<<i) ^ (1<<j), rem-1, cur+1);
            }
        }
    }
    return;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif

    int t= 1;
    
    while(scanf("%d %d", &c, &n) == 2){
        memset(vis, false, sizeof vis);
        assert(n <= 10);
        int tot = 0;
        for(int i = 0; i < n; i++){
            scanf("%d", &items[i]);
            tot += items[i];
        }
        avg = (double)tot / c;
        double best = 1e8;
        int taken;
        for(int i = 1; i <= c; i++){
            //memset(vis, false, sizeof vis);
            //N = i;
            double X = solve((1 << n) - 1, i) + ((c-i) * avg);
            if(X < best){
                bk((1 << n) - 1, i, 0);
                best = X;
                taken = i;
            }
        }
        
        printf("Set #%d\n", t++);
        for(int i = 0; i < c; i++){
            printf(" %d:", i);
            for(int j = 0; j < n; j++){
                if(assi[j] == i){
                    printf(" %d", items[j]);
                }
            }
            printf("\n");
        }
        
        printf("IMBALANCE = %.5lf\n\n", best);
        
    }
    
    
    return 0;
}