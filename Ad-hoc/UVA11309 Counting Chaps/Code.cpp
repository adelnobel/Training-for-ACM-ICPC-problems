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

#define EPS 1e-7
#define N 10


char s[N];

char s1[N];

int main()
{
    //freopen("in2.in", "r", stdin);
    int n;
    scanf("%d", &n, s);
    while(n--)
    {
        scanf("%s", s);
        bool valid = true, flag = true;
        
        int a1 = s[0] - '0', b1 = s[1] - '0', c1 = s[3] - '0', d1 = s[4] + 1 - '0';
        
        while(flag)
        {
            for(int a = a1 + '0'; a <= '2' && flag; a++)
            {
                char to = '9';
                if(a == '2') to = '3';
                for(int b = b1 + '0'; b <= to && flag; b++)
                {
                    for(int c = c1 + '0'; c <= '5' && flag; c++)
                    {
                        for(int d = d1 + '0'; d <= '9' && flag; d++)
                        {
                            valid = true;
                            if( a != d  ) valid = false;
                            if( b != c  ) valid = false;
                            if(a == '0')
                            {
                                valid = false;
                                if(b == '0')
                                {
                                    if(c == '0')
                                    {
                                        valid = true;
                                    }
                                    else
                                    {
                                        if(c == d) valid = true;
                                    }
                                }
                                else
                                {
                                    if(b == d) valid = true;
                                }
                            }
                            if(valid)
                            {
                                printf("%c%c:%c%c\n", a, b, c, d);
                                flag = false;
                            }
                        }
                        d1 = 0;
                    }
                    c1 = 0;
                }
                b1 = 0;
            }
            a1 = 0;
        }
    }
    
    return 0;
}