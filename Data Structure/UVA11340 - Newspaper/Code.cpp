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

int vals[260];

int main()
{
    //freopen("in.in", "r", stdin);
    
    int n, c, l, v;
    unsigned char ch, ch2;
    scanf("%d\n", &n);
    
    while(n--)
    {
        scanf("%d%c", &c, &ch);
        memset(vals, 0, sizeof(vals));
        int tot = 0;
        while(c--){
            scanf("%c", &ch);
            scanf("%d%c", &v, &ch2);
            vals[ch] = v;
        }
        
        scanf("%d\n", &l);
        while(l--){
            for(;;)
            {
                scanf("%c", &ch);
                if(ch == 10) break;
                tot += vals[ch];
            }
        }
        printf("%.2f$\n", (tot/100.) );
    }
    
    return 0;
}
