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

int main()
{
    //freopen("in.in", "r", stdin);
    
    int t, c, a, n, q, b, w = 1;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        c = 0;
        a = (n / 2) + 1;
        
        for(int i = 0; i < n; i++){
            scanf("%d", &q);
            c++;
            if(c == a)
                b = q;
        }
        
        printf("Case %d: %d\n", w++, b);
        
    }
    
    return 0;
}