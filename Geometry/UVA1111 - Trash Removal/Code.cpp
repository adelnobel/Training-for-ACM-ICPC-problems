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

using namespace std;


typedef complex<double> point;

#define EPS 1e-9
#define X real()
#define Y imag()
#define dot(a, b) ((conj(a)*(b)).X)
#define cross(a, b) ((conj(a) * (b)).Y)
#define vec(a, b) ((b)-(a))
#define length(a) (hypot((a).X, (a).Y))
#define normalize(a) ((a)/length(a))
#define proj(p, a, b) ((dot(vec(a, p), vec(a, b))) / (dot(vec(a, b), vec(a, b))))
#define rotate(p, theta) ((p) * exp(point(0, theta)))
#define rotate_about(p, about, theta) rotate((p)-(about), theta) + (about)

#define getRatio(a, b, p) (length((p)-(a)) / length((b)-(a)))
#define pointFromRatio(a, b, t) ((a) + ((t) * vec(a, b)))
#define cmpPoints(p1, p2) ( (fabs(p1.X - p2.X) < EPS) && (fabs(p1.Y - p2.Y) < EPS))

const double PI2 = 4 * acos(0.0);
const double angle = 1. / 100;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    
    int n, cc = 1, x, y;
    
    while(scanf("%d", &n) && n){
        vector<point> v;
        for(int i = 0; i < n; i++){
            scanf("%d %d", &x, &y);
            v.push_back(point(x, y));
        }
        double ans = 1 << 29;
        for(int i = 0; i < v.size(); i++){
            for(int j = i+1; j < v.size(); j++){
                double rotationAngle = acos(0.0) - atan2(v[i].Y - v[j].Y, v[i].X - v[j].X);
                double minX = 1 << 29, maxX = -minX;
                for(int k = 0; k < v.size(); k++){
                    v[k] = rotate(v[k], rotationAngle);
                    minX = min(minX, v[k].X);
                    maxX = max(maxX, v[k].X);
                }
                ans = min(ans, maxX - minX);
            }
        }
        
        printf("Case %d: %.2lf\n", cc++, ans);
    }
    
    
    
    return 0;
}