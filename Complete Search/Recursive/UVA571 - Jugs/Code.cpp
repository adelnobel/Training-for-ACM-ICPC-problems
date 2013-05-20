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
 
using namespace std;

int aCap, bCap, goal;

int vis[1001][1001];

bool vi[1001][1001];

int recons[1001][1001];


int solve(int a, int b)
{
    if(b == goal) {
        return 0; //Return 0 we reached!
    }
    if( vis[a][b] != -1 ) return vis[a][b]; //If we already computed this before 
    
    if(vi[a][b]) return 1000000; //If visited before but still doesn't have a value, return! its gonna be computed! and this is clearly a longer path than the one that's still not computed..
    
    vi[a][b] = true; //Set to visited so we don't go in an infinite loop!
    
    int curCost = solve(aCap, b); //Fill A
    int mini = curCost;
    int best = 1;
    
    curCost = solve(a, bCap);  //Fill B
    if(curCost < mini){
        best = 2;
        mini = curCost;
    }
    
    curCost = solve(0, b); //Empty A
    
    if(curCost < mini){
        best = 3;
        mini = curCost;
    }
    
    curCost = solve(a, 0); //Empty B
    if(curCost < mini){
        best = 4;
        mini = curCost;
    }
    
    int mi;
    
    mi = min(a, bCap - b);
    curCost = solve(a-mi, b+mi); //Pour A into B
    if(curCost < mini){
        best = 5;
        mini = curCost;
    }
    
    mi = min(aCap - a, b);
    curCost = solve(a+mi, b-mi); //Pour B into A
    if(curCost < mini){
        best = 6;
        mini = curCost;
    }
    
    vis[a][b] = mini + 1;
    recons[a][b] = best;
    
    return vis[a][b];
}

char commands[][30] = {"fill A",
"fill B",
"empty A",
"empty B",
"pour A B",
"pour B A"};

int main()
{
    //freopen("in.in", "r", stdin);
    
    int prevL = 1000;
    
    while(scanf("%d %d %d", &aCap, &bCap, &goal) != EOF)
    {
        for(int i = 0; i <= prevL; i++){
            for(int j = 0; j <= prevL; j++){ //Resetting values!
                vis[i][j] = -1;
                recons[i][j] = -1;
                vi[i][j] = false;
            }
        }
        
        prevL = max(aCap, bCap);
        
        solve(0, 0);
        
        int a = 0;
        int b = 0;

        int mi;
        
        while( b != goal ){ //Reconstructing the path!
            printf("%s\n", commands[ recons[a][b] - 1 ]);
            switch (recons[a][b]){
                case 1:{
                    a = aCap;
                    b = b;
                    break;
                }
                case 2:{
                    a = a;
                    b = bCap;
                    break;
                }
                case 3:{
                    a = 0;
                    break;
                }
                case 4:{
                    b = 0;
                    break;
                }
                case 5:{
                    mi = min(a, bCap - b);
                    a = a - mi;
                    b = b + mi;
                    break;
                }
                case 6:{
                    mi = min(aCap - a, b);
                    a = a+mi;
                    b = b-mi;
                    break;
                }
            }
        }
        
        printf("success\n");
    }
    
    
    return 0;
}