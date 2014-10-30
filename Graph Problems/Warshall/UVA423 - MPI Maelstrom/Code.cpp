#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

int mat[111][111];

char s[31];

#define INF ((1 << 9) - 1)

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    int n;
    
    while(scanf("%d", &n) == 1){
 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            mat[i][j] = INF;
        }
    }
    int i;
    
    mat[0][0] = 0;
    
    for(int j = 1; j < n; j++){
         i = 0;
         while(i < j){
              scanf("%s", s);
              if(s[0] == 'x'){
                  mat[j][i] = mat[i][j] = INF;
              }else{
                  sscanf(s, "%d", &mat[j][i]);
                  mat[i][j] = mat[j][i];
              }
              i++;
         }
         mat[j][j] = 0;
   }
        
   for(int k = 0; k < n; k++){
         for(int i = 0; i < n; i++){
             for(int j = 0; j < n; j++){
                  mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
             }
        }
    }
    
    int maxi = 0;
        
    for(int i = 0; i < n; i++){
        maxi = max(maxi, mat[0][i]);
    }
    
    printf("%d\n", maxi);
    
    
    }
    return 0;
}

