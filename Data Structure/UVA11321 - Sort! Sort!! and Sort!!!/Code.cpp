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

int n, m;

bool mycmp(const int a, const int b){
    
    if(a % m == b % m){
        
        if(a % 2 != 0 && b % 2 == 0){
            return true;
        }
        if(b % 2 != 0 && a % 2 == 0){
            return false;
        }
        
        if(a % 2 != 0 && b % 2 != 0){
            return a > b;
        }
        
        if(a % 2 == 0 && b % 2 == 0){
            return a < b;
        }
    }
    
    return (a % m) < (b % m);
    
}

int arr[10002];

int main()
{
    //freopen("in.in", "r", stdin);
    
    while(1){
        scanf("%d %d", &n, &m);
        printf("%d %d\n", n, m);
        if(n == 0 && m == 0) break;
        for(int i = 0;i < n; i++)
            scanf("%d", &arr[i]);
        
        sort(arr, arr+n, mycmp);
        
        for(int i = 0;i < n; i++)
            printf("%d\n", arr[i]);
        
    }
    return 0;
}