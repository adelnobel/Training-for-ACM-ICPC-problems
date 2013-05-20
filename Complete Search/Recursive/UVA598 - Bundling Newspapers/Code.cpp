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

char s[20];

int toInt(char* str)
{
    int ret = 0;
    while(*str != '\0' && *str != ' '){
        ret = (ret * 10) + *str - '0';
        str++;
    }
    return ret;
}

char newsPapers[20][40];

int c;

void solve(int cur, int remaining, string ss)
{
    if(cur == c) return;
    if(remaining == 1) {
        printf("%s", ss.c_str());
        printf("%s\n", newsPapers[cur]);
        return;
    }
    
    string temp = ss + newsPapers[cur] + ", ";
    for(int i = cur + 1; i < c; i++)
        solve(i, remaining - 1, temp);
    
}

int main()
{
    //freopen("in.in", "r", stdin);
    int n, from, to, cc = 1;
    
    scanf("%d", &n);
    gets(s);
    gets(s); //For blank line
    while(n--)
    {
        if(cc > 1) printf("\n");
        cc++;
        gets(s);
        if(s[0] == '*') {
            from = 1;
            to = 1 << 30;
        }
        else 
        {
            int q;
            for(q = 0; s[q] != '\0' && s[q] != ' '; q++);
            from = toInt(s);
            if(s[q] == ' ')
            {
                to = toInt(s+q+1);
            }
            else
            {
                to = from;
            }
        }
        

        
        c = 0;
        while(1)
        {
            newsPapers[c][0] = '\0';
            gets(newsPapers[c]);
            if(newsPapers[c][0] == '\0') break;
            c++;
        }
        
        if(to == (1 << 30)) to = c;

        for(int j = from; j <= to; j++)
        {
            printf("Size %d\n", j);
            for(int i = 0; i < c; i++)
            {
                solve(i, j, "");
            }
            printf("\n");
        }
        
    }
    
    return 0;
}