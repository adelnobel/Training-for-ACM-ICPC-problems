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

using namespace std;

/**
 * 
 * Make all possible combinations of colors, and then for each combination make app the possible permutations
 * check every permutation with the two guesses, if a permutation is consistent with the two guess then its valid!
 * 
 */

typedef struct guess
{
    char s[5];
    int correctPos;
    int wrongPos;
}guess;

char g[5];

guess ar[2];

int main()
{
    //freopen("in.in", "r", stdin);
    
    char s[] = "BGORVY";
    string str;
    vector<string> comb;
    
    for(int a = 0; a < 6; a++)
    {
        for(int b = a + 1; b < 6;  b++)
        {
            for(int c = b + 1 ; c < 6; c++)
            {
                for(int d = c + 1; d < 6; d++)
                {
                    str = "";
                    str += s[a]; str += s[b]; str += s[c]; str += s[d];
                    comb.push_back( str );
                }
            }
        }
    }
    
    int n;
    scanf("%d", &n);
    
    
    while(n--)
    {
        
        
        for(int x = 0; x < 2; x++)
        {
            scanf("%s %d %d", ar[x].s, &ar[x].correctPos, &ar[x].wrongPos);
        }
        
        int tot = 0;
        
        for(int k = 0; k < comb.size(); k++)
        {
            sort(comb[k].begin(), comb[k].end());
            do
            {
                bool valid = true;
                for(int x = 0; x < 2; x++)
                {
                    int mask = 0;
                    int correctPos = 0;
                    int wrongPos = 0;
                    for(int i = 0; i < 4; i++)
                        if(comb[k][i] == ar[x].s[i])
                            mask |= (1 << i), correctPos++;
                    if(correctPos != ar[x].correctPos){
                        valid = false;
                        //break;
                    }
                    int mask2 = 0;
                    for(int i = 0;i < 4; i++)
                    {
                        if((1 << i) & mask) continue;
                        for(int j = 0; j < 4; j++)
                        {
                            if((1 << j) & mask || (mask2 & (1 << j)) || i == j ) continue;
                            if(comb[k][j] == ar[x].s[i]) {
                                mask2 |= (1 << j);
                                wrongPos++;
                            }
                        }
                    }
                    if(wrongPos != ar[x].wrongPos) valid = false;
                }
                if(valid) tot++;
            }while(next_permutation(comb[k].begin(), comb[k].end()));
        };
        
        if(tot > 0) printf("Possible\n");
        else printf("Cheat\n");
        
    }
    
    
    
    
    return 0;
}