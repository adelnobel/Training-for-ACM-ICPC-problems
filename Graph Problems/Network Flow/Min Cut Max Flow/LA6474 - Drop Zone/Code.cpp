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
typedef long double ld;
typedef pair<int, int> pi;

const int N = 155 * 155 + 5;
const int SOURCE = 0, SINK = N - 1;

char g[153][153];

int dr[] = {1, 0, 0, -1};
int dc[] = {0, -1, 1, 0};

int getIdx(int r, int c){
    return r * 153 + c;
}

const int INF = 2000000000;

struct Edge {
  int from, to, cap, flow, index;
  Edge(int from, int to, int cap, int flow, int index) :
    from(from), to(to), cap(cap), flow(flow), index(index) {}
};

struct Dinic {
  int N;
  vector<vector<Edge> > G;
  vector<Edge *> dad;
  vector<int> Q;

  Dinic(int N) : N(N), G(N), dad(N), Q(N) {}

  void AddEdge(int from, int to, int cap) {
    G[from].push_back(Edge(from, to, cap, 0, G[to].size()));
    if (from == to) G[from].back().index++;
    G[to].push_back(Edge(to, from, 0, 0, G[from].size() - 1));
  }

  long long BlockingFlow(int s, int t) {
    fill(dad.begin(), dad.end(), (Edge *) NULL);
    dad[s] = &G[0][0] - 1;

    int head = 0, tail = 0;
    Q[tail++] = s;
    while (head < tail) {
      int x = Q[head++];
      for (int i = 0; i < G[x].size(); i++) {
    Edge &e = G[x][i];
    if (!dad[e.to] && e.cap - e.flow > 0) {
      dad[e.to] = &G[x][i];
      Q[tail++] = e.to;
    }
      }
    }
    if (!dad[t]) return 0;

    long long totflow = 0;
    for (int i = 0; i < G[t].size(); i++) {
      Edge *start = &G[G[t][i].to][G[t][i].index];
      int amt = INF;
      for (Edge *e = start; amt && e != dad[s]; e = dad[e->from]) {
    if (!e) { amt = 0; break; }
    amt = min(amt, e->cap - e->flow);
      }
      if (amt == 0) continue;
      for (Edge *e = start; amt && e != dad[s]; e = dad[e->from]) {
    e->flow += amt;
    G[e->to][e->index].flow -= amt;
      }
      totflow += amt;
    }
    return totflow;
  }

  long long GetMaxFlow(int s, int t) {
    long long totflow = 0;
    while (long long flow = BlockingFlow(s, t))
      totflow += flow;
    return totflow;
  }
};

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif

    int t, r, c;
    cin >> t;
    while (t--) {
        memset(g, '.', sizeof g);
        scanf("%d %d", &r, &c);
        for(int i = 2; i <= r + 1; i++){
            scanf("%s", g[i] + 2);
        }
        Dinic D(N);
        for(int i = 1; i <= r + 2; i++){
            for(int j = 1; j <= c + 2; j++){
                if(g[i][j] == 'X') continue;
                if(g[i][j] == 'D') D.AddEdge(getIdx(i, j), SINK, INF);
                for(int a = 0; a < 4; a++){
                    int nr = i + dr[a], nc = j + dc[a];
                    if(g[nr][nc] == 'X') continue;
                    D.AddEdge(getIdx(i, j), getIdx(nr, nc), 1);
                }
            }
        }

        for(int i = 1; i <= r + 2; i++){
            if(g[i][1] != 'X'){
                D.AddEdge(SOURCE, getIdx(i, 1), INF);
            }
            if(g[i][c + 2] != 'X'){
                D.AddEdge(SOURCE, getIdx(i, c + 2), INF);
            }
        }

        for(int i = 2; i <= c + 1; i++){
            if(g[1][i] != 'X'){
                D.AddEdge(SOURCE, getIdx(1, i), INF);
            }
            if(g[r + 2][i] != 'X'){
                D.AddEdge(SOURCE, getIdx(r + 2, i), INF);
            }
        }


        cout << D.GetMaxFlow(SOURCE, SINK) << '\n';

    }

    return 0;
}
