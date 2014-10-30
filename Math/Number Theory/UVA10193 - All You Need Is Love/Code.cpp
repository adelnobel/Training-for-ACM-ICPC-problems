#include <vector>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <bitset>
#include <map>
#include <complex>
#include <ctime>
#include <numeric>

using namespace std;

typedef long long ll;

char s1[40], s2[40];

int conv(char s[], int l){
    int ret = 0;
    for(int i = 0; i < l; i++){
        if(s[i] == '1')
        ret |= (1 << (l-i-1));
    }
    return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    
    int t, a, b, c = 1;
    scanf("%d", &t);
    
    while(t--){
        scanf("%s %s", s1, s2);
        a = conv(s1, strlen(s1));
        b = conv(s2, strlen(s2));
        printf("Pair #%d: ", c++);
        printf(__gcd(a, b) > 1 ? "All you need is love!\n" : "Love is not all you need!\n");
    }
    
    return 0;
}