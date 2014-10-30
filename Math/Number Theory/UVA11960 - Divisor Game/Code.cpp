/* In the name of ALLAH, most gracious, most merciful */
#include <cstring>
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
#include <tr1/unordered_set>

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

#define N 1000005

int divv[N];
int ans[N];

int main() 
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    for(int i = 0; i < N; i++){
        divv[i] = 1;
    }
    for(int i = 2; i < N; i++){
        if(divv[i] == 1){
            for(int j = i+i; j < N; j += i){
                int x = j, tot = 0;
                while(x % i == 0){
                    ++tot;
                    x /= i;
                }
                divv[j] *= tot + 1;
            }
        }
    }
    int best = 1;
    for(int i = 1; i < N; i++){
        if(divv[i] >= divv[best]) best = i;
        ans[i] = best;
    }
    
    int T, n;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        printf("%d\n", ans[n]);
    }
    
    
    
    return 0;
}