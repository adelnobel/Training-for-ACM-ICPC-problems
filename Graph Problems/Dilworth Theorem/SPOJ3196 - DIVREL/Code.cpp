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

typedef long long ll;
typedef pair<int, int> pi;

/**
Another way to find the maximum independent set, is to first, run the max matching
and get the cardinality of the min vertex cover, now for each node, try to remove it
and run max matching, if we get the same cardinality of a min vertex cover, then 
this can be included as it's in the max independent set and so on
http://www.spoj.com/forum/viewtopic.php?p=25148&sid=90d10ebe211ba335cfae95529cc5de94#p25148
**/

vector< int > adj[2*205];
bool vis[2*205];
int match[2*205];

int Aug(int l){
    if(vis[l]) return 0;
    vis[l] = 1;
    for(int i = 0; i < adj[l].size(); i++){
        int r = adj[l][i];
        if(match[r] == -1 || Aug(match[r])){
            match[r] = l;
            match[l] = r;
            return 1;
        }
    }
    
    return 0;
}

bool isInMinCover[2*205];

void mark(int v){
    if(vis[v]) return;
    vis[v] = true;
    isInMinCover[v] = false;
    for(int i = 0; i < adj[v].size(); i++){
        int to = adj[v][i];
        assert(match[to] != -1); //Assert we go from UNMATCHED vertex to a MATCHED vertex
        isInMinCover[to] = true;
        mark(match[to]);
    }
}


int main(){
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    
    int n, x;
    vector< int > v;
    scanf("%d", &n);
    
    for(int i = 0; i < n; i++){
        scanf("%d", &x);
        v.push_back(x);
    }
    
    sort(v.begin(), v.end());
    
    for(int i = 0; i < v.size(); i++){
        for(int j = i+1; j < v.size(); j++){
            if(v[j] % v[i] == 0){
                adj[i].push_back(j+n);
                adj[j+n].push_back(i);
            }
        }
    }
    

    memset(match, -1, sizeof match);
    
    int tot = 0;
    
    for(int i = 0; i < v.size(); i++){
        memset(vis, false, sizeof vis);
        tot += Aug(i);
        //return 0;
    }
    
    vector< int > ans;
    memset(vis, false, sizeof vis);
    for(int i = 0; i < 2*n; i++){
        if(match[i] == -1){
            mark(i);
        }
    }
    
    for(int i = 0; i < n; i++){
        if(match[i] != -1){
            if(!isInMinCover[i] && !isInMinCover[match[i]]){
                isInMinCover[i] = true;
            }
        }
    }
    
    
    for(int i = 0; i < n; i++){
        if(!isInMinCover[i] && !isInMinCover[i+n]){
            ans.push_back(i);
        }
    }
    
    assert(ans.size() == n - tot);
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans.size(); j++){
            if(i == j) continue;
            assert(v[ans[i]] % v[ans[j]] != 0);
        }
    }
    
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++){
        if(i != 0) printf(" ");
        printf("%d", v[ans[i]]);
    }
    printf("\n");

    return 0;
}