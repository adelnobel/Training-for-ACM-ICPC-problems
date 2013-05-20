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
#include <time.h>

using namespace std;

int r, c;
int inf = (1 << 30) + 1;

typedef struct
{
    int val, pos;
}state;

int arr[15][150];
int arr2[15][150];

int val(int x , int y)
{
    if(x == -1)
        x = r - 1;
    if(x == r)
        x = 0;
    if(x < 0 || x > r - 1 || y < 0 || y > c - 1)
        return inf;
    return arr2[x][y];
}

bool mycmp(state s1, state s2)
{
    if(s1.val == s2.val) return s1.pos < s2.pos;
    return s1.val < s2.val;
}

void solvePathDFS(int x, int y)
{
    if(y == c)
        return ;
    state first; first.val = val(x+1, y + 1); first.pos = (x+1) % r;
    state second; second.val = val(x, y + 1); second.pos = x;
   state third; third.val = val(x - 1, y + 1); third.pos = (x == 0) ? r - 1 : x - 1 ;
   vector<state> s;
   s.push_back(first); s.push_back(second); s.push_back(third);
   
   sort(s.begin(), s.end(), mycmp);
   
   if(y == c - 1)
        printf("%d", x+1);
   else
       printf("%d ", x+1);
   
   solvePathDFS(s[0].pos, y+1);
   
}

int main()
{
    int cou = 0;
    while(scanf("%d %d", &r, &c) != EOF)
    {
        for(int x = 0; x < r; x++)
        {
            for(int y = 0; y < c; y++)
            {
                scanf("%d", &arr[x][y]);
                arr2[x][y] = arr[x][y];
            }
        }
        
        for(int y = c-2; y >= 0; y--)
        {
            for(int x = 0; x < r; x++)
            {
                arr2[x][y] = arr2[x][y] + min( val(x-1, y+1), min(val(x+1, y+1), val(x, y+1)) );
                //printf("%d ", arr2[x][y]);
            }
            //printf("\n");
        }
        
        int mini = arr2[0][0];
        int startX = 0, startY = 0; 
        
        for(int x = 1; x < r; x++)
        {
            if(arr2[x][0] < mini)
            {
                mini = arr2[x][0];
                startX = x;
            }
        }
        
        solvePathDFS(startX, 0);
        printf("\n");
        
        printf("%d\n", mini);
        
    }
    
    return 0;
}
