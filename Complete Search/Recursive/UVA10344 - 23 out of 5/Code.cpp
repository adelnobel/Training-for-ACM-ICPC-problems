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

using namespace std;

int ar[6];

bool valid(int leftVal, int cur)
{
    if(cur == 5){
        if(leftVal == 23) return true;
        return false;
    }
    
    return valid( leftVal + ar[cur], cur + 1 ) || valid( leftVal - ar[cur], cur + 1 ) || valid( leftVal * ar[cur], cur + 1 );
}

int main()
{
    //freopen("in.in", "r", stdin);
    
    while(1)
    {
        bool stop = true;
        for(int i = 0; i < 5; i++){
            scanf("%d", &ar[i]);
            if(ar[i] != 0) stop = false;
        }
        if(stop) break;
        sort(ar, ar+5);
        bool possible = false;
        do
        {
            possible = valid(ar[0], 1);
        }while(next_permutation(ar, ar+5) && !possible);
        
        if(possible){
            printf("Possible\n");
        }
        else{
            printf("Impossible\n");
        }
    }
    
    return 0;
}