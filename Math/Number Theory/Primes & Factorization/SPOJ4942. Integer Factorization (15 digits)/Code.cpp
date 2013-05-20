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
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <limits>
#include <tr1/unordered_map>
 
using namespace std;

typedef long long ll;

pair<ll, int> ans[100];

int main()
{
    //freopen("in.in", "r", stdin);
    ll n;
    while(1)
    {
        scanf("%lld", &n);
        if(n == 0) break;
        ll to = sqrt(n) + 1;
        int cur = 0;
        int c = 0;
        for(ll i = 2; i < to; i++){
            c = 0;
            while(n % i == 0){
                n /= i;
                to = sqrt(n) + 1;
                c++;
            }
            if(c > 0){
                ans[cur].first = i;
                ans[cur].second = c;
                cur++;
            }
        }
        
        if(n > 1){
            ans[cur].first = n;
            ans[cur].second = 1;
            cur++;
        }
        
        printf("%lld^%d", ans[0].first, ans[0].second);
        
        for(int i = 1; i < cur; i++){
            printf(" %lld^%d", ans[i].first, ans[i].second);
        }
        printf("\n");
    }
    
    return 0;
}

