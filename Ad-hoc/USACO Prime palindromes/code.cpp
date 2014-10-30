/*
ID: adelnob1
PROG: pprime
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

bool isPrime(int n)
{
    if(n == 1 || n == 2)
        return true;
    int root = sqrt(n) + 1;
    for(int x = 2; x <= root; x++ )
        if(n % x == 0 )
            return false;
    return true;
}

int main() 
{
    FILE* f = fopen("pprime.in", "r");
    FILE* fo = fopen("pprime.out", "w");
    
    int start, end;
    fscanf(f, "%d %d", &start, &end);
    
    vector<int> valid;
    
    for(int a = 0; a <= 10; a++)
        for(int b = 0; b <= 10; b++)
            for(int c = 0; c <= 10; c++)
                for(int d = 0; d <= 10; d++)
                {
                    for(int e = 0; e <= 10; e++)
                    {
                        int n = 0;
                        if(a < 10)
                            n = (n * 10) + a;
                        if(b < 10)
                            n = (n * 10) + b;
                        if(c < 10)
                            n = (n * 10) + c;
                        if(d < 10)
                            n = (n * 10) + d;
                        if(e < 10)
                            n = (n * 10) + e;
                        if(d < 10)
                            n = (n * 10) + d;
                        if(c < 10)
                            n = (n * 10) + c;
                        if(b < 10)
                            n = (n * 10) + b;
                        if(a < 10)
                            n = (n * 10) + a;
                        
                        if(n < 100000000 && isPrime(n))
                            valid.push_back(n);
                    }
                }
    
    //sort(valid.begin(), valid.end());
    set<int> noDups(valid.begin(), valid.end());
    set<int>::iterator it = noDups.begin();
    for(;it != noDups.end() && *it < start; it++);
    
    while(it != noDups.end() && *it <= end )
    {
        fprintf(fo, "%d\n", *it);
        it++;
    }
    
    fclose(f); fclose(fo);
    
    return 0;
}