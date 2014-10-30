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
#include <set>
#include <cassert>

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    
    int L, G, x, r;
    
    while(1){
        scanf("%d %d", &L, &G);
        if(!L && !G) break;
        vector< pi > v;
        for(int i = 0; i < G; i++){
            scanf("%d %d", &x, &r);
            v.push_back(pi(x - r, x + r));
        }
        bool valid = true;
        int tot = 1;
        int last = 0;
        int maxiCovered = 0;
        sort(v.begin(), v.end());
        
        for(int i = 0; i < v.size() && valid; i++){
            //printf("%d %d\n", v[i].first, v[i].second);
            if(maxiCovered >= L) break;
            if(v[i].first <= last && v[i].second >= last){
                maxiCovered = max(maxiCovered, v[i].second);
            }else if(v[i].first > last){
                if(v[i].first > maxiCovered){
                    valid = false;
                }else{
                    if(v[i].second > maxiCovered){
                        tot++;
                        last = maxiCovered;
                        maxiCovered = v[i].second;
                    }
                }
            }
        }
        
        if(maxiCovered < L) valid = false;
        
        printf("%d\n", valid ? G - tot : -1);
        
        
    }
    
    return 0;
}