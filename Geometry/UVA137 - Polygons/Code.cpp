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


typedef complex<double> point;

#define EPS 1e-5
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


enum STATE{
    PARALLEL, COLLINEAR, INTERSECT
};

STATE lineLineIntersection(const point& p1, const point& p2, const point& p3, const point& p4, point& intersectionPoint)
{
    double D = p4.Y - p3.Y;
    double A = p2.X - p1.X;
    double B = p4.X - p3.X;
    double C = p2.Y - p1.Y;
    
    double numerator = (( ((p3.X - p1.X)) * D) + ((p1.Y - p3.Y) * B) ) ;
    double denominator = ( (A * D) - (C * B) );

    STATE ret;
    
    if(fabs(denominator) < EPS){
        if(fabs(numerator) < EPS){
            ret = COLLINEAR;
        }else{
            ret = PARALLEL;
        }
    }else{
        double t = numerator / denominator;
        intersectionPoint = pointFromRatio(p1, p2, t);
        ret = INTERSECT;
    }
    return ret;
}

vector<point> polyCut(const vector<point> &poly, const point &p1, const point &p2){
    vector<point> ret;
    for(int i = 0; i < poly.size(); i++){
        double c1 = cross(vec(p1, p2), vec(p1, poly[i]));
        double c2 = cross(vec(p1, p2), vec(p1, poly[(i+1)%poly.size()]));
        if(c1 < -EPS || c2 < -EPS){
            point pnt;
            STATE l = lineLineIntersection(p1, p2, poly[i], poly[(i+1)%poly.size()], pnt);
            
            if(c1 < -EPS) ret.push_back(poly[i]);
            if(l == INTERSECT) ret.push_back(pnt);
        }
    }
    return ret;
}

double tri(const vector<point>& v){
    double tot = 0.0;
    for(int i = 1; i + 1 < v.size(); i++){
        tot += cross(vec(v[0], v[i]), vec(v[0], v[i+1]));
    }
    
    return abs(tot / 2.);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    
    int x, y, a, b;
    
    while(1){
        scanf("%d", &a);
        if(a == 0) break;
        vector<point> p1, p2, world;
        for(int i = 0; i < a; i++){
            scanf("%d%d", &x, &y);
            p1.push_back(point(x, y));
        }
        scanf("%d", &b);
        for(int i = 0; i < b; i++){
            scanf("%d%d", &x, &y);
            p2.push_back(point(x, y));
        }
        world.push_back(point(-1000, -1000));
        world.push_back(point(1000, -1000));
        world.push_back(point(1000, 1000));
        world.push_back(point(-1000, 1000));
        
        for(int i = 0; i < p1.size(); i++){
            world = polyCut(world, p1[i], p1[(i+1)%p1.size()]);
        }
        for(int i = 0; i < p2.size(); i++){
            world = polyCut(world, p2[i], p2[(i+1)%p2.size()]);
        }

        
        printf("%8.2lf", (tri(p1) + tri(p2)) - (2 * tri(world)));
    }
    printf("\n");
    
    
    return 0;
}