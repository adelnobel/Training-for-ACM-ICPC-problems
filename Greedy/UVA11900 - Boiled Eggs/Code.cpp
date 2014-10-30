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


int main(){
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif

    
    int T, n, P, Q, x, t = 1;
    scanf("%d", &T);
    while(T--){
        scanf("%d %d %d", &n, &P, &Q);
        vector< int > v;
        for(int i = 0; i < n; i++){
            scanf("%d", &x);
            v.push_back(x);
        }
        
        sort(v.begin(), v.end());
        
        int totQ = 0, res = 0;
        
        for(int i = 0; i < min((int)v.size(), P); i++){
            if(totQ + v[i] > Q) break;
            totQ += v[i];
            res++;
        }
        
        printf("Case %d: %d\n", t++, res);
        
    }
    

    return 0;
}