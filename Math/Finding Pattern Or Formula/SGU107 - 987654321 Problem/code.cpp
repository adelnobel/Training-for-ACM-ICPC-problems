#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
#include <set>
#include <cassert>
#include <ctime>

using namespace std;

typedef long long ll;

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    /**
    int tot = 0;
    for(ll i = 1000000000; i < 10000000000LL; i++){
        if(i%1000000000*i%1000000000%1000000000 == 987654321){
            tot++;
            cerr << i << endl;
            cerr << tot << endl;
        }
    }
    cout << tot << endl;
    return 0;**/
    
    int N;
    
    cin >> N;
    
    if(N < 9){
        cout << 0 << endl;
    }else if(N == 9){
        cout << 8 << endl;
    }else{
        N -= 10;
        printf("72");
        while(N > 0){
            printf("0");
            --N;
        }
        printf("\n");
    }
    
    
    return 0;
}