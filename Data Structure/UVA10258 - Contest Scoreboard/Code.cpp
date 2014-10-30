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

typedef struct team
{
    int number;
    int problemsPenalty[10];
    int solved;
    int penalty;
    
    bool operator<(const team &t) const
    {
        if(number == -1 || t.number == -1){
            if(number == -1) return false;
            return true;
        }
        if(solved != t.solved) return solved > t.solved;
        if(penalty != t.penalty) return penalty < t.penalty;
        return number < t.number;
    }
    
}team;

char line[200];

team teams[110];

/**
Multi field sorting!
**/

int main()
{
    //freopen("in.in", "r", stdin);
    int t, c = 0, number, problem, time;
    char status;
    
    scanf("%d", &t);
    gets(line);
    gets(line);
    
    while(t--)
    {
        
        for(int i = 0; i <= 105; i++){
            teams[i].number = -1;
            teams[i].penalty = 0;
            teams[i].solved = 0;
            for(int j = 0; j < 10; j++)
                teams[i].problemsPenalty[j] = 0;
        }
        if(c){
           printf("\n");
        }
        c = 1;
        
        line[0] = '\0';
        
        while(1){
            gets(line);
            if(line[0] == '\0') break;
            
            sscanf(line, "%d %d %d %c", &number, &problem, &time, &status);
            
            if(teams[number].number == -1){
                teams[number].number = number;
            }
            
            if(teams[number].problemsPenalty[problem] != -1){
                if(status == 'C'){
                    teams[number].penalty += time + teams[number].problemsPenalty[problem];
                    teams[number].solved++;
                    teams[number].problemsPenalty[problem] = -1;
                }
                else if(status == 'I'){
                    teams[number].problemsPenalty[problem] += 20;
                }
            }
            
            line[0] = '\0';
        }
        
        sort(teams, teams+105);
        
        for(int i = 0; i <= 105; i++){
            if(teams[i].number != -1){
                printf("%d %d %d\n", teams[i].number, teams[i].solved, teams[i].penalty);
            }
        }
        
        
    }
    

    return 0;
}