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

typedef pair<int, int> pi;
typedef long long ll;

#define EPS 1e-10

vector< pi > fact(int x){
    map<int, int> m;
    for(int i = 2; i*i <= x; i++){
        int cnt = 0;
        while(x % i == 0) x /= i, ++cnt;
        if(cnt) m[i] = cnt;
    }
    if(x > 1) m[x] = 1;
    return vector<pi>(m.begin(), m.end());
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    int n, b;
    
    while(scanf("%d %d", &n, &b) == 2){
        if(n <= 1) {
            printf("0 1\n");
            continue;
        }
        long double ans = 0;
        for(int i = 1; i <= n; i++){
            ans += log10l(i);
        }
        ans /= log10l(b);
        
        vector< pi > v = fact(b);
        int trailing = 1e9;
        for(int i = 0; i < v.size(); i++){
            int tot = 0;
            int x = v[i].first;
            while(x <= n){
                tot += n / x;
                x *= v[i].first;
            }
            trailing = min(trailing, tot / v[i].second);
        }
        /**
        if(ans - floorl(ans) < EPS){
            ans = floorl(ans);
        }else if(ceill(ans) - ans < EPS){
            ans = ceill(ans);
        }**/
        printf("%d %d\n",trailing, (int)(ans + 1) );
    }
    
    return 0;
}
