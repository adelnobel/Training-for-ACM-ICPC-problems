
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

/**
lineLineIntersection Function is too buggy!
**/

typedef complex<double> point;

#define EPS 1e-9
#define X real()
#define Y imag()
#define dot(a, b) ((conj(a)*(b)).X)
#define cross(a, b) ((conj(a) * (b)).Y)
#define vec(a, b) ((b)-(a))
#define length(a) (hypot((a).X, (a).Y))
#define normalize(a) ((a)/length(a))

#define getRatio(a, b, p) (length((p)-(a)) / length((b)-(a)))
#define pointFromRatio(a, b, t) ((a) + (t * (b - a)))

point lineLineIntersection(const point& p1, const point& p2, const point& p3, const point& p4)
{
    double D = p4.Y - p3.Y;
    double A = p2.X - p1.X;
    double B = p4.X - p3.X;
    double C = p2.Y - p1.Y;
    
    double numerator = ( (((p3.X - p1.X)) * D / B) + p1.Y - p3.Y );
    double denominator = ( (A * D / B) - C );
    
    point ret;
    
    if(numerator == 0){
        ret.X = 0;
        ret.Y = NAN;
    }else if(denominator == 0){
        ret.X = NAN;
        ret.Y = NAN;
    }else{
        double t = numerator / denominator;
        ret = pointFromRatio(p1, p2, t);
    }
    return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    
    bool flag = false;
    int t, n;
    double x1, y1, x2, y2;
    scanf("%d", &t);
    
    while(t--){
        if(flag) printf("\n");
        else flag = true;
        int totalIntersections = 0;
        scanf("%d", &n);
        vector< pair<point, point> > v;
        for(int i = 0; i < n; i++){
            scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
            v.push_back(make_pair(point(x1, y1), point(x2, y2)));
        }
        for(int i = 0; i < v.size(); i++){
            for(int j = i+1; j < v.size(); j++){
                    point intersectionPoint = lineLineIntersection(v[i].first, v[i].second, v[j].first, v[j].second);
                    if(intersectionPoint.X == 0){
                        //cout << "Collinear!" << endl;
                    }else if(isnan(intersectionPoint.X)){
                        //cout << "Parallel!" << endl;
                    }else{
                        double t = getRatio(v[i].first, v[i].second, intersectionPoint);
                        point fRatio1 = pointFromRatio(v[i].first, v[i].second, t);
                        double s = getRatio(v[j].first, v[j].second, intersectionPoint);
                        point fRatio2 = pointFromRatio(v[j].first, v[j].second, s);
                        if(fRatio1 == fRatio2 && t - EPS > 0 && t + EPS <= 1 && s - EPS > 0 && s + EPS <= 1){
                            totalIntersections++;
                            //cout << intersectionPoint << endl;
                        }
                    }
            }
        }
        printf("%d\n", n + totalIntersections*2);
    }
    
    
    
    return 0;
}