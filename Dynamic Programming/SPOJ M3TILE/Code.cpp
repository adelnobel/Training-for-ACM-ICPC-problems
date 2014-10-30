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
#include <queue>

using namespace std;

int arr[31][8];


int n, tot;

int solve(int y, int mask)
{
    if(y > n)
    {
        if(mask == 0)
            return 1;
        return 0;
    }
    if(arr[y][mask] != -1)
        return arr[y][mask];
        
    int val;
    if(mask == 0)
    {
        val = solve(y+1, 4) + solve(y+1, 7) + solve(y+1, 1);
    }
    else if(mask == 7)
    {
        val = solve(y+1, 0);
    }
    else if(mask == 1 )
    {
        val = solve(y+1, 6) + solve(y+1, 0);
    }
    else if(mask == 6)
    {
        val = solve(y+1, 1);
    }
    else if(mask == 4)
    {
        val = solve(y+1, 0) + solve(y+1, 3);
    }
    else if(mask == 3)
    {
        val = solve(y+1, 4);
    }
    arr[y][mask] = val;
    return val;    
}

int main() 
{
    
    
    while(1)
    {
        memset(arr, -1, sizeof(arr));
        scanf("%d", &n);
        if(n == -1)
            break;
        tot = solve(1, 0);
        printf("%d\n", tot);
    }
    

    return 0;
}