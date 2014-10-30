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
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

bitset<45> primes;

bool isPrime(int n)
{
    if(n == 1 || n == 2) return true;
    int to = sqrt(n);
    
    for(int x = 2; x <= to; x++)
        if(n % x == 0)
            return false;
    
    return true;
}

char ret[20] = {'\0'};
char* itoa(int n){
    
    int c = 18;
    do{
        ret[c--] = (n % 10) + '0';
        n /= 10;
    }while(n > 0);
    return &ret[c+1];
}

int n;

void solve(int cur, int prev, int takenMask , string s)
{
    if(cur == n ){
        if(primes[prev + 1]){
            printf("%s\n", s.c_str());
        }
        return ;
    }
    for(int x = 1; x <= n ; x++){
        if(!((1 << x) & takenMask ) && primes[prev + x]){
            solve(cur + 1, x, (1 << x) | takenMask , s + ' ' + itoa(x));
        }
    }
}


int main()
{
    //freopen("in.in", "r", stdin);
    
    primes.set(); //Set all bits to true!
    for(int x = 2; x <= 40; x++) //Seive fro primes!
        if(isPrime(x)){
            for(int a = x * x; a <= 40; a+=x){
                primes[a] = false;
            }
        }
    
    int cc = 1;
    
    while(scanf("%d", &n) != EOF)
    {
        if(cc > 1) printf("\n");
        printf("Case %d:\n", cc++);
        solve(1, 1, 0 | (1 << 1) , "1");
    }

    return 0;
}