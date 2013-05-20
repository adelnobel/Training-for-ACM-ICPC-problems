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
#include <bitset>


using namespace std;

int mask;

bool noRepeat(long long in)
{
    mask = 0;
    while(in > 0)
    {
        if( mask & (1 << (in % 10) ) )
            return false;
        mask |= 1 << (in % 10);
        in /= 10;
    }
    return true;
}

int main()
{
    //freopen("in.in", "r", stdin);
    
    int t;
    
    scanf("%d", &t);
    
    long long n, res;
    
    for(int x = 0; x < t; x++)
    {
        if(x > 0) printf("\n");
        scanf("%lld", &n);
        long long c = 1;
        while(1)
        {
            if( noRepeat(c) )
            {
                res = n * c;
                if(res > 9999999999) break;
                if( noRepeat(res) )
                {
                    printf("%lld / %lld = %lld\n", res, c, n);
                }
            }
            c++;
        }
    }
    return 0;
}