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
    
    int t, N, K , P, c = 1;
    
    scanf("%d", &t);
    
    while(t--){
        
        scanf("%d %d %d", &N, &K, &P);
        int res = (K + P) % N;
        
        printf("Case %d: %d\n", c++, res == 0 ? N : res);
    }
    

    return 0;
}