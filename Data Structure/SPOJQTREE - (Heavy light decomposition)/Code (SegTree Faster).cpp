#include <vector>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <bitset>
#include <map>
#include <complex>
#include <ctime>
#include <numeric>
#include <set>
#include <cassert>

using namespace std;

#define N 10005
typedef pair<int, int> pi;
vector< pi > adj[N];
int lca[N][15];
pi par[N], edges[N];
int skip[N], sz[N];
int depth[N];
char s[40];

class SegmentTree{
public:
    SegmentTree();
    
    SegmentTree(vector< int > &v){
        n = v.size();
        tree = new int[4*n];
        memset(tree, 0, sizeof tree);
        build(1, 0, n-1, v);
    }
    
    ~SegmentTree(){
        delete[] tree;
    }
    
    int query(int l, int r){
        left = l, right = r;
        return query(1, 0, n-1);
    }
    
    void update(int l, int v){
        left = l, right = l; val = v;
        update(1, 0, n-1);
    }
private:
    int *tree;
    int n, left, right, val;
    
    int query(int cur, int cL, int cR){
        if(cL >= left && cR <= right){
            return tree[cur];
        }
        if(cL > right || cR < left) return -1e9;
        int mid = (cL+cR) >> 1;
        int l = query(cur<<1, cL, mid);
        int r = query((cur<<1) + 1, mid+1, cR);
        return max(l, r);
    }
    
    void update(int cur, int cL, int cR){
        if(cL == left && cR == right){
            tree[cur] = val;
            return;
        }
        if(left < cL || left > cR) return;
        int mid = (cL+cR) >> 1;
        update(cur<<1, cL, mid);
        update((cur<<1) + 1, mid+1, cR);
        tree[cur] = max(tree[cur<<1], tree[(cur<<1) + 1]);
    }
    
    void build(int cur, int cL, int cR, vector< int > & node){
        if(cL == cR){
            tree[cur] = node[cL];
            return;
        }
        int mid = (cL+cR) / 2;
        build(cur*2, cL, mid, node);
        build(cur*2+1, mid+1, cR, node);
        tree[cur] = max(tree[cur*2], tree[cur*2+1]);
    }
    
};

class HeavyPath{
public:
    int rootOfPath;
    HeavyPath();
    
    HeavyPath(int root){
        rootOfPath = root;
    }
    
    void initTree(){
        T = new SegmentTree(nodes);
    }
    
    void add(int edgeCost){
        nodes.push_back(edgeCost);
    }
    
    void update(int a, int b, int val){
        
        int l = depth[a] - depth[rootOfPath];
        int r = depth[b] - depth[rootOfPath];
        assert(l+1 == r && l >= 0 && l < nodes.size());
        T->update(l, val);
    }
    
    int query(int a, int b){
        int l = depth[a] - depth[rootOfPath];
        int r = depth[b] - depth[rootOfPath] - 1;
        assert(l >= 0 && l < nodes.size() && r >= l);
        return T->query(l, r);
    }
    

private:
    vector< int > nodes;
    SegmentTree* T;
};

vector< HeavyPath > paths;

void dfs(int cur, int d, int P){
    lca[cur][0] = P;
    for(int i = 1; i <= 14; i++){
        lca[cur][i] = lca[lca[cur][i-1]][i-1];
    }
    depth[cur] = d;
    sz[cur] = 1;
    for(int i = 0; i < adj[cur].size(); i++){
        int to = adj[cur][i].first;
        if(to == P) continue;
        par[to].first = cur;
        par[to].second = adj[cur][i].second;
        dfs(to, d+1, cur);
        sz[cur] += sz[to];
    }
}

void initSkip(int cur, int P, int prevHeavy){
    skip[cur] = -1;
    if(cur != 1){
        if(sz[cur] > (sz[P] / 2)){
            if(prevHeavy == -1){
                prevHeavy = paths.size();
                paths.push_back(HeavyPath(P));
            }
            paths[prevHeavy].add(par[cur].second);
            skip[cur] = prevHeavy;
        }else{
            prevHeavy = -1;
        }
    }
    for(int i = 0; i < adj[cur].size(); i++){
        int to = adj[cur][i].first;
        if(to == P) continue;
        initSkip(to, cur, prevHeavy);
    }
}

int raise(int n, int l){
    for(int i = 0; i <= 14; i++){
        if(l & (1<<i)){
            n = lca[n][i];
        }
    }
    return n;
}

int LCA(int a, int b){
    if(depth[a] > depth[b]){
        a = raise(a, depth[a] - depth[b]);
    }else{
        b = raise(b, depth[b] - depth[a]);
    }
    assert(depth[a] == depth[b]);
    if(a == b) return a;
    for(int i = 14; i >= 0; i--){
        if(lca[a][i] != lca[b][i]){
            a = lca[a][i];
            b = lca[b][i];
        }
    }
    return par[a].first;
}

int getPath(int a, int b){
    int ret = 0;
    if(a == b) return ret;
    assert(depth[a] > depth[b]);
    int tot = 0;
    while(a != b){
        assert(tot < 30);
        int jump = skip[a];
        if(jump != -1){
            int to;
            if(depth[b] <= depth[paths[jump].rootOfPath]){
                to = paths[jump].rootOfPath;
            }else{
                to = b;
            }
            ret = max(ret, paths[jump].query(to, a));
            a = to;
        }else{
            ret = max(ret, par[a].second);
            a = par[a].first;
        }
        tot++;
    }
    return ret;
}

int getMax(int a, int b){
    int root = LCA(a, b);
    return max(getPath(a, root), getPath(b, root));
}

int update(int a, int b, int val){
    par[b].second = val;
    int path = skip[b];
    if(path != -1){
        paths[path].update(a, b, val);
    }
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    /*
    freopen("in.in", "w", stdout);
    cout << 1 << endl << 10000 << endl;
    
    for(int i = 1; i < 10000; i++){
        printf("%d %d %d\n", i, i+1, rand() % 1000000);
    }
    for(int i = 0; i < 100000; i++){
        int t = rand() % 2;
        if(t){
            printf("QUERY %d %d\n", rand() % 10000 + 1, rand() % 10000 + 1);
        }else{
            printf("CHANGE %d %d\n", rand() % (10000-1) + 1, rand() % 1000000);
        }
    }
    printf("DONE\n");
    return 0;*/
    int T, a, b, c, n;
    scanf("%d", &T);
    while(T--){
        paths.clear();
        scanf("%d", &n);
        for(int i = 0; i < n-1; i++){
            scanf("%d %d %d", &a, &b, &c);
            adj[a].push_back(pi(b, c));
            adj[b].push_back(pi(a, c));

            edges[i].first = a;
            edges[i].second = b;
        }
        
        
        dfs(1, 0, 0);
        sz[0] = 1e9;
        initSkip(1, 0, -1);
        for(int i = 0; i < paths.size(); i++){
            paths[i].initTree();
        }
        

        while(1){
            scanf("%s", s);
            if(s[0] == 'D') break;
            scanf("%d %d", &a, &b);
            if(s[0] == 'Q'){
                printf("%d\n", getMax(a, b));
            }else{
                if(depth[edges[a-1].first] > depth[edges[a-1].second]){
                    swap(edges[a-1].first, edges[a-1].second);
                }
                update(edges[a-1].first, edges[a-1].second, b);
            }
        }
        
        
        
        for(int i = 0; i <= n; i++){
            adj[i].clear();
        }
    }
    
    
    return 0;
}
