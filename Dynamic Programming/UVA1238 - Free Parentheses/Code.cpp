#include <vector>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <bitset>
#include <map>
#include <complex>
#include <ctime>
#include <numeric>
#include <set>
#include <cassert>

using namespace std;

typedef struct node{
    int idx, val;
    int open;
    node(){};
    node(int a, int b, int c){
        idx = a, open = b, val = c;
    }
    bool operator<(const node& x) const{
        if(idx != x.idx) return idx < x.idx;
        if(val != x.val) return val < x.val;
        return open < x.open;
    }
};

char s[1005];
char sign[10];
vector< int > v;
vector< bool > si;
set< node > dp;
set< int > ans;

void solve(node x){
    if(dp.count(x) > 0) return;
    if(x.idx == v.size()){
        ans.insert(x.val);
        return;
    }
    dp.insert(x);
    if(si[x.idx]){
        solve(node(x.idx+1, x.open+1, x.val + ((x.open & 1) ? 1 : -1) * abs(v[x.idx]) ));
    }
    if(x.open > 0){
        solve(node(x.idx, x.open-1, x.val ));
    }
    solve(node(x.idx+1, x.open, x.val + ((x.open & 1) ? -1 : 1) * v[x.idx]));
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    
    while(gets(s)){
        v.clear();
        si.clear();
        int tot = 0, c, x, len = strlen(s);
        sscanf(s, "%d%n",&x, &tot);
        v.push_back(x);
        si.push_back(false);
        while(sscanf(s+tot, "%s %d%n", sign, &x, &c) == 2 && tot < len){
            if(sign[0] == '-'){
                v.push_back(-x);
                si.push_back(true);
            }else{
                v.push_back(x);
                si.push_back(false);
            }
            tot += c;
        }
        ans.clear(); dp.clear();
        solve(node(0, 0, 0));
        cout << ans.size() << endl;
        
    }
    
    return 0;
}
