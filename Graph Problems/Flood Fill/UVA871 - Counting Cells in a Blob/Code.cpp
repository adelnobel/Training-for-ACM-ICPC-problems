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
 
using namespace std;

bool vis[27][27];

char s[27][27];

int w, h;

int fill(int x, int y)
{
    if(vis[x][y]) return 0;
    if(x < 0 || y < 0 || x >= w || y >= h || s[x][y] == '0'){
        return 0;
    }
    
    int ret = 0;
    
    vis[x][y] = true;
    
    for(int a = -1; a <= 1; a++ )
        for(int b = -1; b <= 1; b++){
            if(a == 0 && b == 0) continue;
            ret += fill(x+a, y+b);
        }
    
    
    return ret+1;
}

int main()
{
    //freopen("in.in", "r", stdin);
    
    int n, cc = 1;
    scanf("%d", &n);
    gets(s[0]);
    gets(s[0]);
    
    while(n--)
    {
        if(cc++ > 1) printf("\n");
        
        h = 0;
        while(1){
            s[h][0] = '\0';
            gets(s[h]);
            if(s[h][0] == '\0') break;
            h++;
        }
        
        if(h == 0) w = 0;
        else w = strlen(s[h-1]);
        
        memset(vis, false, sizeof(vis));
        int maxi = 0;
        
        for(int x = 0; x < 5; x++){
            for(int y = 0; y < 5; y++){
                if(!vis[x][y]){
                    maxi = max(maxi, fill(x, y));
                }
            }
        }
        
        printf("%d\n", maxi);
    }
    
    return 0;
}