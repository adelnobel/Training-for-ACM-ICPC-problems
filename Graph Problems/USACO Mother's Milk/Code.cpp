/*
ID: adelnob1
PROG: milk3
LANG: C++
*/
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

typedef struct
{
    int a, b , c;
}state;

bool marked[25][25][25];

int a, b , c;

int main() 
{
    FILE* f = fopen("milk3.in", "r");
    FILE* fo = fopen("milk3.out", "w");
    
    memset(marked, false, sizeof marked);
    
    
    fscanf(f, "%d %d %d", &a, &b, &c);
    state s;
    s.a = 0;
    s.b = 0;
    s.c = c;
    
    vector<int> valid;
    
    queue<state> q;
    q.push(s);
    bool flag = true;
    
    while(!q.empty())
    {
        state cur = q.front(); q.pop();
        if(cur.a == 0 && !flag)
            valid.push_back(cur.c);
        
        flag = false;
        
        if(cur.c > 0 && cur.a < a) // C => A
        {
             state n = cur;
             int mini = min(cur.c, a - cur.a);
             n.c -= mini;
             n.a += mini;
             if(!marked[n.a][n.b][n.c])
             {
                 marked[n.a][n.b][n.c] = true;
                 q.push(n);
             }
        }
        
        if(cur.c > 0 && cur.b < b) // C => B
        {
             state n = cur;
             int mini = min(cur.c, b - cur.b);
             n.c -= mini;
             n.b += mini;
             if(!marked[n.a][n.b][n.c])
             {
                 marked[n.a][n.b][n.c] = true;
                 q.push(n);
             }
        }
        
        if(cur.a > 0 && cur.b < b) // A => B
        {
             state n = cur;
             int mini = min(cur.a, b - cur.b);
             n.a -= mini;
             n.b += mini;
             if(!marked[n.a][n.b][n.c])
             {
                 marked[n.a][n.b][n.c] = true;
                 q.push(n);
             }
        }
        if(cur.a > 0 && cur.c < c) // A => C
        {
             state n = cur;
             int mini = min(cur.a, c - cur.c);
             n.a -= mini;
             n.c += mini;
             if(!marked[n.a][n.b][n.c])
             {
                 marked[n.a][n.b][n.c] = true;
                 q.push(n);
             }
        }
        
        if(cur.b > 0 && cur.c < c) // B => C
        {
             state n = cur;
             int mini = min(cur.b, c - cur.c);
             n.b -= mini;
             n.c += mini;
             if(!marked[n.a][n.b][n.c])
             {
                 marked[n.a][n.b][n.c] = true;
                 q.push(n);
             }
        }
        
        if(cur.b > 0 && cur.a < a) // B => A
        {
             state n = cur;
             int mini = min(cur.b, a - cur.a);
             n.b -= mini;
             n.a += mini;
             if(!marked[n.a][n.b][n.c])
             {
                 marked[n.a][n.b][n.c] = true;
                 q.push(n);
             }
        }
    }
    
    sort(valid.begin(), valid.end());
    
    for(int x = 0; x < valid.size() - 1; x++)
        fprintf(fo, "%d ", valid[x]);
    fprintf(fo, "%d\n", valid[valid.size() - 1]);
    
    fclose(f); fclose(fo);
    
    return 0;
}