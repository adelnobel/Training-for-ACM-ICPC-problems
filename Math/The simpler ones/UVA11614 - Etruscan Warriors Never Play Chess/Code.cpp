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

/**
 * 
 * http://apps.topcoder.com/forums/;jsessionid=618EC1F48EF591F86239726C9142F61F?module=Thread&threadID=651145&start=0&mc=6#1147508
 * You are looking for the largest X such that X(X+1)/2 <= N.

   This can be rewritten as X^2 + X - 2N <= 0.

   The positive root of X^2 + X - 2N = 0 is X = ( -1 + sqrt(1+8N) ) / 2, and hence the answer is the integer part of this number.
 * 
 * x = (n*(n+1)) / 2
 * hence, n^2 + n - 2x = 0
 * Solve with quadratic formula!
 * http://en.wikipedia.org/wiki/Quadratic_equation#Quadratic_formula
 * 
 * ax^2 + bx + c = 0
 * 
 * then 
 * x = (-b +|- sqrt(b^2 - 4ac)) / 2a
 * 
 */

int main()
{
    //freopen("in.in", "r", stdin);
    long long t, x, res;
    
    scanf("%lld", &t);
    
    while(t--){
        scanf("%lld", &x);
        
        double e = sqrt(1 + 4 * 2 * x );
        
        res = ((-1 + e) / 2);
        
        printf("%lld\n", res );
    }
    

    return 0;
}