#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <ctime>

using namespace std;

typedef pair<int, int> pi;

vector<pi> v;
int n, m, a , b , c, d;

bool fun(const pi &p){
    return ((a >= p.first && a < (p.first + p.second)) || ((a+b-1) >= p.first && (a+b-1) < (p.first + p.second)))
            ||
           ( (p.first >= a && p.first < (a+b)) || ( (p.first + p.second - 1) >= a && (p.first + p.second - 1) < (a+b)));
            ;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    
    
    
    while(1){
        scanf("%d %d", &n, &m);
        if(n == 0 && m == 0) break;
        v.clear();
        for(int i = 0; i < n; i++){
            scanf("%d %d %d %d", &a, &b, &c, &d);
            v.push_back(make_pair(c, d));
        }
        
        for(int i = 0; i < m; i++){
            scanf("%d %d", &a , &b);
            int cnt = count_if(v.begin(), v.end(), fun);
            cout << cnt << endl;
        }
        
    }
    return 0;
}