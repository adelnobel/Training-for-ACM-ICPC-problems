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
#include <numeric>
#include <set>
#include <ctime>

using namespace std;


typedef long long ll;

#define N 1010
#define INF (int)(1e9 * 2)

int arr[N], acc[N];

int t, n, a;

int solve(int prev, int idx){
    if(idx == n+1){
         return acc[n] - acc[prev-1];
    }

    int prevSum = acc[idx-1] - acc[prev-1];
    int pos = (int) (lower_bound(acc+idx, acc+n, acc[idx-1] + prevSum) - acc);
    if(acc[pos] != acc[idx-1] + prevSum){
        return INF;
    }
    
    return solve(idx, pos+1);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    
    scanf("%d", &t);
    
    while(t--){
        
        scanf("%d %d", &a, &n);
        for(int i = 1; i <= n; i++){
            scanf("%d", &arr[i]);
            acc[i] = acc[i-1] + arr[i];
        }
        int mini = INF;
        for(int i = 1; i <= n; i++){
            mini = min(mini, solve(1, i+1));
        }
        printf("%d %d\n", a, mini);
    }
    
    return 0;
}
