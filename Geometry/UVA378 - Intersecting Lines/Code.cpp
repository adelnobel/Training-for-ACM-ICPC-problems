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
#include <ctime>
#include <complex>

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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    
    int T;
    
    scanf("%d", &T);
    
    printf("INTERSECTING LINES OUTPUT\n");
    
    while(T--){
        point points[4] , inter;
        for(int i = 0; i < 4; i++){
            scanf("%lf %lf", &points[i].X, &points[i].Y);
        }
        STATE ret = lineLineIntersection(points[0], points[1], points[2], points[3], inter);
        if(ret == COLLINEAR){
            printf("LINE\n");
        }else if(ret == PARALLEL){
            printf("NONE\n");
        }else{
            printf("POINT %.2lf %.2lf\n", inter.X, inter.Y);
        }
    }
    printf("END OF OUTPUT\n");
    
    
    return 0;
}
