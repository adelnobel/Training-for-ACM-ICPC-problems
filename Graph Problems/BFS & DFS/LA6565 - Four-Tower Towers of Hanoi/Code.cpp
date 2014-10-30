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

using namespace std;

typedef pair<int, int> pi;
typedef long long ll;

/*
#define MAXN 22

typedef struct node{
    int counter[4];
    int arr[4][MAXN];
    bool operator<(const node& n) const{
        for(int i = 0; i < 4; i++){
            if(counter[i] != n.counter[i]) return counter[i] < n.counter[i];
        }
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < counter[i]; j++){
                if(arr[i][j] != n.arr[i][j]) return arr[i][j] < n.arr[i][j];
            }
        }
        return false;
    }
};

int n, best;
map< node, int > vis;

int solve(node start){
    queue < node > q;
    q.push(start);
    vis[start] = 0;

    while(!q.empty()){
        node cur = q.front(); q.pop();
        int cost = vis[cur];
        if(cur.counter[3] == n){
            return cost;
        }
        for(int i = 0; i < 4; i++){
            if(cur.counter[i] > 0){
                for(int j = 0; j < 4; j++){
                    if(cur.counter[j] == 0 || cur.arr[j][cur.counter[j] - 1] > cur.arr[i][cur.counter[i] - 1]){
                        node next = cur;
                        next.counter[i]--;
                        next.arr[j][next.counter[j]] = next.arr[i][next.counter[i]];
                        next.counter[j]++;
                        if(vis.count(next) == 0){
                            vis[next] = cost + 1;
                            q.push(next);
                        }
                    }
                }
            }
        }
    }
    return -1;
}*/

ll ans[1005];

int main(){
#ifndef ONLINE_JUDGE
     freopen("in.in", "r", stdin);
#endif
     ios::sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);

    /* while(cin >> n){
         vis.clear();
         node start;
         best = 1e9;
         for(int i = 0; i < 4; i++){
             start.counter[i] = 0;
         }
         for(int i = 0; i < n; i++){
             start.arr[0][i] = n - i;
         }
         start.counter[0] = n;
         cout << solve(start) << endl;
     }*/

     int cur = 4, curPower = 2;
     ans[1] = 1, ans[2] = 3, ans[3] = 5;
     for(int i = 3; cur < 1002 ; i++){
         for(int j = 0; j < i && cur < 1002; j++){
             ans[cur] = ans[cur - 1] + (1LL << curPower);
             cur++;
         }
         curPower++;
     }
     int n, tcase = 1;
     while(cin >> n){
         cout << "Case " << tcase++ <<  ": ";
         cout << ans[n] << '\n';
     }

     return 0;
}
