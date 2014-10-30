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


int main(){
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    
    
    string s, t;
    
    while(cin >> s >> t){
        int c = 0;
        for(int i = 0; i < t.size() && c < s.size(); i++){
            if(t[i] == s[c]) c++;
        }
        cout << (c == s.size() ? "Yes" : "No") << endl;
    }
    

    return 0;
}