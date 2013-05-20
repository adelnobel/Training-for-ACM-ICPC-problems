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

using namespace std;


typedef struct puzzle{
    int configuration[4][4];
    short cost;
    short heuristic;
    short last;
    short parent;
    short zPlace;
    char path[50];
    
    puzzle(){};
    
    puzzle(short c, short h){
        cost = c;
        heuristic = h;
        last = 0;
    }
    
    bool operator<(const puzzle& p) const{
        return cost + heuristic > p.cost + p.heuristic;
    }
}puzzle;


int dirX[4] = {0, -1, 0, 1};
int dirY[4] = {-1, 0, 1, 0};

char dirs[] = "LURD";

pair<int, int> goal[17];

int countInversions(int arr[], int len){
    int tot = 0;
    for(int i = 0; i < len; i++){
        for(int j = i-1; j >= 0; j--){
            if(arr[j] > arr[i]) tot++;
        }
    }
    return tot;
}

bool isSolvable(puzzle puzz){
    int linearArray[15];
    int c = 0;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(puzz.configuration[i][j] == 0) continue;
            linearArray[c++] = puzz.configuration[i][j];
        }
    }
    int inversions = countInversions(linearArray, 15);
    int zeroRow = 4 - ((puzz.zPlace / 4));//Rows are 1 indexed!
    if(zeroRow % 2 == 0){ //if the zero is in an even row!
        return inversions % 2; //then inversions must be odd if solvable!
    }else{
        return inversions % 2 == 0;
    }
}

short manhattnDistance(int puzzle[][4]){
    short tot = 0;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            tot += abs(i - goal[puzzle[i][j]].first) + abs(j - goal[puzzle[i][j]].second);
        }
    }
    return tot;
}

priority_queue<puzzle> pq;

string aStar(const puzzle& start){
    while(!pq.empty())pq.pop();
    pq.push(start);
    
    while(!pq.empty()){
        puzzle cur = pq.top(); pq.pop();
        if(cur.cost < 50){
            if(cur.heuristic == 0){
                return string(cur.path);
            }
            for(int i = 0; i < 4; i++){
                int row = cur.zPlace / 4 , col = cur.zPlace % 4;
                if(row + dirX[i] < 0 || row + dirX[i] > 3 || col + dirY[i] < 0 || col + dirY[i] > 3) continue;
                if(abs(i - cur.parent) == 2) continue;
                puzzle newP;
                newP.parent = i;
                newP.cost = cur.cost + 1;
                newP.last = cur.last;
                memcpy(newP.path, cur.path, cur.last);
                newP.path[newP.last++] = dirs[i]; newP.path[newP.last] = '\0';
                memcpy(newP.configuration, cur.configuration, sizeof(cur.configuration));
                swap(newP.configuration[row][col], newP.configuration[row+dirX[i]][col+dirY[i]]);
                row += dirX[i]; col += dirY[i];
                newP.heuristic = manhattnDistance(newP.configuration);
                newP.zPlace = (row * 4) + col;
                pq.push(newP);
            }
        }
    }
    
    return "";
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    
    int c = 1;
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            goal[c].first = i;
            goal[c].second = j;
            c++;
        }
    }
    goal[0].first = goal[0].second = 3;

    int t;
    
    scanf("%d", &t);

    while(t--){
        puzzle start(0, 100);
        short zPlace = 0;
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                scanf("%d", &start.configuration[i][j]);
                if(start.configuration[i][j] == 0){
                    zPlace = (i * 4) + j;
                }
            }
        }
        start.zPlace = zPlace;
        start.parent = -10;
        if(isSolvable(start)){
            printf("%s\n", aStar(start).c_str());
        }else{
            printf("This puzzle is not solvable.\n");
        }
       
    }

    return 0;
}