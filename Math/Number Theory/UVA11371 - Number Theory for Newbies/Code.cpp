#include <cstdlib>
#include <iostream>
#include <vector>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

char s[30];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    

    while(scanf("%s", s) == 1){
        int l = strlen(s);
        sort(s, s+l, greater<char>());
        ll maxi = 0, mini;
        for(int i = 0; i < l; i++){
            maxi = maxi * 10 + s[i] - '0';
        }
        int zeros = 0;
        for(int i = l-1; i >= 0; i--){
            zeros += s[i] == '0';
        }
        mini = s[l-1-zeros] - '0';
        for(int i = 0; i < zeros; i++){
            mini *= 10;
        }
        for(int i = l-1-zeros-1; i >= 0; i--){
            mini = mini * 10 + s[i] - '0';
        }
        
        printf("%lld - %lld = %lld = 9 * %lld\n", maxi, mini, maxi - mini, (maxi-mini) / 9);
        
    }
    
    
    return 0;
}
