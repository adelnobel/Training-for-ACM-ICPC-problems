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

#define N 10005

int arr[N];

typedef struct node{
    int bestLeft, bestRight, best, sum;
    node(){};
    node(int bL, int bR, int b, int s){
        bestLeft = bL;
        bestRight = bR;
        best = b;
        sum = s;
    }
}node;

node solve(int s, int e){
    if(s == e){
        return node(arr[s], arr[s], arr[s], arr[s]);
    }
    
    int mid = (s + e) / 2;
    node l = solve(s, mid);
    node r = solve(mid+1, e);
    
    int bestLeft = max(l.bestLeft, max(l.sum, l.sum + r.bestLeft));
    int bestRight = max(r.bestRight, max(r.sum, r.sum + l.bestRight));
    int sum = l.sum + r.sum;
    int best = max(bestLeft, max(bestRight, max(sum, l.bestRight + r.bestLeft)));
    best = max(best, max(l.best, r.best));
    
    return node(bestLeft, bestRight, best, sum);
    
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    
    int n;
    
    while(scanf("%d", &n), n){
        for(int i = 0; i < n; i++){
            scanf("%d", &arr[i]);
        }
        node res = solve(0, n-1);
        if(res.best <= 0){
            printf("Losing streak.\n");
        }else{
            printf("The maximum winning streak is %d.\n", res.best);
        }
    }
    
    
    return 0;
}