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

int N, L;
bool flag;
int ar[15];

int valid[15];

int available[101];

set<string> final;

char* itoa(int val, int base){
    static char buf[32] = {0};
    int i = 30;
    for(; val && i ; --i, val /= base)
        buf[i] = "0123456789abcdef"[val % base];
    return &buf[i+1];
}

void solve(int cur, int remaining, string s)
{
    if(remaining == 0) {
        if(final.count(s) == 0){
            int tot = s.size() - 1;
            while(tot--)
                printf("%c", s[s.size() - 2 - tot]);
            printf("\n");
            final.insert(s);
        }
        return;
    }
    if(cur >= L) return;
    if(remaining < 0) return;

    
    for(int x = cur+1; x <= L; x++)
        solve(x, remaining - ar[cur], s + itoa(ar[cur], 10) + "+");
}

int main()
{
    //freopen("in.in", "r", stdin);
    
    while(1)
    {
        scanf("%d %d", &N, &L);
        if(N == 0) break;
        for(int x = 0; x < L; x++){
            scanf("%d", &ar[x]);
        }
        
        printf("Sums of %d:\n", N);
        for(int x = 0; x < L; x++)
            solve(x, N, "");
        if(final.size() == 0)
            printf("NONE\n");
        
        final.clear();
        
    }
    return 0;
}