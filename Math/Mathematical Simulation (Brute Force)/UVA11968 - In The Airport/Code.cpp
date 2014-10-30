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

int drinks[1005];
int cakes[1005];

int main()
{
    //freopen("in.in", "r", stdin);
    
    int N, M, K, x, t, bestDrink, bestCake;
    ll tot;
    long double avg, bestDrinkDiff, bestCakeDiff;
    
    scanf("%d", &t);
    
    for(int q = 1; q <= t; q++){
        
        scanf("%d %d %d", &N, &M, &K);
        
        tot = 0;
        
        for(int i = 0; i < M; i++){
            scanf("%d", &cakes[i]);
            tot += cakes[i];
        }
        
        for(int i = 0; i < K; i++){
            scanf("%d", &drinks[i]);
            tot += drinks[i];
        }
        
        for(int i = 0, to = N - M - K; i < to; i++){
            scanf("%d", &x);
            tot += x;
        }
        
        avg = (tot*1.) / (N*1.);
        
        bestDrinkDiff = bestCakeDiff = (1 << 30) * 1.9;
        bestDrink = bestCake = 0;
        
        for(int i = 0; i < K; i++){
            if(fabs(drinks[i] - avg) < bestDrinkDiff || (fabs(drinks[i] - avg) == bestDrinkDiff && drinks[i] < drinks[bestDrink] ) ){
                bestDrinkDiff = fabs(drinks[i] - avg);
                bestDrink = i;
            }
        }
        
        for(int i = 0; i < M; i++){
            if(fabs(cakes[i] - avg) < bestCakeDiff || (fabs(cakes[i] - avg) == bestCakeDiff && cakes[i] < cakes[bestCake] ) ){
                bestCakeDiff = fabs(cakes[i] - avg);
                bestCake = i;
            }
        }
        
        printf("Case #%d: %d %d\n", q, cakes[bestCake] ,drinks[bestDrink]);
        
    }

    return 0;
}