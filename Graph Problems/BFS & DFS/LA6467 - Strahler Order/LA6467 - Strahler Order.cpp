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

const int N = 1005;

typedef pair<int, int> pi;
typedef long long ll;

vector< int > adj[N];
int deg[N];
int order_[N], count_[N];

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T, n, m, a, b, tt;

    cin >> T;

    while(T--){
    	memset(deg, 0, sizeof deg);
    	memset(count_, 0, sizeof count_);
    	memset(order_, 0, sizeof order_);
    	cin >> tt >> n >> m;
    	for(int i = 0; i < m; i++){
    		cin >> a >> b;
    		adj[a].push_back(b);
    		deg[b]++;
    	}
    	int maxi = 1;
    	queue < int > q;
    	for(int i = 1; i <= n; i++){
    		if(deg[i] == 0){
    			q.push(i);
    			order_[i] = 1;
    		}
    	}
    	assert(q.size() != 0);
    	while(!q.empty()){
    		int cur = q.front(); q.pop();
    		if(count_[cur] > 1) order_[cur]++;
    		maxi = max(maxi, order_[cur]);
    		for(int i = 0; i < adj[cur].size(); i++){
    			int to = adj[cur][i];
    			if(order_[cur] > order_[to]){
    				order_[to] = order_[cur];
    				count_[to] = 1;
    			}else if(order_[cur] == order_[to]){
    				count_[to]++;
    			}
    			deg[to]--;
    			if(deg[to] == 0) q.push(to);
    		}
    	}
    	for(int i = 0; i <= n; i++) adj[i].clear();
    	cout << tt << " " << maxi << "\n";
    }



    return 0;
}
