#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <functional>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>

using namespace std;

typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef double ld;

int cur = 1;
int vis[21][21][40][40];
const int N = 20;
vector< string > v1, v2;

bool solve(int idx1, int idx2, int offset1, int offset2){
    if(vis[idx1][idx2][offset1][offset2] == cur) return false;
    vis[idx1][idx2][offset1][offset2] = cur;
    if(idx1 == N){
        for(int i = 0; i < v1.size(); i++){
            int m = 0;
            while(m < v1[i].size() && offset2 + m < v2[idx2].size()
                  && v1[i][m] == v2[idx2][offset2 + m]) m++;
            if(m == v1[i].size()){
                if(offset2 + m == v2[idx2].size()) return true;
                int nOffset2 = offset2 + m;
                if(solve(N, idx2, 0, nOffset2)){
                    return true;
                }
            }else{
                if(offset2 + m == v2[idx2].size()){
                    if(solve(i, N, m, 0)) return true;
                }
            }
        }
    }else{
        for(int i = 0; i < v2.size(); i++){
            int m = 0;
            while(m < v2[i].size() && offset1 + m < v1[idx1].size()
                  && v2[i][m] == v1[idx1][offset1 + m]) m++;
            if(m == v2[i].size()){
                if(offset1 + m == v1[idx1].size()) return true;
                int nOffset1 = offset1 + m;
                if(solve(idx1, N, nOffset1, 0)){
                    return true;
                }
            }else{
                if(offset1 + m == v1[idx1].size()){
                    if(solve(N, i, 0, m)) return true;
                }
            }
        }
    }
    return false;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    //freopen("out1.in", "w", stdout);
#endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    int n, m;
    while(cin >> n >> m){
        v1.clear(); v2.clear();
        for(int i = 0; i < n; i++){
            cin >> s;
            v1.push_back(s);
        }
        for(int i = 0; i < m; i++){
            cin >> s;
            v2.push_back(s);
        }
        cur++;
        bool okay = false;
        for(int i = 0; i < n && !okay; i++){
            okay |= solve(i, N, 0, 0);
        }
        for(int i = 0; i < m && !okay; i++){
            okay |= solve(N, i, 0, 0);
        }

        if(okay) cout << "S";
        else cout << "N";
        cout  << '\n';
    }



    return 0;
}
