/* In the name of ALLAH, most gracious, most merciful */
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
#include <string.h>
 
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

#define N 505

unsigned int tree[N][N];

unsigned int query(int r, int c){
    unsigned int ret = 0;
    while(r > 0){
        int cCur = c;
        while(cCur > 0){
            ret += tree[r][cCur];
            cCur -= cCur & -cCur;
        }
        r -= r & -r;
    }
    return ret;
}

void update(int r, int c, unsigned int val){
    while(r < N){
        int cCur = c;
        while(cCur < N){
            tree[r][cCur] += val;
            cCur += cCur & -cCur;
        }
        r += r & -r;
    }
}

unsigned int querySubMatrix(int r1, int r2, int c1, int c2){
    unsigned int ret = query(r2, c2);
    ret -= query(r1 - 1, c2);
    ret -= query(r2, c1 - 1);
    ret += query(r1 - 1, c1 - 1);
    return ret;
}

int arr[N];
vector< pi > v;

bool cmp(const pi& a, const pi& b){
    return arr[a.first] + arr[a.second] < arr[b.first] + arr[b.second];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t, n;
    cin >> t;
    for(int T = 1; T <= t; T++){
        memset(tree, 0, sizeof tree);
        v.clear();
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                v.push_back(pi(i, j));
            }
        }
        sort(v.begin(), v.end(), cmp);
        unsigned int res = 0;
        int i = 0, j;
        while(i < v.size()){
            j = i;
            vector< unsigned int > updates; //Hold updates for equal pairs to avoid including equal pairs in our calculations
            while(j < v.size() && !cmp(v[i], v[j])){ //While equal
                unsigned int curResult = 1;
                if(v[j].first + 1 < v[j].second){
                    curResult += querySubMatrix(v[j].first + 2, v[j].second, v[j].first + 2, v[j].second); //Turning to 1-indexed mode!!
                }
                updates.push_back(curResult);
                ++j;
            }
            int k = 0;
            while(i < j){
                update(v[i].first + 1, v[i].second + 1, updates[k]);
                res += updates[k];
                ++k;
                ++i;
            }
        }
        
        cout << "Case " << T <<  ": " << res << "\n";
    }
    
    
    return 0;
}

