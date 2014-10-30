
ID adelnob1
PROG gift1
LANG C++

#include cstdio
#include cstring
#include algorithm
#include iostream
#include cmath
#include map
#include vector

using namespace std;

int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int freqs[7];

int main()
{
#ifndef ONLINE_JUDGE
    freopen(gift1.in, r, stdin);
    freopen(gift1.out, w, stdout);
    freopen(in.in, r, stdin);
#endif
    
    int years, curYear, curDay = 1, daysInCurMonth;
    scanf(%d, &years);
    
    
    for(int i = 0; i  years; i++){
        curYear = 1900 + i;
        bool isLeap = (curYear % 4 == 0) && ((curYear % 100 != 0)  (curYear % 400 == 0));
        for(int j = 0; j  12; j++){
            daysInCurMonth = months[j];
            if(j == 1 && isLeap) {
                daysInCurMonth++;
            }
            freqs[(curDay+13)%7]++;
            curDay = (curDay + daysInCurMonth) % 7;
        }
    }
    
    printf(%d, freqs[0]);
    for(int i = 1; i  7; i++) printf( %d, freqs[i]);
    printf(n);
    
    return 0;
}

