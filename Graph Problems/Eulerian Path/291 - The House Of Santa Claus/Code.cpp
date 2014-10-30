#include <cstdlib>
#include <iostream>
#include <vector>
#include <cstring>
#include <cassert>
#include <cstdio>
using namespace std;

typedef long long ll;

bool A[6][6];

char S[11];
int cur;
vector< string > ans;

bool check(){
    for(int i = 1; i <= 5; i++){
        for(int j = 1; j <= 5; j++){
            if(A[i][j]) return false;
        }
    }
    return true;
}

void solve(int v){
    if(check()){
        S[cur] = '0' + v;
        S[cur+1] = '\0';
        ans.push_back(S);
        //assert(false);
        return;
    }
    //for(int i = 0; i < cur; i++) printf("-");
    //cout << v << endl;
    for(int i = 1; i <= 5; i++){
        //if(min(v, i) == 2 && max(v, i) == 5) cout << "HERE";
        if(A[v][i]){
            A[v][i] = A[i][v] = false;
            S[cur++] = '0' + v;
            solve(i);
            A[v][i] = A[i][v] = true;
            cur--;
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    
    A[1][5] = A[1][3] = A[1][2] = A[2][1] = A[2][3] = A[2][5] = A[3][1] = A[3][2] = A[3][4] = A[3][5] = 
            A[4][3] = A[4][5] = A[5][4] = A[5][3] = A[5][2] = A[5][1] = true;
    
    cur = 0;
    
    solve(1);

    for(int i = 0; i < ans.size(); i++){
        printf("%s\n", ans[i].c_str());
        if(i > 0) assert(ans[i] > ans[i-1]);
    }
    
    
    return 0;
}
