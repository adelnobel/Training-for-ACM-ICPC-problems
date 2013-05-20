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

typedef struct str
{
    string s;

    bool operator<(const str &ss) const
    {
        if(s.size() != ss.s.size()) return s.size() < ss.s.size();
        return s < ss.s;
    }

    bool operator>(const str &ss) const
    {
        if(s.size() != ss.s.size()) return s.size() > ss.s.size();
        return s > ss.s;
    }

    bool operator==(const str &rhs) const
    {
        return s == rhs.s;
    }

    str(string ss) {s = ss;};
}str;

char s[25][25];
int n, l;

set<str> se;

void recur(int x, int y, char last, int depth, string cur)
{
    if(x >= l || x < 0 || y >= l || y < 0) return;
    if(s[x][y] <= last) return;
    cur += s[x][y];
    if(depth > 2){ 
        se.insert(str(cur));
    }
    for(int a = -1; a <= 1; a++)
        for(int b = -1; b <= 1; b++)
        {
            if( a == 0 && b == 0)
                continue;
            recur(x+a, y+b, s[x][y], depth+1, cur);
        }
}

int main()
{
    //freopen("in.in", "r", stdin);
    int cc = 0;
    scanf("%d", &n);

    while(n--)
    {
        if(cc++ > 0) printf("\n");
        scanf("%d", &l);

        for(int i = 0; i < l; i++)
            scanf("%s", s[i]);
        
        for(int x = 0; x < l; x++)
            for(int y = 0;y < l; y++)
                recur(x, y, 'A' - 1, 1, "");

        set<str>::iterator it;

        for(it = se.begin(); it != se.end(); it++)
            printf("%s\n", it->s.c_str());

        se.clear();



    }

    return 0;
}