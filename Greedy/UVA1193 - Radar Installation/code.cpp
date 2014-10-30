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

#define EPS 1e-7

bool vis[1006];
int opened[1006];

typedef struct node{
    double x;
    int pos;
    bool isEnd;
    node(){};
    node(double a, int b, bool c){
        x = a, pos = b, isEnd = c;
    }
    bool operator<(const node& a) const{
        if(fabs(x - a.x) > EPS) return x < a.x;
        if(isEnd != a.isEnd) return isEnd < a.isEnd;
        return pos < a.pos;
    }
};

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif

    int t = 1, n, x, y;
    ll d;
    
    while(1){
        cin >> n >> d;
        if(!n && !d) break;
        bool ok = true;
        vector< pair<int, int> > v;
        for(int i = 0; i < n; i++){
            scanf("%d %d", &x, &y);
            v.push_back(make_pair(x, y));
            if(abs(y) > d) ok = false;
        }
        
        printf("Case %d:", t++);
        if(!ok){
            printf(" -1\n");
            continue;
        }
        
        vector< node > pnts;
        for(int i = 0; i < v.size(); i++){
            double add = sqrt((double)d*d - (double)v[i].second*v[i].second);
            pnts.push_back(node(v[i].first - add, i, 0));
            pnts.push_back(node(v[i].first + add, i, 1));
            //cout << v[i].first - add << endl << v[i].first + add << endl; 
        }
        
        memset(vis, false, sizeof vis);
        sort(pnts.begin(), pnts.end());
        
        int tot = 0, res = 0;
        for(int i = 0; i < pnts.size(); i++){
            if(vis[pnts[i].pos]) continue;
            //cout << pnts[i].isEnd << " " << pnts[i].pos << endl;
            if(!pnts[i].isEnd){
                opened[tot++] = pnts[i].pos;
            }else{
                res++;
                for(int j = 0; j < tot; j++){
                    vis[opened[j]] = true;
                }
                tot = 0;
            }
        }
        
        printf(" %d\n", res);
        
    }
    
    
    return 0;
}