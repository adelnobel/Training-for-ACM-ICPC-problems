#include <cstdlib>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <queue>
#include <cmath>
 
using namespace std;

typedef long long ll;

char s[(int)2e4 + 5];
int T, n, k;
int minimize(const int& len){
    int tot = 0;
    for(int i = 0; i < len;){
        int j = i+1;
        while(j < len && s[j] == s[i]) j++;
        int size = j - i;
        tot += size / k;
        if(size % k != 0) tot++;
        i = j;
    }
    return tot;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    
    
    scanf("%d", &T);

    while(T--){
        scanf("%d %d", &n, &k);
        scanf("%s", s);
        int len = strlen(s);
        int tot = 1, maxi = 1;
        for(int i = 1; i < len; i++){
            if(s[i] == s[i-1]) tot++;
            else {
                tot = 1;
            }
            maxi = max(tot, maxi);
        }
        
        if(maxi < k){
            printf("-1\n");
            continue;
        }
        
        int mini = 1e9;
        
        
        mini = min(mini, minimize(len));
        
        printf("%d\n", mini);
        
    }
    
    return 0;
}