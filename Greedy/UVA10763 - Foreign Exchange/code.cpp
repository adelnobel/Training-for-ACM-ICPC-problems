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

map<pair<ll, ll>, int> m;

void add(const ll&a, const ll& b, const int &add){
    pair<ll, ll> p(a, b);
    m[p] += add;
    if(m[p] == 0) m.erase(m.find(p));
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    
    int a, b, n;
    
    while(1){
        
        m.clear();
        scanf("%d", &n);
        if(!n) break;
        for(int i = 0; i < n; i++){
            scanf("%d %d", &a, &b);
            add(a, b, 1);
            add(b, a, -1);
        }
        
        if(m.empty()){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
        
    }
    
    
    return 0;
}