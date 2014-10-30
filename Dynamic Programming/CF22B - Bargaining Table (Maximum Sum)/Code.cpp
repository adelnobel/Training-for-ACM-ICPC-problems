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

int accSum[27][27];


int main()
{
    //freopen("in.in", "r", stdin);
    
    int n, m;
    
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            scanf("%1d", &accSum[i][j], 1); //Scan only 1 digit!
            accSum[i][j] += accSum[i-1][j];
            accSum[i][j] += accSum[i][j-1];
            accSum[i][j] -= accSum[i-1][j-1];
        }
    }
    
    int maxi = 0, curRectSum;
    
    for(int a = 1; a <= n; a++){
        for(int b = a; b <= n; b++){
            for(int c = 1; c <= m; c++){
                for(int d = c; d <= m; d++){
                    curRectSum = accSum[b][d];
                    curRectSum -= accSum[a-1][d];
                    curRectSum -= accSum[b][c-1];
                    curRectSum += accSum[a-1][c-1];
                    if(curRectSum == 0){ //If this sub rectangle doesn't contain any zeroes!
                        maxi = max(maxi, (((b - a) + 1) + ((d - c) + 1)) * 2 ); //Perimeter of rectangle = (width + height) * 2
                    }
                }
            }
        }
    }
    
    
    cout << maxi;

    return 0;
}
