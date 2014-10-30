#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <ctime>

using namespace std;

typedef pair<int, int> pi;

int t, total, n, sum;
int taken[105];
vector<pi> v;

void solve(int rem, int to){
    if(rem == 0) return;
    int take = max(rem / to, 1);
    for(int i = 0; i < to; i++){
        take = min(take, v[i].first - taken[n - v[i].second - 1]);
    }
    int cntr = 0;
    for(int i = 0; i < to; ++i){
        taken[n - v[i].second - 1] += take;
        rem -= take;
        if(rem == 0) return;
        if(taken[n - v[i].second - 1] < v[i].first) cntr++;
    }
    return solve(rem, cntr);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    
    
    scanf("%d", &t);
    
    while(t--){
        v.clear();
        memset(taken, 0, sizeof taken);
        sum = 0;
        scanf("%d %d", &total, &n);
        for(int i = 0; i < n; i++){
            pi p;
            scanf("%d", &p.first);
            sum += p.first;
            p.second = n - i - 1;
            v.push_back(p);
        }
        sort(v.begin(), v.end(), greater<pi>());
        if(sum < total){
            printf("IMPOSSIBLE\n");
            continue;
        }else{
            solve(total, n);
        }
        printf("%d", taken[0]);
        for(int i = 1; i < n; i++){
            printf(" %d", taken[i]);
        }
        printf("\n");
    }
    
    
   
    return 0;
}