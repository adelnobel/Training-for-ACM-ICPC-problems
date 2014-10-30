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

const int N = 1 << 17;
ll dp[N][18][2];
int bitscnt[N];
int k, n;

ll solve(int mask, int mismatches, bool correct){
	if(correct && mismatches > 0) return 0;
	if(mismatches < 0) mismatches = 0;
	assert(mask < (N));
	int cur = bitscnt[mask];
	if(cur == n){
		return mismatches <= 0;
	}
	ll& ret = dp[mask][mismatches][correct];
	if(ret != -1) {
		return ret;
	}
	ret = 0;
	for(int i = 0; i < n; i++){
		if(!((bool)(mask & (1 << i)))){
			ret += solve(mask | (1 << i), mismatches - (i != cur), i == cur);
		}
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

    for(int i = 0; i < N; i++){
    	bitscnt[i] = __builtin_popcount(i);
    }

    int T, tt;
    cin >> T;

    while(T--){
    	memset(dp, -1, sizeof dp);
    	cin >> tt >> n >> k;
    	cout << tt << " " << solve(0, k, false) << "\n";
    }



    return 0;
}
