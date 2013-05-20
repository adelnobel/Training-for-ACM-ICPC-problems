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

typedef pair<double, double> pd;

map<string, pd> m;

char s[2005], t[2005];
string ss;
double x, e;

bool cmp(const pair<double, string > &a, const pair<double, string > &b){
    if(a.first != b.first) return a.first > b.first;
    return a.second < b.second;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    
    int n;
    
    while(scanf("%d", &n) , n){
        m.clear();
        for(int i = 0, to = 2*n; i < to; i++){
            scanf("%s %s", t, s);
            ss = s;
            scanf("%lf %lf", &x, &e);
            if(m.count(ss) == 0) m[ss].first = m[ss].second = 0.0;
            m[ss].first += x;
            m[ss].second += e;
        }
        
        vector< pair<double, string > > v;
        
        map<string, pd>::iterator it;
        for(it = m.begin(); it != m.end(); it++){
            v.push_back(make_pair(1.0 - (it->second.second / it->second.first), it->first ));
        }
        
        sort(v.begin(), v.end(), cmp);
        
        //for(int i = 0; i < v.size(); i++){
            //cout << v[i].second << " " << (((int)(v[i].first * 1000)) / 10.) << "%" << endl;
            printf("%s %.1lf%%\n", v[0].second.c_str(), (v[0].first*100) );
        //}
    }
    
   
    return 0;
}