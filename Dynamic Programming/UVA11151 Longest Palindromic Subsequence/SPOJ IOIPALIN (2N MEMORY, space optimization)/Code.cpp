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

char s[5005];

int dp[2][5005];

int len;

void solve()
{
    for(int left = len-1; left >= 0; left--){
        int ll = left&1;
        for(int right = left; right < len; right++){
            
            if(left > right) continue;
            
            if(left == right){
                dp[ll][right] = 0;
                continue;
            }
            if(1-ll == right){
                if(s[left] == s[right]) dp[ll][right] = 0;
                else dp[ll][right] = 1;
                continue;
            }
            
            if(s[left] == s[right]){
                dp[ll][right] = dp[1-ll][right-1];
            }else{
                dp[ll][right] = 1 + min(dp[ll][right-1], dp[1-ll][right]);
            }
       }
    }
}


int main()
{
    //freopen("in.in", "r", stdin);
    
    scanf("%d", &len);

    scanf("%s", s);

    len = strlen(s);
        
    solve();
        
    printf("%d\n", dp[0][len-1]);
    
    return 0;
}
