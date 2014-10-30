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
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;

char s[200];

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    
    int T, n;
    
    
    scanf("%d", &T);
    
    for(int t = 1; t <= T; t++){
        scanf("%d %s", &n, s);
        int l = strlen(s), res = 0;
        for(int i = 0; i < l; i++){
            if(s[i] == '.'){
                i += 2;
                res++;
            }
        }
        
        printf("Case %d: %d\n", t, res);
    }
    

    return 0;
}