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


int start[15];
int end[15];


bitset<31700> bs;

int primes[31700];

bitset<100005> segmented_sieve;

int main()
{
    //freopen("in.in", "r", stdin);
    
    int to = sqrt(1000000000) + 1;
    int to2 = sqrt(to) + 1;
    
    int lastPrime = 0;
    
    for(int i = 2; i < to; i++){
        if(!bs[i]){
            if(i <= to2){
                for(int j = i * i; j < to; j+=i){
                    bs[j] = true;
                }
            }
            primes[lastPrime++] = i;
        }
    }
    
    int t;
    scanf("%d", &t);
    
    for(int w = 0; w < t; w++){
        if(w > 0) printf("\n");
        scanf("%d %d", &start[w], &end[w]);
        start[w] = max(2, start[w]);
        end[w] = max(2, end[w]);
        segmented_sieve.set();
        for(int i = 0; i < lastPrime && primes[i] < end[w]; i++){
            double from = ceil(start[w]*1. / primes[i]*1.);
            for(int j = max(2, (int)from); j*primes[i] <= end[w]; j++){
                segmented_sieve[(j*primes[i]) - start[w] ] = false;
            }
        }
        for(int i = 0; start[w] + i <= end[w]; i++){
            if(segmented_sieve[i])
                printf("%d\n", i + start[w]);
        }
    }
    
    
    
    return 0;
}

