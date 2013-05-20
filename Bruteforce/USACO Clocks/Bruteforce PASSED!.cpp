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

string best;
string final = "444444444";
string cur;
string moves;

void getState(int move, int times)
{
    for(int a = 0; a < times; a++ )
    {
        for(int x = 0; x < mapp[move].size();x++)
        {
            cur[mapp[move][x] - 'A'] = (cur[mapp[move][x] - 'A'] == '4' ) ? '1' : cur[mapp[move][x] - 'A']+1;
        }
    }
}

int main() 
{
    FILE* f = fopen("clocks.in", "r");
    FILE* fo = fopen("clocks.out", "w");
    
    mapp[0] = "ABDE"; mapp[1] = "ABC"; mapp[2] = "BCEF";
    mapp[3] = "ADG"; mapp[4] = "BDEFH"; mapp[5] = "CFI";
    mapp[6] = "DEGH"; mapp[7] = "GHI"; mapp[8] = "EFHI";
    
    memset(states, -1, sizeof(states));
    string s = "", best = "";
    
    for(int x = 0; x < 9; x++)
    {
        fscanf(f, "%d", &a[x]);
        s += (a[x] / 3) + '0';
    }
    
    states[a[0] / 3 - 1][a[1] / 3 - 1][a[2] / 3 - 1][a[3] / 3 - 1][a[4] / 3 - 1][a[5] / 3 - 1][a[6] / 3 - 1][a[7] / 3 - 1][a[8] / 3 - 1] = 0;
    
    
    
    for(int a = 0; a < 4; a++)
    {
        for(int b = 0; b < 4; b++)
            for(int c = 0; c < 4; c++)
                for(int d = 0; d < 4; d++)
                    for(int e = 0; e < 4; e++)
                        for(int f = 0; f < 4; f++)
                            for(int g = 0; g < 4; g++)
                                for(int h = 0; h < 4; h++)
                                    for(int i = 0; i < 4; i++)
                                    {
                                        moves = "";
                                        cur = s;
                                        getState(0, a);
                                        getState(1, b);
                                        getState(2, c);
                                        getState(3, d);
                                        getState(4, e);
                                        getState(5, f);
                                        getState(6, g);
                                        getState(7, h);
                                        getState(8, i);
                                        
                                        for(int x = 0; x < a; x++) moves.push_back('1');
                                        for(int x = 0; x < b; x++) moves.push_back('2');
                                        for(int x = 0; x < c; x++) moves.push_back('3');
                                        for(int x = 0; x < d; x++) moves.push_back('4');
                                        for(int x = 0; x < e; x++) moves.push_back('5');
                                        for(int x = 0; x < f; x++) moves.push_back('6');
                                        for(int x = 0; x < g; x++) moves.push_back('7');
                                        for(int x = 0; x < h; x++) moves.push_back('8');
                                        for(int x = 0; x < i; x++) moves.push_back('9');
                                        if(cur == final)
                                        {
                                            if(best.size() == 0 || best > cur)
                                            {
                                                best = moves;
                                            }
                                        }
                                    }
    }
    
    for(int x = 0; x < best.size() - 1; x++)
    fprintf(fo,"%c ", best[x] );
    fprintf(fo, "%c\n", best[best.size()-1]);
    
    fclose(f); fclose(fo);
    
    return 0;
}