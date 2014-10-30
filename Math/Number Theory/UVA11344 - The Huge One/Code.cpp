#include <cstdlib>
#include <iostream>
#include <vector>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef long long ll;

char s[1008];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    
    
    int T, x, n;
    scanf("%d", &T);
    
    while(T--){
        scanf("%s", s);
        int l = strlen(s);
        scanf("%d", &n);
        assert(n <= 12);
        bool ok = true;
        for(int i = 0; i < n; i++){
            scanf("%d", &x);
            int mod = 0;
            for(int j = 0; j < l; j++){
                mod = (mod * 10 + s[j] - '0');
                mod %= x;
            }
            ok &= mod == 0;
        }
        printf("%s - ", s);
        printf(ok ? "Wonderful." : "Simple.");
        printf("\n");
    }
    
    
    return 0;
}
