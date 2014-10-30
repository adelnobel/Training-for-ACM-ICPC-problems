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

typedef long long ll;
typedef pair<int, int> pi;

/**

We want to find the longest DECREASING subsequence on the heights, 
and this LIS function finds the longest INCREASING, so we just negate all heights
and find the longest INCREASING subsequence :D :D

**/

bool cmp(const pi &a, const pi & b){
    if(a.first != b.first) return a.first < b.first;
    return a.second > b.second;
}
vector< pi > v;

typedef vector<int> VI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;

//#define STRICTLY_INCREASNG

VI LongestIncreasingSubsequence(VI v) {
  VPII best;
  VI dad(v.size(), -1);
  
  for (int i = 0; i < v.size(); i++) {
#ifdef STRICTLY_INCREASNG
    PII item = make_pair(v[i], 0);
    VPII::iterator it = lower_bound(best.begin(), best.end(), item);
    item.second = i;
#else
    PII item = make_pair(v[i], i);
    VPII::iterator it = upper_bound(best.begin(), best.end(), item);
#endif
    if (it == best.end()) {
      dad[i] = (best.size() == 0 ? -1 : best.back().second);
      best.push_back(item);
    } else {
      dad[i] = dad[it->second];
      *it = item;
    }
  }
  
  VI ret;
  for (int i = best.back().second; i >= 0; i = dad[i])
    ret.push_back(v[i]);
  reverse(ret.begin(), ret.end());
  return ret;
}


int main(){
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    
    int T, n, x, y;
    scanf("%d", &T);
    
    while(T--){
        v.clear();
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            scanf("%d %d", &x, &y);
            v.push_back(pi(x, y));
        }
        sort(v.begin(), v.end(), cmp);
        
        
        vector< int > H;
        for(int i = 0; i < v.size(); i++){
            H.push_back(-v[i].second);
        }
        
        int ans = LongestIncreasingSubsequence(H).size();
        
        cout << ans << endl;
        
    }

    return 0;
}