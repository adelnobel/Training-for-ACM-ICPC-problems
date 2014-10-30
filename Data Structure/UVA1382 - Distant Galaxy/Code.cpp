#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
#include <set>
#include <cassert>
#include <ctime>

using namespace std;

typedef long long ll;

int vis[205][205];

int tree[105][105][105 * 4];
int ACC[105][105], ACCY[105][105];

int K;

int getVal(int l, const int &yL, const int &yU){
    return ACC[l][yU] - ACC[l][yL-1] + ACCY[yU][l] + ACCY[yL][l]
           - vis[K][yL] - vis[l][yL] - vis[K][yU] - vis[l][yU];
    
}


void build(int node, int l, int r, const int &yL, const int &yU){
    if(l == r){
        tree[yL][yU][node] = l;
        return;
    }
    
    int mid = (l+r) / 2;
    build(node*2, l, mid, yL, yU);
    build(node*2+1, mid+1, r, yL, yU);
    if(getVal(tree[yL][yU][node*2], yL, yU) > getVal(tree[yL][yU][node*2+1], yL, yU)){
        tree[yL][yU][node] = tree[yL][yU][node*2];
    }else{
        tree[yL][yU][node] = tree[yL][yU][node*2+1];
    }
    
}

int query(int node, int l, int r, int cL, int cR, const int &yL, const int &yU){
    if(cL >= l && cR <= r){
        return tree[yL][yU][node];
    }
    if(cL > r || cR < l){
        return -1;
    }
    
    int mid = (cL+cR) / 2;
    int left = query(node*2, l, r, cL, mid, yL, yU);
    int right = query(node*2+1, l, r, mid+1, cR, yL, yU);
    
    if(left == -1) return right;
    if(right == -1) return left;
    
    if(getVal(left, yL, yU) >= getVal(right, yL, yU)){
        return left;
    }
    
    return right;
    
}

int main() {
    
    freopen("in.in", "r", stdin);
    /**
    freopen("in.in", "w", stdout);
    srand(time(NULL));
    
    for(int j = 0; j < 10; j++){
        cout << 10 << endl;

        for(int i = 0; i < 10; i++){
            cout << (rand() * rand()) % 20;
            cout << " ";
            cout << (rand() * rand()) % 20 << endl;
        }
    }
    
    return 0;**/
    
    int t = 1;
    int n, a, b;
    

    while(1){
        
        scanf("%d", &n);
        if(!n) break;

        memset(vis, 0, sizeof vis);
        map<int, int> X, Y;
        vector< pair<int, int> > v;
        v.push_back(make_pair(-2e9, -2e9));
        v.push_back(make_pair(2e9, 2e9));
        for(int i = 0; i < n; i++){
            scanf("%d %d", &a, &b);
            v.push_back(make_pair(a, b));
        }
        
        for(int i = 0; i < v.size(); i++){
            X[v[i].first] = 0;
            Y[v[i].second] = 0;
        }
        

        int totX = 1;
        map<int, int>::iterator it;
        for(it = X.begin(); it != X.end(); it++){
            it->second = totX++;
        }
        
        int totY = 1;

        for(it = Y.begin(); it != Y.end(); it++){
            it->second = totY++;
        }
        
        for(int i = 0; i < v.size(); i++){
            v[i].first = X[v[i].first];
            v[i].second = Y[v[i].second];
            
            if(i > 1){
                vis[v[i].first][v[i].second]++;
            }
            //cout << v[i].first << " " << v[i].second << endl;
        }
        

        memset(ACC, 0, sizeof ACC);
        memset(ACCY, 0, sizeof ACCY);
        
        for(int x = 1; x < totX; x++){
            for(int y = 1; y < totY; y++){
                ACC[x][y] = ACC[x][y-1];
                ACC[x][y] += vis[x][y];
            }
        }
        
        for(int y = 1; y < totY; y++){
            for(int x = 1; x < totX; x++){
                ACCY[y][x] = ACCY[y][x-1];
                ACCY[y][x] += vis[x][y];
            }
        }
        
        totX--;
        totY--;
        
        for(int i = 1; i < totY; i++){
            for(int j = i+1; j <= totY; j++){
                build(1, 1, totX, i, j);
            }
        }
        
        
        int ans = 0;
        
        for(int i = 1; i < totY; i++){
            for(int j = i+1; j <= totY; j++){
                for(int k = 1; k < totX; k++){
                    K = k;
                    int w = query(1, k+1, totX, 1, totX,  i, j);
                    assert(w >= k+1 && w <= totX);
                    int v = ACC[k][j] - ACC[k][i-1];
                    v += ACC[w][j] - ACC[w][i-1];
                    v += ACCY[i][w] - ACCY[i][k-1];
                    v += ACCY[j][w] - ACCY[j][k-1];
                    v -= vis[k][i] + vis[w][i] + vis[k][j] + vis[w][j];
                    ans = max(v, ans);
                    /**
                    int q = w;
                    int h = v;
                    
                    int maxi = 0;
                    int bestW;
                    for(int w = k+1; w <= totX; w++){
                        v = ACC[k][j] - ACC[k][i-1];
                        v += ACC[w][j] - ACC[w][i-1];
                        v += ACCY[i][w] - ACCY[i][k-1];
                        v += ACCY[j][w] - ACCY[j][k-1];
                        v -= vis[k][i] + vis[w][i] + vis[k][j] + vis[w][j];
                        if(v > maxi){
                            maxi = v;
                            bestW = w;
                        }
                    }
                    
                    if(maxi != h){
                        cerr << maxi << endl;
                        cerr << h << endl;
                        cerr << q << endl;
                        cerr << bestW << endl;
                        cerr << getVal(q, i, j) << endl;
                        cerr << getVal(bestW, i, j) << endl;
                        //maxi++;
                    }
                    assert(maxi == h);**/
                    
                    
                }
            }
        }
        
        printf("Case %d: %d\n",t++, ans);

    }
    

    return 0;
}