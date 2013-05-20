#include <cstring>
#include <algorithm>
#include <functional>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <queue>

using namespace std;

#define MAXN 505
#define INF 1 << 30

int a, n, k, l, t, w, pos;

int menP[MAXN][MAXN];
int womenP[MAXN][MAXN];

int matchWomen[MAXN];

int manLastMatched[MAXN];

bool isMorePreferable(int man, int woman)
{
    if(matchWomen[woman] == INF) return true;
    if(womenP[woman][matchWomen[woman]] > womenP[woman][man]) return true; //if current matched man is less good than this man, then return true
    return false;
}

void makeTheMatches(queue<int> &next)
{
    while(!next.empty())
    {
        int cur = next.front(); next.pop();
        ++manLastMatched[cur]; //Move this man's last match to next woman
        int woman = menP[cur][manLastMatched[cur]];
        if(isMorePreferable(cur, woman)) //If this man is more preferable to this woman!
        {
            if(matchWomen[woman] != INF) //If previous man was not INF (Initial value!)
                next.push(matchWomen[woman]); //We put the previous man on the queue to find another match for!!
            matchWomen[woman] = cur; //Update current match for this woman to equal this current man!
        }
        else //If this person is not more preferable than the previous man this woman was engaged to!
        {
            next.push(cur); //Push this man again to the queue!
        }
    }
}

int main() 
{
    //freopen("in2.in", "r", stdin);
    
    scanf("%d", &t);
    while(t--)
    {
        queue<int> next;
        memset(manLastMatched, 0, sizeof(manLastMatched));
        scanf("%d", &n);
        for(int x = 0; x <= n; x++)
            matchWomen[x] = INF;
        for(int x = 1; x <= n; x++)
        {
            scanf("%d", &w);
            next.push(w);
            for(int y = 1; y <= n; y++)
            {
                scanf("%d", &pos);
                womenP[x][pos] = y;
            }
        }
        
        for(int x = 1; x <= n; x++)
        {
            scanf("%d", &w);
            for(int y = 1; y <= n; y++)
            {
                scanf("%d", &menP[x][y]);
            }
        }
        
        makeTheMatches(next);
        
        for(int x = 1; x <= n; x++)
        {
            printf("%d %d\n", x, menP[x][manLastMatched[x]] );
        }
        
    }
    
    return 0;
}