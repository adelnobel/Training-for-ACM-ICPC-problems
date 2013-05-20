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
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>

using namespace std;

char str[10000];
int stud, a , b, xD, yD;

typedef pair<int, int> ii;
ii arr[30];

double mem[70000];

double solve(int bitm)
{
    if(mem[bitm] > -0.5)
        return mem[bitm];
    
    int firstOnBit = 0;
    for(int x = 0; x < stud; x++)
    {
        if( !((1 << x) & bitm) )
        {
            firstOnBit = x;
            break;
        }
    }
    double dist = 2000000000.00;
    bool flag = false; //Flag will be true IFF this is not the base case!
    for(int x = firstOnBit + 1; x < stud; x++)
    {
        if( !((1 << x) & bitm) )
        {
            flag = true;
            xD = abs(arr[firstOnBit].first - arr[x].first);
            yD = abs(arr[firstOnBit].second - arr[x].second);
            dist = min(dist, sqrt( xD*xD + yD*yD  ) + solve(bitm | (1 << firstOnBit) | (1 << x) ) );
        }
    }
    if(flag)
        mem[bitm] = dist;
    else mem[bitm] = 0.0;
    return mem[bitm];
}


int main()
{
    //freopen("in2.in", "r", stdin);
    int n, cc = 0;
    while(1)
    {
        cc++;
        scanf("%d", &n);
        if(n == 0) break;
        memset(mem, -1, sizeof(mem));
        stud = 2 * n;
        for(int x = 0; x < stud; x++)
        {
            ii i;
            scanf("%s %d %d", str, &i.first, &i.second);
            arr[x] = i;
        }
        
        printf("Case %d: %.2lf\n", cc , solve(0));
        
    }
    
    return 0;
}