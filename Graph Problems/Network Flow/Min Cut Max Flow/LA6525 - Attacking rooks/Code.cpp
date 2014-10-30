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
#include <cassert>
#include <tr1/unordered_set>
#include <tr1/unordered_map>

using namespace std;
using namespace tr1;

typedef pair<int, int> pi;
typedef long long ll;
typedef long double ld;

const int N = 105;
const int NN = N * N;

char G[N][N];
pi X[N][N];

vector< int > adj[NN];

int visLeft[NN];
int match[NN];
int visRight[NN];
int curLeftCounter, curRightCounter;

int Aug(int l){
    if(visLeft[l] == curLeftCounter) return 0;
    visLeft[l] = curLeftCounter;
    for(int i = 0; i < adj[l].size(); i++){
        int right = adj[l][i];
        if(visRight[right] != curRightCounter || Aug(match[right])){
            visRight[right] = curRightCounter;
            match[right] = l;
            return 1;
        }
    }
    return 0;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    curRightCounter = curLeftCounter = 1;
    while(scanf("%d", &n) > 0){
        for(int i = 0; i < n; i++){
            scanf("%s", G[i]);
        }

        int currentRow = 0;
        for(int i = 0; i < n; i++){
            if(G[i][0] == '.'){
                X[i][0].first = ++currentRow;
            }
            for(int j = 1; j < n; j++){
                if(G[i][j] == '.'){
                    if(G[i][j - 1] == 'X') currentRow++;
                    X[i][j].first = currentRow;
                }
            }
        }

        int currentCol = 0;
        for(int i = 0; i < n; i++){
            if(G[0][i] == '.'){
                X[0][i].second = ++currentCol;
            }
            for(int j = 1; j < n; j++){
                if(G[j][i] == '.'){
                    if(G[j - 1][i] == 'X') currentCol++;
                    X[j][i].second = currentCol;
                }
            }
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(G[i][j] == '.') adj[X[i][j].first].push_back(X[i][j].second);
            }
        }

        int total = 0;

        curRightCounter++;
        for(int i = 0; i <= currentRow; i++){
            curLeftCounter++;
            total += Aug(i);
        }

        for(int i = 0; i <= currentRow; i++){
            adj[i].clear();
        }

        cout << total << '\n';

        /*for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cout << X[i][j].second;
            }
            cout << endl;
        }*/

    }

    return 0;
}
