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

int c, n;

int ans[5];

int main()
{
    //freopen("in.in", "r", stdin);
    
    int cc = 1, n, cur;
    
    scanf("%d", &c);
    
    while(c--){
        
        scanf("%d", &n);
        
        int to = sqrt(n) + 1;
        
        cur = 0;
        
        for(int i = 2; i <= to; i++){
            if(n % i == 0){
                if(i != n / i){
                    ans[cur++] = i;
                    ans[cur++] = n/i;
                }
                if(cur == 4) break;
            }
        }
        
        printf("Case #%d: %d = %d * %d = %d * %d\n", cc++, n, ans[0], ans[1], ans[2], ans[3]);
        
    }
    
    return 0;
}