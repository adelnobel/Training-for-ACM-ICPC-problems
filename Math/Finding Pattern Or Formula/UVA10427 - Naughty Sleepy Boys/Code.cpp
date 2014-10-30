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

int startP[10];
int endP[10];


int pow(int a, int b)
{
    if(a == 0) return 1;
    return b * pow(a-1, b);
}

char num[10];

char getDigit(int n, int t)
{
    int ret, cnt = 0;
    while(n > 0){
        num[cnt] = (n%10) + '0';
        n /= 10;
        cnt++;
    }
    return num[cnt-t-1];
}

int main()
{
    //freopen("in.in", "r", stdin);
    int n;
    int cur = 0;
    int cnt = 1;
    
    while(cur <= 100000000){
        cur = ( pow(cnt-1, 10) * 9) * cnt;
        endP[cnt] = cur + endP[cnt-1];
        startP[cnt] = endP[cnt-1] + 1;
        cnt++;
    }
    
    int pos = 0;
    
    while(scanf("%d", &n) != EOF){
        for(int i = 1; i <= 8; i++){
            if(n >= startP[i] && n <= endP[i]){
                pos = i;
                break;
            }
        }
        
        int modForPrev = (n - startP[pos]) % pos;
        
        int previousStart = n - modForPrev;
        int startingNumber = pow(pos-1, 10);
        
        int distFromStarting = (previousStart - startP[pos]) / pos;
        
        int number = distFromStarting + startingNumber;
        
        int targetDigit = modForPrev;
        
        int digit = getDigit(number, targetDigit);
        
        printf("%c\n", digit);
        
    }
    
    
    return 0;
}