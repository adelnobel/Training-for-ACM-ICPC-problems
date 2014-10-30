/*
ID: adelnob1
PROG: beads
LANG: C++
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <map>
#include <vector>

using namespace std;

char s[360];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("beads.in", "r", stdin);
    freopen("beads.out", "w", stdout);
    //freopen("in.in", "r", stdin);
#endif
    
    int n, maxi = 0, tot, ptr;
    scanf("%d", &n);
    scanf("%s", s);
    
    for(int i = 0; i < n; i++){
        tot = 0;
        int j = ptr = i;
        while( (s[j] == s[ptr] || s[j] == 'w') && tot < n ){
            j = (j+1) % n, tot++;
            if(s[ptr] == 'w' && s[j] != 'w') ptr = j;
        }
        ptr = j;
        while( (s[j] == s[ptr] || s[j] == 'w') && tot < n ) {
            j = (j+1) % n, tot++;
            if(s[ptr] == 'w' && s[j] != 'w') ptr = j;
        }
        maxi = max(tot, maxi);
    }
    
    printf("%d\n", maxi);
    
    return 0;
}

