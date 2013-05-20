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

/**
Precompute all possible numbers, we loop only to sqrt of the 8,6,4,2 digits number
**/

using namespace std;

int main()
{
    //freopen("in.in", "r", stdin);
    
    int sum, squared, conc;
    
    vector< string > v[9];
    char q[100];
    string s;
    
    for(int x = 1; x <= 4; x++)
    {
        int to = pow(10, x);
        
        for(int a = 0; a < to; a++)
        {
            for(int b = 0; b < to; b++)
            {
                sum = a + b;
                if(sum >= to) break;
                conc = (a*to) + b;
                if(sum*sum == conc)
                {
                    sprintf(q, "%d", conc);
                    s = q;
                    s.insert(s.begin(), (x*2) -  s.size(), '0' );
                    v[x*2].push_back(s);
                }
            }
        }
        
    }
    
    int n;
    
    while(scanf("%d", &n) != EOF)
    {
        for(int x = 0; x < v[n].size(); x++)
            printf("%s\n", v[n][x].c_str());
    }
    
    return 0;
}