#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <ctime>

using namespace std;

#define EPS 1e-9

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    
    int n;
        
    while(scanf("%d", &n) == 1){
        int tot = 1, i = 0;
        double s, q;
        scanf("%lf", &s);
        for(int x = 1; x < n; x++){
            scanf("%lf", &q);
            if(q - (s + 1) > -EPS ){
                s = q;
                tot++;
            }
        }
        
        cout << tot << endl;
    }
    
    
   
    return 0;
}