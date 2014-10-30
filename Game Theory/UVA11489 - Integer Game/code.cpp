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

using namespace std;


typedef long long ll;

char s[1010];

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    

    int T, t = 1;
    
    cin >> T;
    
    while(T--){
        scanf("%s", s);
        printf("Case %d: ", t++);
        int l = strlen(s);
        int mod = 0;
        int tot = 0;
        for(int i = 0; i < l; i++){
            mod += s[i] - '0';
            if( (s[i] - '0') % 3 == 0) tot++;
        }
        bool S = false;
        mod %= 3;
        if(mod == 0){
            if(tot % 2 == 1) S = true;
        }else{
            bool found = false;
            for(int i = 0; i < l; i++){
                if( (mod - s[i] - '0') % 3 == 0){
                    found = true;
                    break;
                }
            }
            if(found){
                if(tot % 2 == 0) S = true;
            }
        }
        
        printf("%c\n", S ? 'S' : 'T');
    }
    
    

}