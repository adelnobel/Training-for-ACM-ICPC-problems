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

int arr[1000000];
int last, lastPrime, divv;



#define N 10000005

bitset<N> bs;
int precalc[N];

int cur;

int parents[N];

void printFactors(int n)
{
    
    int cur = n;
    while(cur != 0){
        if(parents[cur] != 0){
            printf(" x %d", cur / parents[cur]);
            cur = parents[cur];
            continue;
        }
        printf(" x %d", cur);
        cur = parents[cur];
    }
    
}


int main()
{
    //freopen("in.in", "r", stdin);
    
    lastPrime = 0;
    bs.set();
    
    bs[0] = bs[1] = 1;
    
    for(int i = 2; i < bs.size(); i++){
        if(i >= 3164) break;
            if(bs[i]){
                for(int j = i * i; j < bs.size(); j += i){
                    if(parents[j] == 0){
                        parents[j] = j / i;
                    }
                    bs[j] = 0;
                }
                arr[lastPrime++] = i;
            }
    }

    int n;
    
    while(scanf("%d", &n) != EOF)
    {
        printf("1");
        
        if(bs[n] && n != 1){
            printf(" x %d", n);
        }
        else printFactors(n);
        
        printf("\n");
        
    }
    
    return 0;
}

