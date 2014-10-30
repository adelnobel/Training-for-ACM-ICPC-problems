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

int n;

int arr[30];
int arr2[30];

int main() 
{
    //freopen("in2.in", "r", stdin);
    int couu = 0;
    while(1)
    {
        couu++;
         scanf("%d", &n);
         if(n == 0)
             break;
         for(int x = 0; x < n; x++)
             scanf("%d", &arr[x]);
         
         int co = 0;
         
         bool shift = true;
         bool valid = true;
         
         for(int x = 1; x < n; x++)
             if(arr[x] != arr[x-1]) valid = false;
         
         while(co < 1000 && !valid )
         {
             valid = true;
             if(shift)
             {
                for(int x = 0; x < n; x++)
                {
                    arr2[x] = abs(arr[x] - arr[ ( (x+1) % n)]);
                    if(x > 0)
                    if(arr2[x] != arr2[x-1]) valid = false;
                }
             }
             else
             {
                for(int x = 0; x < n; x++)
                {
                    arr[x] = abs(arr2[x] - arr2[( (x+1) % n)]);
                    if(x > 0)
                    if(arr[x] != arr[x-1]) valid = false;
                }
             }
             co++;
             shift ^= 1;
         }
         
         cout << "Case " << couu << ": ";
         if(valid)
                cout << co << " iterations" << endl;
         else
                cout << "not attained" << endl;
    }
    return 0;
}


