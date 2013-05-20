#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

int* par;

int parent(int x){
    return par[x] = par[x] == x ? x : parent(par[x]);
}

void join(int a, int b){
    par[parent(a)] = parent(b);
}

bool areInSameSet(int a, int b){
    return parent(a) == parent(b);
}

char line[30];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    
    int t, scanned, n, a, b, totSucc, totUnsucc, cc = 1;
    char q;
    scanf("%d", &t);
    
    while(t--){
        scanf("%d ", &n);
        if(cc != 1) printf("\n");
        cc++;
        totSucc = totUnsucc = 0;
        par = (int*) malloc( (sizeof(int) * (n+1)) );
        for(int i = 1; i <= n; i++){
            par[i] = i;
        }
        while(gets(line) && line[0]){
            sscanf(line, " %c %d %d ", &q, &a, &b);
            if(q == 'c'){
                join(a, b);
            }else if(q == 'q'){
                if(areInSameSet(a, b)){
                    totSucc++;
                }else{
                    totUnsucc++;
                }
            }
        }
        printf("%d,%d\n", totSucc, totUnsucc);
        free(par);
    }
    
    
    return 0;
}

