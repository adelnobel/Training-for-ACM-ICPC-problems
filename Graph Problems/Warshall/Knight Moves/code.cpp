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

int t, n, s, d, p, e; 

int links[9][9][9][9];

char str1[10];
char str2[10];


int main()
{
    for(int x = 0; x < 9; x++)
        for(int y = 0; y < 9; y++)
        {
            for(int z = 0; z < 9; z++)
                for(int q = 0; q < 9; q++)
                        links[x][y][z][q] = 1 << 29;
            links[x][y][x][y] = 0;
        }
    for(int x = 0; x < 8; x++)
    {
        for(int y = 0; y < 8; y++)
        {
            
            if(x - 1 >= 0 && y + 2 <= 8 )
            {
                links[x][y][x-1][y+2] = 1;
                links[x-1][y+2][x][y] = 1;
            }
            if(x - 2 >= 0 && y + 1 <= 8 )
            {
                links[x][y][x-2][y+1] = 1;
                links[x-2][y+1][x][y] = 1;
            }
            if(x - 1 >= 0 && y - 2 >= 0 )
            {
                links[x][y][x-1][y-2] = 1;
                links[x-1][y-2][x][y] = 1;
            }
            if(x - 2 >= 0 && y - 1 >= 0 )
            {
                links[x][y][x-2][y-1] = 1;
                links[x-2][y-1][x][y] = 1;
            }
            
            if(x + 1 <= 8 && y + 2 <= 8 )
            {
                links[x][y][x+1][y+2] = 1;
                links[x+1][y+2][x][y] = 1;
            }
            if(x + 2 <= 8 && y + 1 <= 8 )
            {
                links[x][y][x+2][y+1] = 1;
                links[x+2][y+1][x][y] = 1;
            }
            if(x + 1 <= 8 && y - 2 >= 0 )
            {
                links[x][y][x+1][y-2] = 1;
                links[x+1][y-2][x][y] = 1;
            }
            if(x + 2 <= 8 && y - 1 >= 0 )
            {
                links[x][y][x+2][y-1] = 1;
                links[x+2][y-1][x][y] = 1;
            }
            
        }
    }
    
    
    for(int a = 0; a < 8; a++)
        for(int b = 0; b < 8; b++)
            for(int c = 0; c < 8; c++)
                for(int d = 0; d < 8; d++)
                {
                    for(int e = 0; e < 8; e++)
                        for(int f = 0; f < 8; f++)
                        {
                            if(links[c][d][e][f] > links[c][d][a][b] + links[a][b][e][f])
                                links[c][d][e][f] = links[c][d][a][b] + links[a][b][e][f];
                        }
                }
    
    
    while(scanf("%s %s", str1, str2) != EOF)
    {
        printf("To get from %s to %s takes %d knight moves.\n", str1, str2, links[str1[1] - 1 - '0'][str1[0] - 'a'][str2[1] - 1 - '0'][str2[0] - 'a'] );
    }
    
    
    return 0;
}
