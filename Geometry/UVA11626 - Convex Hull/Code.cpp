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

typedef long long ll; 

typedef complex<int> point;

#define EPS 1e-4
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

const double PI = 2 * acos(0.0);

char s[5];
int x, y;

point pivot;
double leastAngle;

double angleWithPivot(const point& p1){
    return atan2(p1.Y - pivot.Y, p1.X - pivot.X);
}

void initMinimalAngle(const vector<point>& v){
    leastAngle = 1 << 30;
    for(int i = 1; i < v.size(); i++){
        leastAngle = min(leastAngle, angleWithPivot(v[i]));
    }
}

bool cmp(const point& p1, const point& p2){
    if(p1.X != p2.X){
        return p1.X < p2.X;
    }
    return p1.Y < p2.Y;
}

bool putCloserFirst(const point& p1, const point& p2){
    return length(vec(pivot, p1)) < length(vec(pivot, p2));
}
bool putFartherFirst(const point& p1, const point& p2){
    return length(vec(pivot, p1)) > length(vec(pivot, p2));
}

bool pivotCmp(const point& p1, const point& p2){
    double a1 = angleWithPivot(p1);
    double a2 = angleWithPivot(p2);
    if(cross(vec(pivot, p1), vec(pivot, p2)) == 0){ //Stay away from EPS! caused too many WA's!
        if(fabs(a1 - leastAngle) < EPS){
            return putCloserFirst(p1, p2);
        }
        return putFartherFirst(p1, p2);
    }

    return a1 < a2;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif

    int t, n;
    scanf("%d", &t);
    while(t--){
        vector<point> cvxHull;
        pivot = point(1<<30, 1<<30);
        int pivotPos = 0;
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            scanf("%d %d %s", &x, &y, s);
            if(s[0] == 'Y'){
                cvxHull.push_back(point(x, y));
                if(cmp(*(cvxHull.end()-1), pivot)){
                    pivot = *(cvxHull.end()-1);
                    pivotPos = cvxHull.size() - 1;
                }
            }
        }
        
        swap(cvxHull[pivotPos], cvxHull[0]);
        initMinimalAngle(cvxHull);
        sort(cvxHull.begin()+1, cvxHull.end(), pivotCmp);
        
        printf("%d\n", cvxHull.size());
        for(int i = 0; i < cvxHull.size(); i++){
            printf("%d %d\n", cvxHull[i].X, cvxHull[i].Y);
        }
        
    }
  
    return 0;
}