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

typedef struct guess
{
    char s[5];
    int correctPos;
    int wrongPos;

}guess;

guess ar[15];

char s[100];

int main()
{
    //freopen("in.in", "r", stdin);
    int t, n, correctPos, wrongPos, tot, mask1 , mask2;
    bool valid;
    char counter[5];
    char best[5];

    counter[4] = best[4] = '\0';
    
    scanf("%d", &t);

    while(t--)
    {
        scanf("%d", &n);
        for(int x = 0; x < n; x++)
        {
            guess g;
            scanf("%s %s", g.s, s);
            g.correctPos = s[0] - '0';
            g.wrongPos = s[2] - '0';
            ar[x] = g;
        }
        
        tot = 0;
        
        for(int a = 0; a <= 9 && tot < 2; a++)
        {
            counter[0] = a + '0';
            for(int b = 0; b <= 9 && tot < 2; b++)
            {
                counter[1] = b + '0';
                for(int c = 0; c <= 9 && tot < 2; c++)
                {
                    counter[2] = c + '0';
                    for(int d = 0; d <= 9 && tot < 2; d++)
                    {
                        counter[3] = d + '0';
                        valid = true;
                        
                        for(int e = 0; e < n && valid; e++)
                        {
                            correctPos = wrongPos = 0;
                            mask1 = mask2 = 0;
                            for(int q = 0; q < 4; q++)
                            {
                                 if(counter[q] == ar[e].s[q]) 
                                 {
                                    correctPos++;
                                    mask1 |= (1 << q);
                                    mask2 |= (1 << q);
                                 }
                            }
                            for(int x = 0; x < 4; x++)
                            {
                                if((mask1 & (1 << x))) continue;
                                for(int y = 0; y < 4; y++)
                                {
                                    if(x == y || (mask2 & (1 << y)) ) continue;
                                    if(counter[x] == ar[e].s[y])
                                    {
                                         mask2 |= (1 << y);
                                         mask1 |= (1 << x);
                                         wrongPos++;
                                         break;
                                    }    
                                }
                            }
                            if(correctPos != ar[e].correctPos) valid = false;
                            if(wrongPos != ar[e].wrongPos) valid = false;
                        }
                        if(valid)
                        {
                            tot++;
                            memcpy(best, counter, sizeof(counter));
                        }
                    }
                }
            }
        }
        
        if(tot == 1)
            printf("%s\n", best);
        else if(tot == 0)
            printf("impossible\n");
        else
            printf("indeterminate\n");

    }
   
    return 0;
}