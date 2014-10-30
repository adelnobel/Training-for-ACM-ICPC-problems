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
#include <cassert>


using namespace std;

typedef complex<int> point;

#define X real()
#define Y imag()

#define vec(a, b) ((b)-(a))
#define dot(a, b) (conj(a)*b).X
#define cross(a, b) (conj(a)*b).Y

#define N 305
vector< int > adj[N];
int match[N];
bool vis[N];

int Aug(int l){
    if(vis[l]) return 0;
    vis[l] = true;
    for(int i = 0; i < adj[l].size(); i++){
        int to = adj[l][i];
        if(match[to] == -1 || Aug(match[to])){
            match[to] = l;
            return 1;
        }
    }
    return 0;
}



int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    
    int n, a, b, c, x, y, R, t = 1;
    vector< point > v;
    vector< int > r;
    
    while(scanf("%d", &n), n != 0){
        v.clear();
        r.clear();
        for(int i = 0; i < N; i++) adj[i].clear();
        memset(match, -1, sizeof match);
        for(int i = 0; i < n; i++){
            scanf("%d %d %d", &x, &y, &c);
            v.push_back(point(x, y));
            r.push_back(c);
        }
        scanf("%d %d %d", &a, &b, &R); --a, --b, R *= R;
        point separator = vec(v[a], v[b]);
        vector< int > A, B;
        for(int i = 0; i < n; i++){
            if(r[i] == 0) continue;
            int crs = cross(separator, vec(v[a], v[i]));
            assert(crs != 0);
            if(crs > 0) A.push_back(i);
            else B.push_back(i);
        }

        
        if(B.size() < A.size()) swap(A, B);
        for(int i = 0; i < A.size(); i++){
            for(int j = 0; j < B.size(); j++){
                if(r[A[i]] > r[B[j]]){
                    int dx = v[A[i]].X - v[B[j]].X, dy = v[A[i]].Y - v[B[j]].Y;
                    if(dx*dx + dy*dy <= R){
                        adj[A[i]].push_back(B[j]);
                    }
                }
            }
        }

        int tot = 0;
        for(int i = 0; i < A.size(); i++){
            memset(vis, false, sizeof vis);
            tot += Aug(A[i]);
        }
        
        printf("Case %d: %d\n", t++, tot);
        
        
    }
    
    return 0;
}
