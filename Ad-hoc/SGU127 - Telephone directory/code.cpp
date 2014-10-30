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
#include <bitset>

using namespace std;

typedef long long ll;



int main() {
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    
    int K, N, x;
    cin >> K >> N;
    vector< int > v;
    for(int i = 0; i < N; i++){
        scanf("%d", &x);
        v.push_back(x);
    }
    
    sort(v.begin(), v.end());
    
    int tot = 3;
    int taken = 1 % K;
    for(int i = 1; i < v.size(); i++){
        if(v[i-1] / 1000 < v[i] / 1000){
            tot++;
            taken = 1 % K;
        }else{
            if(taken == 0) tot++;
            taken++;
            taken %= K;
        }
    }
    
    cout << tot << endl;
    
    
    
    return 0;
}