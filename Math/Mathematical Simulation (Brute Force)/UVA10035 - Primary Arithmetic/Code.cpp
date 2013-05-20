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

char n1[12];
char n2[12];
int maxiDigits;

void convToChar(ll n, char* ptr){
    
    for(int i = 0; i < 12; i++)
        *(ptr+i) = '0';
    
    int cur = 0;
    
    while(n){
        *(ptr+cur++) = '0' + n%10;
        n /= 10;
    }
    maxiDigits = max(maxiDigits, cur);
}

int solve(int carry, int cur)
{
    if(cur == maxiDigits) return carry;
    
    int res = (n1[cur] - '0') + carry + (n2[cur] - '0');
    int newCarry = 0;
    if(res > 9)
        newCarry = 1;
    
    return carry + solve(newCarry, cur+1);
    
}

int main()
{
    //freopen("in.in", "r", stdin);
    
    ll a, b;
    
    while(1){
        scanf("%lld %lld", &a, &b);
        if(a == 0 && b == 0) break;
        
        maxiDigits = 0;
        
        convToChar(a, n1);
        convToChar(b, n2);
        
        int tot = solve(0, 0);
        
        if(tot == 0){
            printf("No carry operation.\n");
        }else if(tot == 1){
            printf("1 carry operation.\n");
        }
        else{
            printf("%d carry operations.\n", tot);
        }
        
    }
    
    return 0;
}