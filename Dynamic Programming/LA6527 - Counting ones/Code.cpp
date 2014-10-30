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
#include <tr1/unordered_set>
#include <tr1/unordered_map>

using namespace std;
using namespace tr1;

typedef long long ll;
typedef long double ld;

typedef pair<ll, ll> pi;

enum state{
    _less,
    _equal,
    _greater
};

ll mask;

state getState(int idx, state old, int val){
    if(old == _less) return _less;
    if(old == _greater) return _greater;
    int bit = (bool)((1LL << idx) & mask);
    if(val > bit) return _greater;
    if(val < bit) return _less;
    return _equal;
}

bool vis[64][3];

pi dp[64][3];

pi solve(int idx, state s){
    if(s == _greater) return pi(0, 0);
    if(idx == -1) return pi(0, 1);
    pi& ret = dp[idx][s];
    if(vis[idx][s]) return ret;
    vis[idx][s] = true;
    ret = pi(0, 0);
    pi a = solve(idx - 1, getState(idx, s, 1));
    ret.first += a.first + a.second;
    pi b = solve(idx - 1, getState(idx, s, 0));
    ret.first += b.first;
    ret.second = a.second + b.second;
    return ret;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll a, b;
    while(cin >> a >> b){
        memset(vis, 0, sizeof vis);
        mask = b;
        ll h = solve(62, _equal).first;
        memset(vis, 0, sizeof vis);
        mask = a - 1;
        ll l = solve(62, _equal).first;

        cout << h - l << '\n';
    }

    return 0;
}
