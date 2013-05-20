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

int conns[40][40];

char s[200];

int parent[40];

bitset<40> vis;

void process()
{
    conns[0][s[0] - 'A' + 1] = s[1] - '0';
    int c = 3;
    while(s[c] != ';'){
        conns[s[0] - 'A' + 1][s[c] - '0' + 27] = 1;
        conns[s[c] - '0' + 27][37] = 1;
        c++;
    }
}

int maxFlow()
{
    vis.reset();
    queue<int> q;
    q.push(0);
    vis[0] = 1;
    parent[0] = -1;
    bool flowExist = false;
    
    while(!q.empty())
    {
        int cur = q.front(); q.pop();
        if(cur == 37) {
            flowExist = true;
            break;
        }
        for(int i = 1; i < 40; i++){
            if(conns[cur][i] > 0 && !vis[i]){
                parent[i] = cur;
                q.push(i);
                vis[i] = 1;
            }
        }
    }
    
    int ptr = 37;
    
    while(flowExist && parent[ptr] != -1){
        conns[parent[ptr]][ptr] -= 1;
        conns[ptr][parent[ptr]] += 1;
        ptr = parent[ptr];
    }
    
    return flowExist;
}

int main()
{
    //freopen("in.in", "r", stdin);
    
    bool flag = true;
    
    while(flag)
    {
        memset(conns, 0, sizeof(conns));
        int tot = 0;
        
        s[0] = '\0';
        gets(s);
        if(s[0] == '\0') break;
        
        process();
        tot += s[1] - '0';
        
        while(1)
        {
            s[0] = '\0';
            gets(s);
            if(s[0] == '\0') break;
            tot += s[1] - '0';
            process();
        }
        
        int maxiFlow = 0;
        
        while(1){
            if(maxFlow() == 1)
                maxiFlow++;
            else break;
        }
        
        if(tot > maxiFlow ){
            printf("!\n");
            continue;
        }
        
        for(int i = 27; i < 37; i++){
            bool assigned = false;
            for(int j = 1; j < 27; j++){
                if(conns[i][j] > 0){
                    printf("%c", j-1 + 'A');
                    assigned = true;
                    break;
                }
            }
            if(!assigned) printf("_");
        }
        printf("\n");
        
    }
    
    
    return 0;
}
