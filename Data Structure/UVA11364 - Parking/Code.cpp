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

int arr[50];

/**
NBo need to brute force, simple math
the element that has the minimum total distance to all other nodes is the MEDIAN in the sorted array!
**/

int main()
{
    //freopen("in.in", "r", stdin);
    int t, n;
    
    scanf("%d", &t);
    
    while(t--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d", &arr[i]);
        
        sort(arr, arr+n);
        
        int median = n / 2;
        median -= 1; //0 Indexed!
        
        printf("%d\n", ((arr[n-1] - arr[median]) * 2) + ((arr[median] - arr[0]) * 2));
        
        
    }
    

    return 0;
}