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

pair<int, int> ri; 
pair<int, int> le;

pair<int, int> pieces[20];

int n, m;

void swap(int i)
{
    int temp = pieces[i].first;
    pieces[i].first = pieces[i].second;
    pieces[i].second = temp;
}

bool solve(int previous, int remaining, int takenMask)
{
    if(remaining == 1) {
        if(le.second == pieces[previous].first) return true;
        return false;
    }
    bool ret = false;
    
    for(int i = 0; i < m && !ret; i++){
        if( (1 << i) & takenMask ) continue;
        if(pieces[i].second == pieces[previous].first) {
            ret |= solve(i, remaining - 1, takenMask | (1 << i));
        }
        else if(pieces[i].first == pieces[previous].first) {
            swap(i);
            ret |= solve(i, remaining - 1, takenMask | (1 << i));
        }
    }
    
    return ret;
    
}


int main()
{
    //freopen("in.in", "r", stdin);
    int a, b;
    while(1)
    {
        scanf("%d", &n);
        if(n == 0) break;
        scanf("%d", &m);
        
        scanf("%d %d", &le.first, &le.second);
        scanf("%d %d", &ri.first, &ri.second);
        
        for(int i = 0; i < m; i++)
            scanf("%d %d", &pieces[i].first, &pieces[i].second);
        
        pieces[m] = ri;
        
        if(solve(m , n, 0)){
            printf("YES\n");
        }else{
            printf("NO\n");
        }
        
    }
    
    
    
    return 0;
}