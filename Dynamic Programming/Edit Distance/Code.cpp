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

int arr[2012][2012];

int n;

char str1[2012];
char str2[2012];


int main()
{
    scanf("%d", &n);
    while(n--)
    {
        memset(arr, 0, sizeof(arr));
        scanf("%s %s", str1+1, str2+1);
        str1[0] = str2[0] = ' ';
        int x = 0, y = 0;
        while(str1[x] != '\0') //Horizontal, 0th row and columns to length of the str1 (Initialize the first row)
        {
            arr[0][x] = x;
            x++;
        }

        while(str2[y] != '\0') //Vertical, 0th column and all rows to length of str2 (Initialize the first column)
        {
            arr[y][0] = y;
            y++;
        }

        int a, b;
        for(a = 1; a < x; a++) //Loop by str1 length
        {
            for(b = 1; b < y; b++)
            {
                arr[a][b] = min(arr[a-1][b] + 1, min(arr[a][b-1] + 1 ,  arr[a-1][b-1] + (str1[a] != str2[b]) ));
            }
        }

        printf("%d\n", arr[x-1][y-1]);

    }

    return 0;
}
