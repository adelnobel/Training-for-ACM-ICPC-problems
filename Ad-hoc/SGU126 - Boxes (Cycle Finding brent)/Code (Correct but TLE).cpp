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

inline pair<int, int> fun(const pair<int, int> &p){
    int a = p.first, b = p.second;
    b -= a;
    a *= 2;
    if(a > b) swap(a, b);
    return make_pair(a, b);
}

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
    
    pair<int, int> tortoise = make_pair(a, b), hare = fun(tortoise);
    int currentPower = 1;
    int lambda = 1;
    
    while(tortoise != hare){
        c++;
        if(hare.first == hare.second) break;
        if(lambda == currentPower){
            currentPower <<= 1;
            lambda = 0;
            tortoise = hare;
        }
        hare = fun(hare);
        lambda++;
    }
    a = hare.first, b = hare.second;
    if(a == b) cout << c + 1 << endl;
    else cout << -1 << endl;
    //cout << bfs(a, b, c) << endl;

    
    return 0;
}