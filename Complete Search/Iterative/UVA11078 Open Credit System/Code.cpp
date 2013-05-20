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

using namespace std;



int main()
{
    //freopen("in.in", "r", stdin);
    int t, n, a, b;
    scanf("%d", &t);
    
    while(t--)
    {
        int best, maxi;
        scanf("%d", &n);
        scanf("%d", &a);
        scanf("%d", &b);
        maxi = max(a, b);
        best = a - b;
        
        for(int x = 2; x < n; x++)
        {
            scanf("%d", &a);
            best = max(maxi-a, best);
            maxi = max(a, maxi);
        }
        
        printf("%d\n", best);
    }
    
    
    return 0;
}