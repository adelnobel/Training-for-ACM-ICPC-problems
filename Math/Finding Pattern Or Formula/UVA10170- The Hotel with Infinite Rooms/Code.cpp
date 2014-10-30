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
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <limits>
#include <tr1/unordered_map>

using namespace std;

typedef long long ll;

/**
http://en.wikipedia.org/wiki/Quadratic_equation#Quadratic_formula
http://www.mathwords.com/a/arithmetic_series.htm
http://online-judge.uva.es/board/viewtopic.php?f=10&t=985&start=15

**/

ll a, n, x;
int main()
{
    //freopen("in.in", "r", stdin);

    
    while(scanf("%lld %lld", &a, &x) != EOF){
        ll b = (2 * a) - 1;
        double w = (-b + sqrt((b*b) - (4 * -2 * x))) / 2.0;
        n =  (ll) ceil(w);
        printf("%lld\n", a+n-1);
    }

    
    return 0;
}