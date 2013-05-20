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
#include <limits>

using namespace std;

int LCS[2005][2005];

char str1[2005];
char str2[2005];

int main()
{
    //freopen("in", "r", stdin);
    while(gets(str1) != NULL)
    {
        gets(str2);
        int strlen1 = strlen(str1);
        int strlen2 = strlen(str2);
        
        for(int y = 0; y < strlen1; y++)
        {
            LCS[y][0] = 0;
        }
        for(int x = 0; x < strlen2; x++)
        {
            LCS[0][x] = 0;
        }
        
        for(int x = 1; x <= strlen1; x++)
        {
            for(int y = 1; y <= strlen2; y++)
            {
                if(str1[x-1] == str2[y-1])
                {
                    LCS[x][y] = LCS[x-1][y-1] + 1;
                }
                else
                {
                    LCS[x][y] = max(LCS[x-1][y], LCS[x][y-1]);
                }
            }
        }
        cout << LCS[strlen1][strlen2] << endl;
    }
    
    
    return 0;
}
 