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
#include <ctime>
#include <cassert>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pl;
typedef pair<int, int> pi;


int main(){
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T, n;
    ll x;
    vector< ll > v;
    cin >> T;
    while(T--){
        cin >> n;
        v.clear();
        for(int i = 0; i < n ;i++){
            cin >> x;
            v.push_back(x);
        }
        sort(v.begin(), v.end());
        v.push_back(1LL << 60);
        int best = 1;
        ll cur;
        for(int i = 0; i <= 0; i++){
            int total = 1;
            cur = v[i];
            for(int j = i + 1; j + 1 < v.size(); j++){
                if(cur + v[j] < v[j + 1]){
                    total++;
                    cur += v[j];
                }
            }
            best = max(best, total);
        }

        cout << best << '\n';

    }

    return 0;
}
