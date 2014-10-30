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

typedef pair<int, int> pi;
typedef long long ll;

const int N = 253;

int arr[N];
int ACC[N];
int dp[N][N];

int solve(int s, int e){
    if(s >= e){
        return 0;
    }
    int& ret = dp[s][e];
    if(ret != -1) return ret;
    ret = 1e9;
    for(int i = s; i <= e; i++){
        ret = min(ret, solve(s, i - 1) + solve(i + 1, e) +
                ACC[i - 1] - ACC[s - 1] + ACC[e] - ACC[i]);
    }

    return ret;
}


int main(){
#ifndef ONLINE_JUDGE
     freopen("in.in", "r", stdin);
#endif
     ios::sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);

     int n;
     while(cin >> n){
        memset(dp, -1, sizeof dp);
        for(int i = 1; i <= n; i++){
            cin >> arr[i];
            ACC[i] = ACC[i - 1] + arr[i];
        }
         cout << solve(1, n) << '\n';
     }



     return 0;
}
