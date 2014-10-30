/*
ID: adelnob1
PROG: beads
LANG: C++
*/
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <map>
#include <vector>
#include <queue>

using namespace std;

bool vis[10000];

char s[11], temp[10];

int toInt(){
    int cur = 0, read, x, ret = 0;
    while(sscanf(s+cur, "%d%n", &x, &read) == 1){
        cur += read;
        ret = (ret * 10) + x;
    }
    return ret;
}


pair<int, int> getNeighbors(int n, int digit){
    temp[0] = temp[1] = temp[2] = temp[3] = '0';
    digit = 3 - digit;
    int left, right;
    int plus = 0;
    if(n < 10) plus = 3;
    else if(n < 100) plus = 2;
    else if(n < 1000) plus = 1;
    char orig;
    sprintf(temp+plus, "%d", n);
    orig = temp[digit];
    if(temp[digit] == '9') temp[digit] = '0';
    else temp[digit] += 1;
    sscanf(temp, "%d", &left);
    
    temp[digit] = orig;
    if(temp[digit] == '0') temp[digit] = '9';
    else temp[digit] -= 1;
    sscanf(temp, "%d", &right);
    
    return make_pair(left, right);
}

int bfs(int start, int goal){
    if(vis[start]) return -1;
    
    queue< pair<int, int> > q;
    q.push(make_pair(start, 0));
    vis[start] = true;
    
    while(!q.empty()){
        pair<int, int> cur = q.front(); q.pop();
        if(cur.first == goal) return cur.second;
        for(int i = 0; i < 4; i++){
            pair<int, int> neighbors = getNeighbors(cur.first, i);
            if(!vis[neighbors.first]) q.push(make_pair(neighbors.first, cur.second+1));
            if(!vis[neighbors.second]) q.push(make_pair(neighbors.second, cur.second+1));
            vis[neighbors.first] = vis[neighbors.second] = true;
        }
    }
    
    return -1;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    int t, n, initial, target, invalid;
    scanf("%d", &t);
    
    while(t--){
        memset(vis, false, sizeof vis);
        scanf(" ");
        gets(s);
        initial = toInt();
        gets(s);
        target = toInt();
        
        scanf("%d ", &n);
        for(int i = 0; i < n; i++){
            gets(s);
            vis[toInt()] = true;
        }
        
        printf("%d\n", bfs(initial, target));
        
    }
    
    
    return 0;
}

