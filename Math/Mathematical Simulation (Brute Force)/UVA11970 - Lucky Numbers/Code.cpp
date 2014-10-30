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

typedef long long ll;

int main()
{
    //freopen("in.in", "r", stdin);

    int T, N;
    
    scanf("%d", &T);
    
    for(int q = 1; q <= T; q++){
        scanf("%d", &N);
        
        printf("Case %d:", q);
        
        for(int i = sqrt(N) + 1; i >= 1; i--){
            if( (N-i*i) % i == 0 && N-i*i != 0)
                printf(" %d", N-i*i);
        }
        
        printf("\n");
        
    }

    return 0;
}