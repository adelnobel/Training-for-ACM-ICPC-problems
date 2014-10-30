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
    
    int e, f, c,t, tot, res;
    
    scanf("%d", &t);
    
    while(t--){
        scanf("%d %d %d", &e, &f, &c);
        tot = e + f;
        res = 0;
        while(tot >= c){
            res++;
            tot -= c;
            tot++;
        }
        
        printf("%d\n", res);
    }
    
    
    return 0;
}