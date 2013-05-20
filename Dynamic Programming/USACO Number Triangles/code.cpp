/*
ID: adelnob1
PROG: numtri
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

int r, t;

int main() 
{
    FILE* f = fopen("numtri.in", "r");
    FILE* fo = fopen("numtri.out", "w");
    
    vector< vector<int> > v;
    
    fscanf(f, "%d", &r);
    
    for(int x = 1; x <= r; x++)
    {
        vector<int> q;
        for(int a = 0; a < x; a++)
        {
            fscanf(f, "%d", &t);
            q.push_back(t);
        }
        v.push_back(q);
    }
    
    for(int x = r-2; x >= 0; x-- )
    {
        for(int a = 0; a < v[x].size(); a++)
        {
            v[x][a] += max(v[x+1][a], v[x+1][a+1]); 
        }
    }
    
    fprintf(fo, "%d\n", v[0][0]);
    
    fclose(f); fclose(fo);
    
    return 0;
}