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

typedef struct record{
    int arr[5];
    bool operator<(const record &r) const {
        for(int i = 0; i < 5; i++){
            if(arr[i] != r.arr[i]) return arr[i] < r.arr[i];
        }
        return false;
    }
    
    bool operator==(const record &r) const {
        for(int i = 0; i < 5; i++){
            if(arr[i] != r.arr[i]) return false;
        }
        return true;
    }
    
}record;

record arr[10001];

int vals[10001];

int main()
{
    //freopen("in.in", "r", stdin);
    
    int n, prevN = 0;
    
    
    while(1){
        scanf("%d", &n);
        if(n == 0) break;
        
        for(int i = 0; i <= n; i++){
            vals[i] = 0;
        }
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 5; j++){
                scanf("%d", &arr[i].arr[j]); 
            }
            sort(arr[i].arr, arr[i].arr+5);
        }
        prevN = n;
        
        sort(arr, arr+n);
        
        int i = 0, j = 0, maxi = 0;
        
        while(i < n){
            j = i + 1;
            while(j < n && arr[i] == arr[j]){
                j++;
            }
            vals[j-i]++;
            maxi = max(maxi, j-i);
            i = j;
        }
        
        printf("%d\n", vals[maxi] * maxi);
    }
    
    
    return 0;
}
