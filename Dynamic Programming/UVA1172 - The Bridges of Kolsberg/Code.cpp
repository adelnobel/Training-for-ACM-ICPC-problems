#include <cstdlib>
#include <iostream>
#include <vector>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

typedef int ll;
typedef pair<int, int> pi;

vector< pair<string, int> > lef, righ;
char s[20], s1[20];

bool vis[1005][1005];
pi dp[1005][1005];
int l, r;

pi maxi(pi a, pi b){
    if(a.first != b.first) return a.first > b.first ? a : b;
    return a.second < b.second ? a : b;
}

pi solve(int a, int b){
    if(a >= l) return pi(0, 0);
    if(b >= r) return pi(0, 0);
    
    pi &ret = dp[a][b];
    if(vis[a][b]) return ret;
    vis[a][b] = true;
    
    ret = pi(-1, -1);
    pi ll = solve(a+1, b);
    pi rr = solve(a, b+1);
    if(lef[a].first == righ[b].first) {
        ret = solve(a+1, b+1);
        ret.first += lef[a].second + righ[b].second;
        ret.second += 1;
    }

    ret = maxi(ret, maxi(ll, rr));
    
    return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    
    int T, x;
    scanf("%d", &T);
    
    while(T--){
        lef.clear();
        righ.clear();
        scanf("%d", &l);
        for(int i = 0; i < l; i++){
            scanf("%s %s %d", s, s1, &x);
            lef.push_back(make_pair(s1, x));
        }
        scanf("%d", &r);
        for(int i = 0; i < r; i++){
            scanf("%s %s %d", s, s1, &x);
            righ.push_back(make_pair(s1, x));
        }
        memset(vis, false, sizeof vis);
        pi res = solve(0, 0);
        cout << res.first << " " << res.second << endl;
        
        
        
    }
    
    
    return 0;
}