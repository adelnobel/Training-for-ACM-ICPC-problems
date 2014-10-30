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

int N, L, mask;

int ar[30];
int recons[30];

pair<int, int> knapSack(int remaining, int cur)
{
    if(remaining < 0) return make_pair(-1000000, 0);
    if(remaining == 0) return make_pair(0, 0);
    if(cur < 0) return make_pair(0, 0);
    
    pair<int, int> takeIt =  knapSack(remaining - ar[cur],cur-1);
    takeIt.first += ar[cur];
    pair<int, int> leaveIt = knapSack(remaining, cur-1);
    
    
    if(takeIt.first >= leaveIt.first)
    {
        takeIt.second |= (1 << cur);
        return takeIt;
    }
    return leaveIt;
    
}

int main()
{
    //freopen("in.in", "r", stdin);
    
    while(scanf("%d %d", &N, &L) != EOF)
    {
        mask = 0;
        for(int x = 0; x < L; x++)
            scanf("%d", &ar[x]);
        pair<int, int> val = knapSack(N, L-1);
        for(int x = 0; x < 21; x++)
        {
            if(val.second & (1 << x))
                printf("%d ", ar[x]);
        }
        printf("sum:%d\n", val.first);
             
    }
    
    return 0;
}