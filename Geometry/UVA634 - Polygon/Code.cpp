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

bool isOnLine(const point& p1Line, const point& p2Line, const point& pToCheck){
    return fabs(cross(vec(p1Line, p2Line), vec(p1Line, pToCheck))) < EPS &&
            fabs(cross(vec(p2Line, p1Line), vec(p2Line, pToCheck))) < EPS;
}

bool isOnRay(const point& rayStart, const point& pOnRay, const point& pToCheck){
    return isOnLine(rayStart, pOnRay, pToCheck) &&
            dot(vec(rayStart, pOnRay), vec(rayStart, pToCheck)) > -EPS; //Greater than or equal to 0 ( >= 0 )
}

bool isOnSegment(const point& p1, const point& p2, const point& pToCheck){
    return isOnRay(p1, p2, pToCheck) && isOnRay(p2, p1, pToCheck);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    
    int n, x, y;
    
    while(scanf("%d", &n), n){
            vector<point> v;
            for(int i = 0; i < n; i++){
                scanf("%d %d", &x, &y);
                v.push_back(point(x, y));
            }
            scanf("%d %d", &x, &y);
            int tot = 0;
            point p(x, y);
            point p1(x-1, y);
            point intersectionPoint;
            for(int i = 0; i < n; i++){
                if(isOnSegment(v[i], v[(i+1)%n], p)){
                    tot++;
                }
                else if((lineLineIntersection(v[i], v[(i+1) % n], p, p1, intersectionPoint) == INTERSECT &&
                    isOnSegment(v[i], v[(i+1) % n], intersectionPoint) && isOnRay(p, p1, intersectionPoint))){
                    if(cmpPoints(intersectionPoint, v[i]) || cmpPoints(intersectionPoint, v[(i+1) % n])){
                        if(fabs(intersectionPoint.Y - max(v[i].Y, v[(i+1) % n].Y)) < EPS){
                            tot++;
                        }
                    }else{
                        tot++;
                    }
                }
            }
            printf( (tot & 1) ? "T\n" : "F\n");
    }
    
    
    
    return 0;
}