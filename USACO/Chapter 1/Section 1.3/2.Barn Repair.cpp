/*
ID: adelnob1
PROG: barn1
LANG: C++
*/
#include <vector>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <bitset>
#include <map>
#include <complex>
#include <ctime>
#include <numeric>
#include <set>

using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
    //freopen("in.in", "r", stdin);
    freopen("barn1.in", "r", stdin);
    freopen("barn1.out", "w", stdout);
#endif
    
    int m, s, c, x;
    vector<int> v;
    vector< pair<int, int> > diff;
    cin >> m >> s >> c;
    
    for(int i = 0; i < c; i++){
        cin >> x;
        v.push_back(x); 
    }
    
    sort(v.begin(), v.end());
    
    for(int i = 1; i < v.size(); i++){
        diff.push_back(make_pair(v[i] - v[i-1], i));
    }
    
    int tot = v[v.size() - 1] - v[0] + 1;
    //cout << tot << endl;
    sort(diff.begin(), diff.end(), greater< pair<int, int> >());
    
    for(int i = 0; i < min(m-1, (int)diff.size()); i++){
        //cout << (diff[i].first) << " " << diff[i].second << endl;
        tot -= diff[i].first - 1;
    }
    
    cout << tot << endl;
    
    return 0;
}