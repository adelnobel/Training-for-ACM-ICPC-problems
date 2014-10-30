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

char s[3008];

int dp[1002][18285];
bool vis[1002][18285];

map< pair<int, int>, string > X;


int solve(int r, int c){
    int&ret = dp[r][c];
    if(vis[r][c]) return ret;
    vis[r][c] = true;
    ret = 0;
    
    string& s = X[make_pair(r, c)];
    //cout << s << endl;
    int cnt = 1;
    while(cnt < s.size()){
        int COL = 0, ROW = 0;
        while(isalpha(s[cnt])){
            COL = COL * 26 + s[cnt] - 'A' + 1;
            cnt++;
        }
        while(isdigit(s[cnt])){
            ROW = ROW * 10 + s[cnt] - '0';
            cnt++;
        }
        //cout << ROW << " " << COL << endl;
        ret += solve(ROW, COL);
        cnt++;
    }
    return ret;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif 
    
    int R, C, T;
    
    cin >> T;
    
    while(T--){
        X.clear();
        memset(vis, false, sizeof vis);
        scanf("%d %d", &C, &R);
        for(int i = 1; i <= R; i++){
            for(int j = 1; j <= C; j++){
                scanf("%s", s);
                if(s[0] != '='){
                    sscanf(s, "%d", &dp[i][j]);
                    vis[i][j] = true;
                }else{
                    X[make_pair(i, j)] = s;
                }
            }
        }

        //return 0;
        
        for(int i = 1; i <= R; i++){
            printf("%d", solve(i, 1));
            for(int j = 2; j <= C; j++){
                printf(" %d", solve(i, j));
            }
            printf("\n");
        }
        
        
    }
    
    
    
    
}
