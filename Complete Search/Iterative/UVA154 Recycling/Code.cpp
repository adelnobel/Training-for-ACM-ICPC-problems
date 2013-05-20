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

char s[10000];

typedef struct city
{
    char r, o, y, g, b;
}city;

city a[102];

int cb[26][26];

/**
Find the city that the most of the rest of the cities put the same colors as it in the same Bin;
Check for every color the similarities between the city and the other cities for this specific color
**/

int main()
{
    //freopen("in.in", "r", stdin);
    bool stop = false;
    while(!stop)
    {
        int tot = 0;
        
        memset(cb, 0, sizeof(cb));
        
        while(1)
        {
            gets(s);
            if(s[0] == '#')
            {
                stop = true;
                break;
            }
            if(s[0] == 'e') break;
            city c;
            for(int x = 0; x <= 16; x += 4)
            {
                cb[s[x] - 'a'][s[x+2] - 'A']++;
                if(s[x] == 'r') c.r = s[x+2];
                else if(s[x] == 'o') c.o = s[x+2];
                else if(s[x] == 'y') c.y = s[x+2];
                else if(s[x] == 'g') c.g = s[x+2];
                else if(s[x] == 'b') c.b = s[x+2];
            }
            a[tot++] = c;
        }
        if(stop) break;
        int maxi = 0;
        int best;
        for(int x = 0; x < tot; x++)
        {
            int total = 0;
            total += cb['b' - 'a'][a[x].b - 'A'];
            total += cb['g' - 'a'][a[x].g - 'A'];
            total += cb['o' - 'a'][a[x].o - 'A'];
            total += cb['r' - 'a'][a[x].r - 'A'];
            total += cb['y' - 'a'][a[x].y - 'A'];
            if(maxi < total){
                maxi = total;
                best = x;
            }
        }
        printf("%d\n", best+1);
    }
    
    return 0;
}