#include <cstdlib>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <queue>
#include <cmath>
 
using namespace std;

#define EPS 1e-10
 
typedef long long ll;

typedef struct Ent{
    double x, y, s;
    Ent(){};
    Ent(double a, double b, double c){
        x = a, y = b, s = c;
    }
}Ent;

vector< Ent > v;

int minY, maxY, minX, maxX;

double calcDist(double a, double b){
    double ret = -1e18;
    for(int i = 0; i < v.size(); i++){
        double diffX = fabs(v[i].x - a);
        double diffY = fabs(v[i].y - b);
        ret = max(ret, sqrt(diffX*diffX + diffY*diffY) / v[i].s);
    }
    return ret;
}

double bsY(double x){
    double left = minY, right = maxY, g, h, add;
    while(right - left > EPS){
        add = (right-left) / 3;
        g = left + add, h = left + 2*add;
        if(calcDist(x, g) > calcDist(x, h)){
            left = g;
        }else{
            right = h;
        }
    }
    return calcDist(x, left);
}

double solve(){
    double left = minX, right = maxX, g, h, add;
    while(right - left > EPS){
        add = (right - left) / 3;
        g = left + add, h = left + 2*add;
        if(bsY(g) > bsY(h)){
            left = g;
        }else{
            right = h;
        }
    }
    return bsY(left);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    
    int T, n, a, b, c;
    scanf("%d", &T);
    
    while(T--){
        scanf("%d", &n);
        v.clear();
        minX = minY = 1e9;
        maxX = maxY = -1e9;
        for(int i = 0; i < n; i++){
            scanf("%d %d %d", & a, &b, &c);
            v.push_back(Ent(a, b, c));
            minY = min(minY, b);
            maxY = max(maxY, b);
            minX = min(minX, a);
            maxX = max(maxX, a);
        }
        printf("%.15lf\n", solve());
    }
    

    return 0;
}