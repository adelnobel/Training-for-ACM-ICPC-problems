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

typedef struct edge{
    int dist, cost, elevator;
    edge(int d, int c, int e){
        dist = d;
        cost = c;
        elevator = e;
    };
}edge;

typedef struct node{
    int vertex, cost, elevator;
    node(int v, int c, int e){
        vertex = v;
        cost = c;
        elevator = e;
    }
    
    bool operator<(const node &n) const{
        return cost > n.cost;
    }
    
}node;

#define INF 1 << 30

int elevatorsCosts[6];

char line[500];

vector< edge > adj[101];

int vis[101];

bool beenThere[5][101];
    
int n, k;

int dijkstra()
{
    vis[0] = 0;
    priority_queue<node> pq;
    pq.push(node(0, 0, -1));
    
    while(!pq.empty()){
        node cur = pq.top(); pq.pop();
        
        if(cur.vertex == k) {
            return cur.cost;
        } //Push only if we reach with a less cost, or if we never reached this floor in this elevator before!
        for(int i = 0; i < adj[cur.vertex].size(); i++){
            int cost = cur.cost + adj[cur.vertex][i].cost + ((cur.elevator == -1 || cur.elevator == adj[cur.vertex][i].elevator) ? 0 : 60 );
            if( vis[adj[cur.vertex][i].dist] > cost || !beenThere[adj[cur.vertex][i].elevator][adj[cur.vertex][i].dist] ){
                pq.push(node(adj[cur.vertex][i].dist, cost, adj[cur.vertex][i].elevator));
                vis[adj[cur.vertex][i].dist] = vis[adj[cur.vertex][i].dist] == INF ? cost : max(cost, vis[adj[cur.vertex][i].dist]);
                //If the previous cost == INF, then we update the cost with the new cost;
                //If its not infinity, then this means we reached this floor before but FROM a different elevator
                //Then we need to set the cost to the max(oldcost, newcost) because for example, we might reach from elevator 1
                //with a cost of 200, and then reach from elevator 2 with cost of 220, then we reach again from elevator 2
                // with cost of 210, if we didn't set the value to the max before, then cost 210 though is less,
                // will not be pushed to the pq!!
                beenThere[adj[cur.vertex][i].elevator][adj[cur.vertex][i].dist] = true;
            }
        }
    }
    
    return INF;
}

int main()
{
    //freopen("in.in", "r", stdin);
    
    while(scanf("%d %d", &n, &k) != EOF)
    {
        memset(beenThere, false, sizeof(beenThere));
        for(int i = 0; i < 101; i++){
            adj[i].clear();
            vis[i] = INF;
        }
        
        for(int i = 0; i < n; i++){
            scanf("%d\n", &elevatorsCosts[i]);
        }
        
        int prevFloor, curFloor;
        
        for(int i = 0; i < n; i++){
            gets(line);
            int ptr = 0, c = 0, read = 0;
            sscanf(line+ptr, "%d%n", &prevFloor, &read);
            ptr += read;
            c++;
            while(sscanf(line+ptr, "%d%n", &curFloor, &read) != EOF){
                int cost = abs(curFloor - prevFloor) * elevatorsCosts[i] ;
                adj[curFloor].push_back( edge(prevFloor, cost, i ) );
                adj[prevFloor].push_back( edge(curFloor, cost, i ) );
                prevFloor = curFloor;
                ptr += read;
                c++;
            }
        }
        
        int cost = dijkstra();
        if(cost == INF) printf("IMPOSSIBLE\n");
        else printf("%d\n", cost);
        
    }
    
    return 0;
}
