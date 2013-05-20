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
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <limits>
#include <tr1/unordered_map>

using namespace std;


int BIT[10][1000001];

bitset<1000001> bs;

int distinctPrimes[1000001];

void updateBIT(int x, int y){
    
    do{
        BIT[x][y] += 1;
        y += y & (-y);
    }while(y < 1000001);
}

int getSum(int x, int to)
{
    int ret = 0;
    
    do{
        ret += BIT[x][to];
        to -= to & (-to);
    }while(to > 0);
    
    return ret;
}

int main()
{
    //freopen("in.in", "r", stdin);
    
    int a, b, t, n;
    
    for(int i = 2; i < 1000001; i++){
        if(!bs[i]){
            for(int j = 2*i; j < 1000001; j+=i){
                bs[j] = true;
                distinctPrimes[j]++;
            }
        }
    }
    
    for(int i = 2; i < 1000001; i++){
        if(distinctPrimes[i] == 0) updateBIT(0, i);
        else{
            if(distinctPrimes[i]-1 < 10)
                updateBIT(distinctPrimes[i]-1, i);
            /**
            for(int j = min(10, distinctPrimes[i]) - 1; j >= 0; j--){
                updateBIT(j, i);
            }**/
        }
    }
    
    
    scanf("%d", &t);
    
    while(t--){
        scanf("%d %d %d", &a, &b, &n);
        
        if(a > b)
            swap(a, b);
        
        if(n == 0){
            if(1 >= a && 1 <= b)
                printf("1\n");
            else
                printf("0\n");
            continue;
        }
        
        int st = getSum(n-1, b);
        int nd = getSum(n-1, a-1);
        
        printf("%d\n", st - nd);
        
    }
    
    
    return 0;
}