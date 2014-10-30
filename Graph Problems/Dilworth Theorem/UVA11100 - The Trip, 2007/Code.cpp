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
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;

map<int, int> M;

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    
    int n, t = 1, x;
    
    while(1){
        scanf("%d", &n);
        if(n == 0) break;
        if(t != 1) printf("\n");
        t = 0;
        M.clear();
        for(int i = 0; i < n; i++){
            scanf("%d", &x);
            ++M[x];
        }
        
        int ans = 0;
        map<int ,int>::iterator it;
        for(it = M.begin(); it != M.end(); it++){
            ans = max(ans, it->second);
        }
        printf("%d\n", ans);
        int maxi = n / ans + (n % ans != 0);
        

        while(!M.empty()){
            int c = 0;
            vector< map<int, int>::iterator > remove;
            for(it = M.begin(); it != M.end() && c < maxi; it++){
                if(c != 0) printf(" ");
                c++;
                printf("%d", it->first);
                it->second--;
                if(it->second == 0) remove.push_back(it);
            }
            printf("\n");
            for(int i = 0; i < remove.size(); i++){
                M.erase(remove[i]);
            }
        }
        
        
    }
    

    return 0;
}