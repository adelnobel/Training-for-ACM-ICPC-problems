#include <algorithm>
#include <functional>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <cstring>

using namespace std;

int t, n, s, d, p, e; 

bool marked[10005];

vector<int> arr;

bool isDivisible(int u)
{
    if(u <= 9)
    {
        arr.push_back(u);
        return true;
    }
    for(int x = 9; x >= 2; x-- )
    {
        if(u % x == 0)
        {
            bool st = isDivisible(x);
            bool nd = isDivisible(u / x);
            if(st && nd)
                return true;
        }
    }
    
    return false;
}



int main()
{
    scanf("%d", &n );
    
    while(n--)
    {
        scanf("%d", &s);
        arr.erase(arr.begin(), arr.end());
        if(isDivisible(s))
        {
            sort(arr.begin(), arr.end());
            for(int x = 0; x < arr.size(); x++)
                printf("%d", arr[x]);
            printf("\n");
        }
        else
            printf("-1\n");
    }
    
    return 0;
}
