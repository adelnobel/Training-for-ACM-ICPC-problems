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

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    
    int T, a, b;
    
    cin >> T;
    
    while(T--){
        scanf("%d %d", &a, &b);
        
        if(b % a == 0){
            cout << a << " " << b << endl;
        }else{
            cout << -1 << endl;
        }
        
    }
    

}