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
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <bitset>


using namespace std;

typedef struct state
{
    int a, b, c;
    bool operator<(const state &s) const
    {
        if(a != s.a) return a < s.a;
        if(b != s.b) return b < s.b;
        return c < s.c;
    }
    
}state;

int n;

int ar[3];

int m[105][105];

bool vis[105][105][105];

vector< state > v;

int main()
{
    //freopen("in.in", "r", stdin);
    
    while(scanf("%d", &n) != EOF)
    {
        v.clear();
        memset(vis, false, sizeof(vis));
        for(int x = 0; x < n; x++)
        {
            for(int y = 0; y < n; y++)
            {
                scanf("%d", &m[x][y]);
            }
        }
        
        int cc = 0;
        
        for(int a = 0; a < n; a++)
        {
            for(int b = 0; b < n; b++)
            {
                if(a == b) continue;
                if(!m[a][b]) continue;
                for(int c = 0; c < n; c++)
                {
                    if(!m[b][c]) continue;
                    if(!m[c][a]) continue;
                    if(b == c || c == a) continue;
                    
                    ar[0] = a; ar[1] = b; ar[2] = c;
                    bool flag = false;
                    if(vis[ar[0]][ar[1]][ar[2]] || vis[ar[1]][ar[2]][ar[0]] || vis[ar[2]][ar[0]][ar[1]])
                        flag = true;
                    if(flag) continue;
                    
                    sort(ar, ar+3);
                    
                    bool ascending = false;
                    
                    for(int x = 0; x < 3; x++)
                    {
                        if((ar[x] == a && ar[(x+1) % 3 ] == b && ar[(x+2) % 3 ] == c) )
                            ascending = true;
                    }
                    if(!ascending)
                    {
                        sort(ar, ar+3, greater<int>());
                    }
                    vis[ar[0]][ar[1]][ar[2]] = true;
                    state s;
                    s.a = ar[0]+1; s.b = ar[1]+1; s.c = ar[2]+1;
                    
                    v.push_back(s);
                    cc++;
                }
            }
        }
        
        sort(v.begin(), v.end());
        
        for(int x = 0; x < v.size(); x++)
               printf("%d %d %d\n", v[x].a, v[x].b, v[x].c);
        
        printf("total:%d\n\n", cc);
    }
    
    return 0;
}