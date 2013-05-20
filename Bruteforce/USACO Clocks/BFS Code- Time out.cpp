/*
ID: adelnob1
PROG: clocks
LANG: C++
*/
#include <algorithm>
#include <functional>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <queue>
#include <stack>
#include <list>
#include <cstring>

using namespace std;

int states[4][4][4][4][4][4][4][4][4];

int a[9];

string mapp[9];

typedef struct
{
    string vals;
    string moves;
    int cost;
}state;

string getState(int move, string newState)
{
    //string newState = statee;
    for(int x = 0; x < mapp[move].size();x++)
    {
        newState[mapp[move][x] - 'A'] = (newState[mapp[move][x] - 'A'] == '4' ) ? '1' : newState[mapp[move][x] - 'A']+1;
    }
    return newState;
}

string n;

int main() 
{
    FILE* f = fopen("clocks.in", "r");
    FILE* fo = fopen("clocks.out", "w");
    
    mapp[0] = "ABDE"; mapp[1] = "ABC"; mapp[2] = "BCEF";
    mapp[3] = "ADG"; mapp[4] = "BDEFH"; mapp[5] = "CFI";
    mapp[6] = "DEGH"; mapp[7] = "GHI"; mapp[8] = "EFHI";
    
    memset(states, -1, sizeof(states));
    string s = "";
    
    for(int x = 0; x < 9; x++)
    {
        fscanf(f, "%d", &a[x]);
        s += (a[x] / 3) + '0';
    }
    
    states[a[0] / 3 - 1][a[1] / 3 - 1][a[2] / 3 - 1][a[3] / 3 - 1][a[4] / 3 - 1][a[5] / 3 - 1][a[6] / 3 - 1][a[7] / 3 - 1][a[8] / 3 - 1] = 0;
    
    state i;
    i.vals = s;
    i.moves = "";
    i.cost = 0;
    
    queue< state > q;
    q.push(i);
    
    int flag = true;
    int tot = 0;
    while(!q.empty() && flag)
    {
        tot++;
        state st = q.front(); q.pop();
        
        for(int x = 0; x < 9; x++)
        {
            n = getState(x, st.vals); //New state
            if(states[n[0] - '0' - 1][n[1] - '0' - 1][n[2] - '0' - 1][n[3] - '0' - 1][n[4] - '0' - 1][n[5] - '0' - 1][n[6] - '0' - 1][n[7] - '0' - 1][n[8] - '0' - 1] == -1) //Not visited Before!
            {
                states[n[0] - '0' - 1][n[1] - '0' - 1][n[2] - '0' - 1][n[3] - '0' - 1][n[4] - '0' - 1][n[5] - '0' - 1][n[6] - '0' - 1][n[7] - '0' - 1][n[8] - '0' - 1] = st.cost + 1;
                state s2;
                s2.vals = n;
                s2.moves = st.moves + (char)(x+1+'0');
                s2.cost = st.cost + 1;
                q.push(s2);
                if(states[3][3][3][3][3][3][3][3][3] != -1)
                {
                    for(int w = 0; w < s2.moves.size() - 1; w++)
                        fprintf(fo,"%c ", s2.moves[w]);
                    fprintf(fo,"%c", s2.moves[s2.moves.size() - 1]);
                    fprintf(fo ,"\n");
                    flag = false;
                    break;
                }
            }
            if(states[n[0] - '0' - 1][n[1] - '0' - 1][n[2] - '0' - 1][n[3] - '0' - 1][n[4] - '0' - 1][n[5] - '0' - 1][n[6] - '0' - 1][n[7] - '0' - 1][n[8] - '0' - 1] > st.cost + 1 )
            {
                states[n[0] - '0' - 1][n[1] - '0' - 1][n[2] - '0' - 1][n[3] - '0' - 1][n[4] - '0' - 1][n[5] - '0' - 1][n[6] - '0' - 1][n[7] - '0' - 1][n[8] - '0' - 1] = st.cost + 1;
            }
        }
    }
    printf("%d", tot);
    fclose(f); fclose(fo);
    
    return 0;
}