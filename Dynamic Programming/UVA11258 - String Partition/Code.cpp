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

int n, len;

char s[210];

ll memo[210];

ll solve(int idx)
{
    if(idx == len){
        return 0;
    }
    
    if(memo[idx] != -1){
        return memo[idx];
    }
    
    if(s[idx] == '0'){
        return memo[idx] = solve(idx+1);
    }
    
    int cur = s[idx] - '0', temp = 0;
    
    ll overFlow;
    
    ll maxi = cur;
    
    
    for(int i = idx+1; i < len; i++){
        maxi = max(maxi, ((ll)cur) + solve(i));
        temp = (cur * 10) + s[i] - '0';
        overFlow = ((ll)cur * 10) + s[i] - '0';
        if(temp != overFlow){
            return memo[idx] = maxi;
        }
        cur = temp;
        maxi = max(maxi, (ll)cur);
    }
    
    return memo[idx] = maxi;
    
}


int main()
{
    //freopen("in.in", "r", stdin);
    
    scanf("%d", &n);
    
    while(n--){
        memset(memo, -1, sizeof memo);
        scanf("%s", s);
        len = strlen(s);
        
        printf("%lld\n", solve(0));
    }
    
    
    
    return 0;
}