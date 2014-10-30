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

char s[1000];

bool conn[26][26];

bool present[26];

int main()
{
    //freopen("in.in", "r", stdin);
    int cc = 0;
    while(1)
    {
        scanf("%s", s);
        int len = strlen(s);
        if(len == 1 && s[0] == '#') break;
        memset(conn, 0, sizeof(conn));
        memset(present, false, sizeof(present));
        int c = 0;
        int cur;
        while(c < len)
        {
            cur = s[c] - 'A';
            present[cur] = true;
            c+=2;
            while(isalpha(s[c]))
            {
                conn[cur][s[c] - 'A'] = conn[s[c] - 'A'][cur]  = true;
                present[s[c] - 'A'] = true;
                c++;
            }
            c++;
        }
        
        int mini = 2000000000;
        
        string best = "";
        string str = "";
        
        for(int x = 0; x < 26; x++)
        {
            if(present[x])
                str += 'A' + x;
        }
        
        do
        {
            int maxi = 1;
            for(int x = 0; x < str.size(); x++)
                for(int y = 0; y < str.size(); y++)
                {
                    if(x == y) continue;
                    if(conn[str[x] - 'A'][str[y] - 'A'])
                        maxi = max(maxi, abs(y - x));
                }
            if(mini > maxi)
            {
                mini = maxi;
                best = str;
            }
        }while(next_permutation(str.begin(), str.end()));
        
        for(int x = 0; x < best.size(); x++)
        {
            printf("%c ", best[x]);
        }
        
        printf("-> %d\n", mini);
    }

    return 0;
}