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
    
    int e, c, tot, res;
    

    
    while(1){
        scanf("%d", &e);
        if(e == 0) break;
        tot = e;
        res = 0;
        while(tot >= 3)
        {
            tot -= 3;
            tot++;
            res++;
        }
        
        if(tot == 2)
            res++;
        
        printf("%d\n", res);
    }
    
    
    return 0;
}