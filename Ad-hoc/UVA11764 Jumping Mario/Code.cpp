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


using namespace std;

int main() 
{
    //freopen("in","r", stdin);
    int n, nu, t, l;
    scanf("%d", &n);
    for(int x = 1; x <= n; x++)
    {
        int high = 0, low = 0;
        scanf("%d", &nu);
        scanf("%d", &t);
        nu--;
        while(nu--)
        {
            scanf("%d", &l);
            if(l > t)
                high++;
            if(t > l)
                low++;
            t = l;
        }
        
        printf("Case %d: %d %d\n", x, high, low);
        
    }
    
                        
    
    return 0;
}


