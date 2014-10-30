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

int vals[9][9];

int main()
{
    //freopen("in.in", "r", stdin);
    vector< vector< int > > v;
    
    for(int a = 1; a <= 8; a++)
    {
        for(int b = 1; b <= 8; b++)
        {
            if(a == b || abs(b - a) == 1) continue;
            for(int c = 1; c <= 8; c++)
            {
                if(c == b || c == a || abs(c - a) == 2 || abs(c - b) == 1) continue;
                for(int d = 1; d <= 8; d++)
                {
                    if(d == b || d == a || d == c || abs(d - a) == 3 || abs(d - b) == 2 || abs(d - c) == 1) continue;
                    for(int e = 1; e <= 8; e++)
                    {
                        if(e == b || e == a || e == c || e == d || abs(e - a) == 4 || abs(e - b) == 3 || abs(e - c) == 2 || abs(e - d) == 1) continue;
                        for(int f = 1; f <= 8; f++)
                        {
                            if(f == b || f == a || f == c || f == d || f == e || abs(f - a) == 5 || abs(f - b) == 4 || abs(f - c) == 3 || abs(f - d) == 2 || abs(f - e) == 1 ) continue;
                            for(int g = 1; g <= 8; g++)
                            {
                                if(g == b || g == a || g == c || g == d || g == e || g == f || abs(g - a) == 6 || abs(g - b) == 5 || abs(g - c) == 4 || abs(g - d) == 3 || abs(g - e) == 2 || abs(g - f) == 1  ) continue;
                                for(int h = 1; h <= 8; h++)
                                {
                                    if(h == b || h == a || h == c || h == d || h == e || h == f || h == g || abs(h - a) == 7 || abs(h - b) == 6 || abs(h - c) == 5 || abs(h - d) == 4 || abs(h - e) == 3 || abs(h - f) == 2 || abs(h - g) == 1  ) continue;
                                    
                                    vector<int> ve(8, 0);
                                    ve[0] = a; ve[1] = b; ve[2] = c; ve[3] = d; ve[4] = e;
                                    ve[5] = f; ve[6] = g; ve[7] = h;
                                    
                                    v.push_back(ve);
                                    
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    
    int n;
    
    scanf("%d", &n);
    
    while(n--)
    {
        for(int i = 0; i < 8; i++)
            for(int j = 0; j < 8; j++)
                scanf("%d", &vals[i][j]);
        
        int maxi = 0;
        
        for(int i = 0; i < v.size(); i++)
        {
            int cur = 0;
            for(int j = 0; j < 8; j++)
            {
                cur += vals[j][v[i][j]-1];
            }
            maxi = max(maxi, cur);
        }
        
        printf("%*d\n", 5, maxi);
        
    }
    
    return 0;
}