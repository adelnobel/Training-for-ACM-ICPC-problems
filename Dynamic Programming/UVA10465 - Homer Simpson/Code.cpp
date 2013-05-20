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



#define N 10001
#define INF 1 << 30

int burgersDP[N];
int timeDP[N];
int m, n, t;

pair<int, int> solve(int timeRemaining)
{
    if(timeRemaining < 0){
        return make_pair(-INF, INF);
    }
    if(timeRemaining == 0){
        return make_pair(0, 0);
    }
    
    if(burgersDP[timeRemaining] != -1){
        return make_pair(burgersDP[timeRemaining], timeDP[timeRemaining]);
    }
    
    //We have three possiblities, either eat burger m, or burger n or STOP eating! 
    pair<int, int> ret = make_pair(0, timeRemaining); //Stop eating case
    pair<int, int> EatBurgerM = solve(timeRemaining - m); //Eat burger m
    pair<int, int> EatBurgerN = solve(timeRemaining - n); //Eat burger n
    
    EatBurgerN.first++; 
    EatBurgerM.first++;
    
    if(ret.second >= EatBurgerN.second)
        ret = EatBurgerN;
    
    if(ret.second == EatBurgerM.second)
        if(ret.first < EatBurgerM.first)
            ret = EatBurgerM;
    
    if(ret.second > EatBurgerM.second )
        ret = EatBurgerM;
    
    
    burgersDP[timeRemaining] = ret.first;
    timeDP[timeRemaining] = ret.second;
    
    return ret;
    
}

int main()
{
    //freopen("in.in", "r", stdin);
    
    while(scanf("%d %d %d", &m, &n, &t) != EOF)
    {
        memset(burgersDP, -1, sizeof(burgersDP));
        pair<int, int> sol = solve(t);
        
        if(sol.second == 0)
            printf("%d\n", sol.first);
        else
            printf("%d %d\n", sol.first, sol.second);
    }
    
    return 0;
}