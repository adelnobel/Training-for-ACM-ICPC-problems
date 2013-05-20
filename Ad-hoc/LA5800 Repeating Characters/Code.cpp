#include <cstring>
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


/**
 2
1 3 ABC
2 5 /HTP
 
 */

using namespace std;

char str[3000];

int main() 
{
    int n, t, r;
    scanf("%d", &n);
    
    for(int x = 1; x <= n; x++)
    {
        scanf("%d %d %s", &t, &r, str);
        string s = "";
        int co = 0;
        while(str[co] != '\0')
        {
            for(int q = 0; q < r; q++)
                s += str[co];
            co++;
        }
        
        cout << x << " " << s << endl;
    }
    
    return 0;
}


