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

const int N = 1e6 + 20;

typedef pair<int, int> pi;
typedef long long ll;

set < pi > S;

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T, a, b, c, tt, n;

    cin >> T;

    while(T--){
    	S.clear();
    	cin >> tt >> n;
    	S.insert(pi(1, 1));
    	a = 1;
    	b = 2 % n;
    	int len = 1;
    	while(S.count(pi(a, b)) == 0){
    		S.insert(pi(a, b));
    		c = a + b;
    		a = b;
    		b = c;
    		if(a >= n) a %= n;
    		if(b >= n) b %= n;
    		len++;
    	}
    	cout << tt << " " << len << "\n";
    }



    return 0;
}
