/*
ID: adelnob1
PROG: frac1
LANG: C++
*/

#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

bool vis[163][163];

int n;

int gcd[163][163];

double vals[163][163];

void dfs(int a, int b)
{
    if(vis[a][b]) return;
    vis[a][b] = true;
    for(int i = n; i >= 1; i--){
        for(int j = 1; j < i; j++){
            if(gcd[j][i] != 1) continue;
            if( vals[j][i] < vals[a][b]){
                dfs(j, i);
            }else{
                break;
            }
        }
    }
    printf("%d/%d\n", a, b);
    
}

int main()
{
    freopen("frac1.in", "r", stdin);
    freopen("frac1.out", "w", stdout);
    

    
    scanf("%d", &n);
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j < i; j++){
            gcd[j][i] = __gcd(i, j);
            vals[j][i] = j / (double)i;
        }
    }
    
    printf("0/1\n");
    vals[1][1] = 1.0;
    dfs(1, 1);
    
    return 0;
}