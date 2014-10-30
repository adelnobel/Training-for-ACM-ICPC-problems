#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <bits/stl_vector.h>

using namespace std;

#define EPS 1e-3

typedef struct record
{
    int x, y;
    record(int xx, int yy) {x = xx; y = yy;};
}record;

int GCD(int a, int b)
{
    if(a == 0) return b;
    if(b == 0) return a;
    return GCD(a%b, b % a);
}

int LCM(long long a, long long b)
{
    return (a * b) / GCD(a, b);
}

int main()
{
    //freopen("in.in", "r", stdin);
    
    int n, tot;
    double res, a1, b1, bb1;
    
    while(scanf("%d", &n) != EOF)
    {
        res = 1. / n;
        tot = 0;
        int a = n + 1;
        vector<record> v; 
        for(; a <= 200000; a++)
        {
            a1 = 1. / a;
            b1 = res - a1;
            bb1 = powl(b1, -1);
            int fu = roundl( bb1 );
            if( fabs( fu - bb1 ) <= EPS && ((long long)(a) * (long long)(fu)) % n == 0 )
            {
                    tot++;
                    v.push_back(record(fu, a));
            }
            if(fu < a) break;
            
        }
        
        printf("%d\n", tot);
        for(int x = 0; x < v.size(); x++)
            printf("1/%d = 1/%d + 1/%d\n", n, v[x].x, v[x].y);
        
    }
    
    
    return 0;
}