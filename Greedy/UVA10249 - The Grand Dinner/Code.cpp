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

pair<int, int> teams[72];
pair<int, int> tables[52];

int assignments[80][60];

int main()
{
    //freopen("in.in", "r", stdin);
    
    int M, N;
    
    while(1){
        scanf("%d %d", &M, &N);
        if(M == 0 && N == 0) break;
        
        int totPlayers = 0, totSeats = 0;
        
        for(int i = 0; i < M; i++){
            scanf("%d", &teams[i].first);
            teams[i].second = i;
            totPlayers += teams[i].first;
        }
        
        for(int i = 0; i < N; i++){
            scanf("%d", &tables[i].first);
            tables[i].second = i+1;
            totSeats += tables[i].first;
        }
        

        if(totPlayers > totSeats){
            printf("0\n");
            continue;
        }
        
        sort(teams, teams+M, greater< pair<int,int> >());
        
        bool valid = true;
        
        for(int i = 0; i < M && valid; i++){
            sort(tables, tables+N, greater< pair<int,int> >());
            int c = 0, curPlayer = 0;
            while(teams[i].first > 0 && c < N){
                if(tables[c].first > 0){
                    tables[c].first--;
                    teams[i].first--;
                    assignments[teams[i].second][curPlayer++] = tables[c].second;
                }
                c++;
            }
            assignments[teams[i].second][curPlayer] = -1;
            if(teams[i].first != 0) valid = false;
        }
        
        if(!valid){
            printf("0\n");
        }
        else{
            printf("1\n");
            for(int i = 0; i < M; i++){
                printf("%d", assignments[i][0]);
                for(int j = 1; assignments[i][j] != -1; j++){
                    printf(" %d", assignments[i][j]);
                }
                printf("\n");
            }
        }
        
    }
    
    return 0;
}
