/*
ID: adelnob1
PROG: gift1
LANG: C++
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <map>
#include <vector>

using namespace std;

map<string, int> m;
char name[20];
string arr[20];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("gift1.in", "r", stdin);
    freopen("gift1.out", "w", stdout);
#endif
    
    int n, a, b, pay;
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++){
        scanf("%s", name);
        arr[i] = string(name);
        m[name] = 0;
    }
    
    for(int i = 0; i < n; i++){
        scanf("%s %d %d", name, &a, &b);
        if(b == 0) continue;
        pay = (a / b);
        m[name] -= pay * b;
        for(int i = 0; i < b; i++){
            scanf("%s", name);
            m[name] += pay;
        }
    }
    for(int i = 0; i < n; i++){
        printf("%s %d\n", arr[i].c_str(), m[arr[i]]);
    }
    
    return 0;
}

