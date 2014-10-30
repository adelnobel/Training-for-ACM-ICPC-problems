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

int a, b, n;

bool marked[11][11];
int arr[15][15];

typedef struct
{
    int a , b;
}score;

int dfs(int x , int y)
{
    if(x == a && y == b )
        return 1;
    if(x > a || y > b)
        return 0;
    
    int r1, r2;
    if(arr[x+1][y] == -1)
    {
        r1 = dfs(x+1, y);
        arr[x+1][y] = r1;
    }
    else
        r1 = arr[x+1][y];
    if(arr[x][y+1] == -1)
    {
        r2 = dfs(x, y+1);
        arr[x][y+1] = r2;
    }
    else
        r2 = arr[x][y+1];
    
    return r1 + r2;
}

int main()
{
    while(1)
    {
        scanf("%d %d", &a, &b);
        
        //memset(marked, false, sizeof(marked));
        memset(arr, -1, sizeof(arr));
        
        if(a == -1 && b == -1)
            break;
        
        int tot = dfs(0, 0);
        
        if(tot == a+b)
            printf("%d+%d=%d\n", a, b , tot);
        else
            printf("%d+%d!=%d\n", a, b , a+b);
        
    }
    
    
    return 0;
}
