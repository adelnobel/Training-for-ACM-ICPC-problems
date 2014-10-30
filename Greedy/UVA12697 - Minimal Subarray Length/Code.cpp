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
#include <cassert>

using namespace std;

typedef long long ll;
typedef pair<ll, int> pi;


#define N 500005

ll ACC[N];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    
    int t, n, X, a;
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &n, &X);
        int besti = 1e9;
        for(int i = 1; i <= n; i++){
            scanf("%d", &a);
            ACC[i] = ACC[i-1] + a;
        }
        priority_queue< pi, vector<pi>, greater<pi> > pq;
        pq.push(pi(ACC[0], 0));
        for(int i = 1; i <= n; i++){
            while(!pq.empty() && ACC[i] - pq.top().first >= X ){
                besti = min(besti, i - pq.top().second);
                pq.pop();
            }
            pq.push(pi(ACC[i], i));
        }
        printf("%d\n", besti > n ? -1 : besti);
    }
    

    
    return 0;
}
