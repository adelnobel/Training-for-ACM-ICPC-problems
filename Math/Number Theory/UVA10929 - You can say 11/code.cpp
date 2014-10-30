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
    
    while(1){
        scanf("%s", s);
        int l = strlen(s);
        if(l == 1 && s[0] == '0') break;
        int tot = 0;
        for(int i = 0; i < l; i++){
            tot += ((i & 1) ? -1 : 1) * (s[i] - '0');
        }
        printf("%s ", s);
        if(tot % 11 == 0){
            printf("is");
        }else{
            printf("is not");
        }
        printf(" a multiple of 11.\n");
    }
    

}