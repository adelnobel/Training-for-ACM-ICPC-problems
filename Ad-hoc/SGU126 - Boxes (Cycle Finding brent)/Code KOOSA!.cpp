#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
#include <set>
#include <cassert>
#include <ctime>
#include <bitset>

using namespace std;

typedef long long ll;

set< pair<int, int> > S;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    
    int a, b, c = 0;
    
    cin >> a >> b;
    if(a == 0 || b == 0) {
        cout << 0 << endl;
        return 0;
    }
    if(a > b) swap(a, b);
    
    int tot = 25000000;
    
    while(b > a && tot > 0){
        b -= a;
        a *= 2;
        c++;
        if(a == b) break;
        if(a > b) swap(a, b);
        --tot;
    }
    
    if(a == b) cout << c + 1 << endl;
    else cout << -1 << endl;
    //cout << bfs(a, b, c) << endl;

    
    return 0;
}