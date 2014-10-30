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

char s[1005];

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    int n, x;
    while(1){
        scanf("%d", &n);
        if(n == 0) break;
        int v = 0;
        for(int i = 0; i < n; i++){
            scanf("%d", &x);
            v ^= x;
        }
        if(v > 0){
            printf("Yes\n");
        }else{
            printf("No\n");
        }
    }
    

}