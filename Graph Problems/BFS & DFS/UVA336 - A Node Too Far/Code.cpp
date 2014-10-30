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

typedef long long ll;

typedef struct node{
    int n, TTL;
    node(int a, int t){n = a; TTL = t;};
}node;

map<int, vector<int> > adj;

set<int> vis;


int main()
{
    //freopen("in.in", "r", stdin);
    
    int e, a, b, prevE = 0, cc = 1;
    
    while(1){
        scanf("%d", &e);
        if(e == 0) break;
        
        adj.clear();

        for(int i = 0; i < e; i++){
            scanf("%d %d", &a, &b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        
        while(1){
            vis.clear();
            scanf("%d %d", &a, &b);
            if(a == 0 && b == 0) break;
            queue<node> q;
            q.push(node(a, b));
            vis.insert(a);
            

            
            while(!q.empty()){
                node cur = q.front(); q.pop();
                if(cur.TTL == 0) continue;
                vector<int>* p = &adj[cur.n];
                for(int i = 0; i < p->size(); i++){
                    if(vis.count(p->at(i)) == 0){
                        vis.insert(p->at(i));
                        q.push(node(p->at(i), cur.TTL-1));
                    }
                }
            }
            
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", cc++, adj.size() - vis.size(), a, b);
            
        }
    }
    
    return 0;
}