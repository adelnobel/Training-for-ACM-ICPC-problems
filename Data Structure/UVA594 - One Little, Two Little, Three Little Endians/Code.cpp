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
    
    unsigned int a, b;
    
    while(scanf("%d", &a) != EOF){
        
        b = 0;
        int mask = (1 << 8) - 1;

        for(int i = 3; i >= 0; i--){
            
            if(i == 3) b |= (mask & a) << 24;
            if(i == 2) b |= (mask & a) << 8;
            if(i == 1) b |= (mask & a) >> 8;
            if(i == 0) b |= (mask & a) >> 24;

            mask <<= 8;
        }
        
        printf("%d converts to %d\n", (signed int)a, (signed int)b);
    }
    
    return 0;
}
