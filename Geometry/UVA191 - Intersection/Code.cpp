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
    
    int t, n;
    int x1, y1, x2, y2, xL, yT, xR, yB;
    scanf("%d", &t);
    
    while(t--){
        scanf("%d %d %d %d %d %d %d %d", &x1, &y1, &x2, &y2, &xL, &yT, &xR, &yB);
        if(xL > xR) swap(xL, xR);
        if(yB > yT) swap(yB, yT);
        point p1(x1, y1), p2(x2, y2);
        bool ans = false;
        point intersectionPoint;
        vector<point> v;
        v.push_back(point(xL, yT));
        v.push_back(point(xL, yB));
        v.push_back(point(xR, yB));
        v.push_back(point(xR, yT));
        for(int i = 0; i < 4; i++){
            ans = ans || (lineLineIntersection(p1, p2, v[i], v[(i+1)%4], intersectionPoint) == INTERSECT && 
                        isOnSegment(v[i], v[(i+1)%4], intersectionPoint)) && isOnSegment(p1, p2, intersectionPoint); 
        }
        ans = ans || (p1.X >= min(xL, xR) && p1.X <= max(xL, xR) && p1.Y >= min(yT, yB) && p1.Y <= max(yT, yB));
        ans = ans || (p2.X >= min(xL, xR) && p2.X <= max(xL, xR) && p2.Y >= min(yT, yB) && p2.Y <= max(yT, yB));
        
        printf(ans ? "T" : "F");
        printf("\n");
        
    }
    
    
    
    return 0;
}