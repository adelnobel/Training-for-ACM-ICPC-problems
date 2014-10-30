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

#define N 105
#define EPS 1e-7

typedef struct rect{
    double x1, y1, x2, y2;
    rect(){};
    rect(double x, double y, double xx, double yy){
        x1 = x, y1 = y, x2 = xx, y2 = yy;
    }
}rect;

typedef struct node{
    int rectNum;
    double p;
    bool isEnd;
    node(){};
    node(int r, double pp, bool i){
        rectNum = r, p = pp, isEnd = i;
    }
    bool operator<(const node &n) const{
        if(fabs(n.p - p) < EPS){
            return isEnd;
        }
        return p < n.p;
    }
}node;

rect points[N];



int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    
    int n, cnt = 1;
    
    while(scanf("%d", &n), n){
        vector<node> v;
        for(int i = 0; i < n; i++){
             scanf("%lf %lf %lf %lf", &points[i].x1, &points[i].y1, &points[i].x2, &points[i].y2);
             v.push_back(node(i, points[i].x1, false));
             v.push_back(node(i, points[i].x2, true));
        }
        
        sort(v.begin(), v.end());
        
        double totArea = 0.0;
        vector<node> vY;
        vY.push_back(node(v[0].rectNum, points[v[0].rectNum].y1, false));
        vY.push_back(node(v[0].rectNum, points[v[0].rectNum].y2, true));

        for(int i = 1; i < v.size(); i++){
            sort(vY.begin(), vY.end());
            double lastY;
            int x = 0, j;
            while(x < vY.size()){
                lastY = vY[x].p;
                int tot = 1;
                j = x+1;
                while(j < vY.size() && tot > 0){
                    if(vY[j].isEnd) tot--;
                    else tot++;
                    j++;
                }
                totArea += (v[i].p - v[i-1].p) * (vY[j-1].p - lastY);
                x = j;
            }
            
            
            if(!v[i].isEnd){
                vY.push_back(node(v[i].rectNum, points[v[i].rectNum].y1, false));
                vY.push_back(node(v[i].rectNum, points[v[i].rectNum].y2, true));
            }else{
                for(int w = 0; w < 2; w++){
                    for(int j = 0; j < vY.size(); j++){
                        if(vY[j].rectNum == v[i].rectNum){
                            vY.erase(vY.begin() + j);
                            break;
                        }
                    }
                }
            }
        }
        printf("Test case #%d\nTotal explored area: ", cnt++);
        printf("%.2lf\n\n", totArea);
        
    }
    

    return 0;
}
