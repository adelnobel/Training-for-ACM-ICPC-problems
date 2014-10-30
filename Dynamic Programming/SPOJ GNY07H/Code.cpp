
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

int arr[1000][16];

int n, tot, val;

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
    
    if(mask == 0)
    {
        val = solve(y+1, 0b1111) + solve(y+1, 0b1100) + solve(y+1, 0b1001) + solve(y+1, 0b0011) + solve(y+1, 0);
    }
    else if(mask == 0b1100)
    {
        val = solve(y+1, 0) + solve(y+1, 0b0011);
    }
    else if(mask == 0b1001)
    {
        val = solve(y+1, 0) + solve(y+1, 0b0110);
    }
    else if(mask == 0b0011)
    {
        val = solve(y+1, 0) + solve(y+1, 0b1100);
    }
    else if(mask == 0b1111)
    {
        val = solve(y+1, 0);
    }
    else if(mask == 0b0110)
    {
        val = solve(y+1, 0b1001);
    }
    
    arr[y][mask] = val;
    return val;
}


int main() 
{
    int t;
    scanf("%d", &t);
    for(int x = 1; x <=t; x++)
    {
        memset(arr, -1, sizeof(arr));
        scanf("%d", &n);
        if(n == -1)
            break;
        printf("%d %d\n",x, solve(1, 0));
    }
    return 0;
}




