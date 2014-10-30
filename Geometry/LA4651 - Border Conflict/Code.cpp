#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <cmath>
#include <iostream>
#include <bitset>
#include <map>
#include <ctime>
#include <set>
#include <complex>

using namespace std;

typedef long long ll;

typedef complex<ll> point;

#define X real()
#define Y imag()
#define dot(a, b) (conj(a) * b).X
#define cross(a, b) (conj(a) * b).Y
#define vec(a, b) ((b)-(a))

#define EPS 1e-9
const double INF = 10000000;
double dp[105][105];

bool vis[105][105];

point coords[105];

int n, c, C;

double distancee(int p1, int p2){
    double x = fabs(coords[p2].X - coords[p1].X);
    double y = fabs(coords[p2].Y - coords[p1].Y);
    return sqrt(x*x + y*y);
}

bool inRange(int s, int e, int p){
    ll dotVal = cross(vec(coords[s], coords[e]), vec(coords[s], coords[p]));
    if(dotVal < 0) dotVal *= -1;
    double length = sqrt(dot(vec(coords[s], coords[e]), vec(coords[s], coords[e])));
    return ((dotVal / length) - c) < EPS;
}

double solve(int idx, int prev){
    
    if(idx == n){
        if(prev == n-1) return 0.0;
        return INF;
    }
    
    if(vis[idx][prev]) return dp[idx][prev];
    
    dp[idx][prev] = solve(idx + 1, prev);
    
    double take = solve(idx+1, idx) + distancee(idx, prev);
    for(int i = idx-1; i >= prev+1; i--){
        if( !inRange(prev, idx, i) ){
            take = INF;
        }
    }
    
    if(take < dp[idx][prev]) {
        dp[idx][prev] = take;
    }
    vis[idx][prev] = true;
    return dp[idx][prev];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    

    while(1){
        ll a, b;
        scanf("%d %d", &n, &c);
        if(n == 0) break;
        C = c*c;
        
        memset(vis, false, sizeof vis);
        
        for(int i = 0; i < n; i++){
            scanf("%lld %lld", &a, &b);
            coords[i].real(a), coords[i].imag(b);
        }

        double ans = solve(1, 0);
        
        printf("%.2lf\n", ans);
    }
    
    return 0;
}

