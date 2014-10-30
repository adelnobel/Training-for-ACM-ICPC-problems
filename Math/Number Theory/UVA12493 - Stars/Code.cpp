#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <functional>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
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
typedef pair<ll, ll> pl;
typedef double ld;

const int N = 1e4 + 5;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    //freopen("out1.in", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string line, word;

    int N, x;
    while(cin >> N){
        int totient = 1;
        for(int i = 2; 1ll * i*i <= N; i++){
            int t = 1;
            while(N % i == 0){
                t *= i;
                N /= i;
            }
            totient *= t - t / i;
        }
        if(N > 1) totient *= N - 1;
        cout << totient / 2 + (totient & 1) << '\n';
    }

    return 0;
}
