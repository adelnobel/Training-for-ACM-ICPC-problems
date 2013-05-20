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

typedef long long ll;

char xx[10], yy[10];
string x, y;

char t[20];

int getDigits(ll n){
    if(n == 0) return 1;
    int ret = 0;
    while(n > 0){
        n /= 10;
        ret++;
    }
    return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    
    int cc = 1;
    ll a, b;
    
    while(scanf("%lld %lld", &a, &b), a || b){
        sprintf(yy, "%lld", b);
        y = yy;
        reverse(y.begin(), y.end());
        printf("Problem %d\n", cc++);

        int resD = getDigits(a*b);
        
        printf("%*lld\n", resD, a);
        printf("%*lld\n", resD, b);
        
        for(int i = 0; i < resD; i++) t[i] = '-';
        t[resD] = '\0';
        
        printf("%s\n", t);
        
        string cur = "";
        int pad;
        bool flag = false;
        int total = 0;
        
        for(int i = 0; i < y.size(); i++){
            ll m = (y[i] - '0') * a;
            if(m != 0){
                if(flag){
                    printf("%*lld%s\n", resD - i, m , cur.c_str());
                    total++;
                }else{
                    printf("%*lld\n", resD - i, m);
                    total++;
                }
                cur = "";
                flag = false;
            }else{
                cur += "0";
                flag = true;
                pad = i;
            }
        }
        
        if(total > 1){
            printf("%s\n%lld\n", t, a * b);
        }
        
    }
    
    
   
    return 0;
}