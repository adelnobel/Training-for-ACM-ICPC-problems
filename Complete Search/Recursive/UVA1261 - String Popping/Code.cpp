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
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <limits>
 
using namespace std;

char s[30];
int len;

bool solve(int takenMask)
{
    if( ((1 << len) - 1) == takenMask) return true;
    
    bool ret = false;
    
    int i, j;
    int newMask;
    
    for(i = 0; i < len; i++){
        if( (1 << i) & takenMask ) continue;
        newMask = takenMask;
        for(j = i + 1; j < len; j++){
            if( (1 << j) & takenMask ) continue;
            if(s[j] != s[i]) break;
            newMask |= (1 << j);
        }
        if(j - i > 1 && !((1 << j-1) & takenMask) ){ //If we could match something and the last character of matched not in the mask
            newMask |= (1 << i);
            i = j - 1;
            ret = solve(newMask) || ret;
            if(ret) return true;
        }
        
    }
    
    return ret;
}

int main()
{
    //freopen("in.in", "r", stdin);
    
    int n;
    scanf("%d", &n);
    
    while(n--)
    {
        scanf("%s", s);
        len = strlen(s);
        printf("%d\n", solve(0));
    }
    
    
    return 0;
}