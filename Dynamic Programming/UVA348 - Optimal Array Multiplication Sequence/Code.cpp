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

int n;

int rowsArr[30];
int colsArr[30];

string memoS[15][15];
ll memoCost[15][15];

char stoi[5];

pair<ll, string> solve(ll left, ll right)
{
    if(left == right) {
        sprintf(stoi, "%d", left+1);
        string ret = "A"; ret += stoi;
        return make_pair(0, ret);
    }
    
    if(memoCost[left][right] != -1) return make_pair(memoCost[left][right], memoS[left][right]);
    
    ll mini = 1 << 30, multiplicationCost;
    mini <<= 30; //Shift long long for more than 31 bits by doing it on two times!!!
    pair<ll, string> ret, leftSol, rightSol;
    
    for(int i = left; i < right; i++){
        leftSol = solve(left, i);
        rightSol = solve(i+1, right); 
        multiplicationCost = (rowsArr[left] * colsArr[right] * colsArr[i]);
        
        if(mini >= leftSol.first + rightSol.first + multiplicationCost){
            mini = leftSol.first + rightSol.first + multiplicationCost;
            ret.first = mini;
            ret.second = "";
            ret.second += "(" + leftSol.second + " x " + rightSol.second + ")";
        }
    }
    
    memoCost[left][right] = ret.first;
    memoS[left][right] = ret.second;
    
    return ret;   
}

int main()
{
    //freopen("in.in", "r", stdin);
    int cc = 1;
    while(1)
    {
        scanf("%d", &n);
        if(n == 0) break;
        memset(memoCost, -1, sizeof(memoCost));
        for(int i = 0; i < n; i++)
            scanf("%d %d", &rowsArr[i], &colsArr[i]);
        

        printf("Case %d: %s\n", cc++, solve(0, n-1).second.c_str());
    }
    
    
    
    return 0;
}
