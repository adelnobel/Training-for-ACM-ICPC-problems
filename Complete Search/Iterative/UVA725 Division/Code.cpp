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

/**
We use the same mask for both sides to check if a digit occurs twice within both sides..
**/

int mask;
int lastDigit;

bool hasRepeatedDigits(int n)
{
    if(n <= 999) return true;
    if(n <= 9999) n*=10; //Add zero to the number!
    while(n > 0)
    {
        lastDigit = (n%10);
        if(mask & (1 << lastDigit ) ) {
            return true;
        }
        mask |= (1 << lastDigit );
        n /= 10;
    }
    return false;
}


int main()
{
    //freopen("in.in", "r", stdin);
    
    int n, cc = 1;
    
    while(1)
    {
        scanf("%d", &n);
        if(n == 0) break;
        if(cc > 1) printf("\n");
        cc++;
        int tot = 0;
        int res;
        for(int x = 01234; x <= 98765; x++)
        {
            if(x % n != 0) continue;
            res = x / n;
            mask = 0;
            if(hasRepeatedDigits(x)) continue;
            
            if(!hasRepeatedDigits( res )) {
                printf("%05d / %05d = %d\n", x, res, n );
                tot++;
            }
        }
        if(tot == 0)
            printf("There are no solutions for %d.\n", n);
    }
    
    
    return 0;
}