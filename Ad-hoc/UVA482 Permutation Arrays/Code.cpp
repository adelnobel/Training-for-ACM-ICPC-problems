#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>

using namespace std;

char s[100000];

int permutedArr[100000];
char str[100000][50];

int main()
{
    //freopen("in2.in", "r", stdin);
    int n, a, cc = 0;
    scanf("%d", &n);
    gets(s);
    while(n--)
    {
        cc++;
        if(cc > 1) printf("\n");
        gets(s);
        gets(s);
        int lastOffset = 0;
        char* ptr = s;
        int c = 0;
        int maxi = 1;
        while(sscanf(ptr, "%d%n", &permutedArr[c], &lastOffset) != EOF)
        {
            ptr += lastOffset;
            maxi = max(maxi, permutedArr[c]);
            c++;
        }
        gets(s);
        ptr = s;
        c = 0;
        while(sscanf(ptr, "%s%n", str[permutedArr[c]], &lastOffset) != EOF)
        {
            ptr += lastOffset;
            c++;
        }
        
        for(int x = 1; x <= maxi; x++)
            printf("%s\n", str[x]);
        
    }
    
    return 0;
}