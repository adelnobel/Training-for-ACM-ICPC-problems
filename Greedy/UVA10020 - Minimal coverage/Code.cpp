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
    
    int L, G, x, r, T;
    bool isFirst = true;
    scanf("%d", &T);
    
    while(T--){
        if(!isFirst) printf("\n");
        isFirst = false;
        scanf("%d", &L);
        vector< pi > v;
        for(;;){
            scanf("%d %d", &x, &r);
            if(x == 0 && r == 0) break;
            v.push_back(pi(x, r));
        }
        bool valid = true;
        int tot = 1;
        int last = 0;
        int maxiCovered = 0;
        sort(v.begin(), v.end());
        
        vector< pi > ans;
        ans.push_back(v[0]);
        for(int i = 0; i < v.size() && valid; i++){
            if(maxiCovered >= L) break;
            if(v[i].first <= last && v[i].second >= last){
                if(v[i].second > maxiCovered){
                    ans[ans.size() - 1] = v[i];
                    maxiCovered = v[i].second;
                }
            }else if(v[i].first > last){
                if(v[i].first > maxiCovered){
                    valid = false;
                }else{
                    if(v[i].second > maxiCovered){
                        tot++;
                        last = maxiCovered;
                        maxiCovered = v[i].second;
                        ans.push_back(v[i]);
                    }
                }
            }
        }
        
        if(maxiCovered < L) valid = false;
        
        printf("%d\n", valid ? tot : 0);
        if(valid){
            for(int i = 0; i < ans.size(); i++){
                printf("%d %d\n", ans[i].first, ans[i].second);
            }
        }
        
        
    }
    
    return 0;
}