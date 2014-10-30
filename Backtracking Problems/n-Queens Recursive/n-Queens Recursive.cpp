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

using namespace std;

bool arr[20][20];

bool isValid(int x , int pos, int n)
{
        for(int a = 1; a < pos; a++)
        {
            if(arr[a][x])
                return false;
            int leftDiagonal =  x - (pos - a) ;
            int rightDiagonal = x + (pos - a);
            if( leftDiagonal > 0 && arr[a][ leftDiagonal ]) //pos Current Row, a the other row
                return false;
            if( n >= rightDiagonal && arr[a][ rightDiagonal ])
                return false;
        }
        return true;
}

void recur(int pos, int n, int &tot)
{
    if(pos > n)
    {
        tot++;
        return;
    }
    int x;
    for(x = 1; x <= n; x++)
    {
        arr[pos][x - 1 ] = false;
        arr[pos][x] = true;
        if(isValid(x, pos, n))
           recur(pos+1, n, tot);
    }
    arr[pos][x - 1] = false;
}

int main()
{
    memset(arr, false, sizeof(arr));
    int tot = 0;
    
    recur(1, 8, tot);
    
    printf("%d", tot);
    return 0;
}