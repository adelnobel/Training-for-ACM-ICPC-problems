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
int mat[102][102];
int accSum[102][102];

int main()
{
    //freopen("in.in", "r", stdin);
    
    scanf("%d", &n);
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            scanf("%d", &mat[i][j]);
            accSum[i][j] = mat[i][j];
            accSum[i][j] += accSum[i-1][j]; //Add from up!
            accSum[i][j] += accSum[i][j-1]; //Add from left
            accSum[i][j] -= accSum[i-1][j-1]; //We included the sum of this sub matrix twice! remove it once! 
        }
    }
    
    int maxi = -(1 << 30), cur;
    
    for(int x1 = 1; x1 <= n; x1++){
        for(int x2 = x1; x2 <= n; x2++){
            for(int y1 = 1; y1 <= n; y1++){
                for(int y2 = y1; y2 <= n; y2++){
                    cur = accSum[x2][y2]; //Acc sum from 0, 0 to this corner!
                    cur -= accSum[x1-1][y2]; //remove upper matrix because we don't need it included!
                    cur -= accSum[x2][y1-1]; //remove left matrix because we don't want this included
                    cur += accSum[x1-1][y1-1]; //Matrix from the diagonal was removed twice! add it once!
                    if(cur > maxi){
                        maxi = cur;
                    }
                }
            }
        }
    }
    
    printf("%d\n", maxi);
    
    
    return 0;
}
