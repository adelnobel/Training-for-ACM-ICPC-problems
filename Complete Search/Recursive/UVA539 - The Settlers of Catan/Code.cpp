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

vector< int > v[30];
int edgesNums[30][30];

int solve(int usedEdgesMask, int vertex)
{
    int best = 0;
    for(int i = 0; i < v[vertex].size(); i++){
        if( !( (1 << edgesNums[vertex][v[vertex][i]]) & usedEdgesMask)) 
        {
             best = max(best,  solve( ((1 << edgesNums[vertex][v[vertex][i]]) | usedEdgesMask), v[vertex][i] ) );
        }
    }
    return best + 1;
}


int main()
{
    //freopen("in.in", "r", stdin);
    int n, m, s, d;
    
    while(1)
    {
        scanf("%d %d", &n, &m);
        if(n == 0 && m == 0) break;
        
        for(int x = 0; x < 30; x++)
            v[x].clear();
        
        for(int x = 0; x < m; x++)
        {
            scanf("%d %d", &s, &d);
            v[s].push_back(d);
            v[d].push_back(s);
            edgesNums[s][d] = edgesNums[d][s] = x;
        }
        
        int maxi = 0;
        
        for(int x = 0; x < n; x++){
            maxi = max(maxi , solve(0, x));
        }
        
        if(maxi > 0) maxi -= 1; //We decrease one if maxi > 0 because one edge is taken twice! 
        printf("%d\n", maxi);
        
    }
    
    return 0;
}