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

/**
 * N (the number of integers), R (Number of roads)
 * Total number of different assignments = N + N * 26 (26 is the number of alphabets)
 * We can make a total of this assignments!
 * Now if the total assignments that can be made is less than the roads, then its impossible to do this!!
 * 
 * To calculate the minimum needed alphabets
 * We can represent N roads with integers only
 * then we need to represent R - N roads with integers and alphabets!
 * then
 * R - N = N * X
 * where X is the minimal number of alphabets we need!
 * solve the linear equation
 * then X = (R - N) / N
 * and we ceil the value to the nearest integer!
 */

int main()
{
    //freopen("in.in", "r", stdin);
    
    int R, N, c = 1;
    
    while(1){
        scanf("%d %d", &R, &N);
        
        if(N == 0 && R == 0) break;
        printf("Case %d: ", c++);
        if( N + N*26 >= R){
            int ret = ceil((R - N)*1. / N*1.);
            printf("%d", ret );
        }else{
            printf("impossible");
        }
        printf("\n");
    }
    


    return 0;
}