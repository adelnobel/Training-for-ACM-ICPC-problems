
#include <stdio.h>
#include <cctype>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <functional>
#include <stack>
#include <iostream>
#include <queue>

using namespace std;

bool next(string comb, int mask)
{
    string str = "";
    for(int x = 0; x < comb.size(); x++)
    {
        if( (1 << x) & mask)
            str += comb[x];
    }
    
    cout << str << endl;
}

int main()
{
    int mask = 0;
    string comb = "ABCD";
    
    int val = pow(2, comb.size()); //All subsets are equal to 2 ^ n
    
    while(mask <  val )
    {
        next(comb, mask);
        mask++;
    }
    
    return 0;
}