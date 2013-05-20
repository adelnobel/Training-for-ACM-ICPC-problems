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

bitset<1000001> bs;

int positions[1000001];
 
int main()
{
    //freopen("in.in", "r", stdin);
        int t, n, cube;
    
        scanf("%d", &t);

        for(int i = 2; i < 1001; i++){
            if(!bs[i]){
                int cube = i*i*i;
                
                for(int j = cube; j < 1000001; j+=cube){
                    positions[j] = -1;
                }
                
                for(int j = i*i; j < 1000001; j+=i){
                    bs[j] = true;
                }
                
            }
        }
        
        int cur = 1;
        
        for(int i = 1; i < 1000001; i++){
            if(positions[i] != -1)
                positions[i] = cur++;
        }
        
        for(int w = 1; w <= t; w++){

            scanf("%d", &n);
            printf("Case %d: ", w);
            if(positions[n] != -1)
                printf("%d\n", positions[n]);
            else
                printf("Not Cube Free\n");
        }
    
    
    return 0;
}