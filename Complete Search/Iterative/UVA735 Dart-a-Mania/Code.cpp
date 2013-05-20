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

bool done[65];

bool canBeProduced[200];

bool alreadyTaken[181][61][61];

int curCombination[3];

int combsNum[181];
int permutNum[181];

int getPermutations()
{
    int c = 0;
    do
    {
        c++;
    }while(next_permutation(curCombination, curCombination+3));
    return c;
}

int main()
{
    //freopen("in.in", "r", stdin);
    memset(done, false, sizeof(done));
    memset(canBeProduced, false, sizeof(canBeProduced));
    
    int n, mini, maxi, tot;
    
    vector< int > v;
    v.push_back(0); v.push_back(50);
    
    for(int a = 1;a <= 20; a++ )
    {
        if(!done[a]) //To not take the same value twice!
        {
            v.push_back(a);
            done[a] = true;
        }
        if(!done[a*a])
        {
            v.push_back(a+a);
            done[a+a] = true;
        }
        if(!done[a+a+a])
        {
            v.push_back(a+a+a);
            done[a+a+a] = true;
        }
    }
    
    for(int i = 0; i < v.size(); i++)
    {
        for(int j = 0; j < v.size(); j++)
        {
            for(int k = 0; k < v.size(); k++) //We store if this combination was taken before in alreadyTaken bool array, so to not take it again!
            {
                
                tot = v[i] + v[j] + v[k];
                mini = min(v[i], min(v[j] , v[k]));
                maxi = max(v[i], max(v[j] , v[k]));
                if(!alreadyTaken[tot][mini][maxi])
                {
                    canBeProduced[tot] = true;
                    curCombination[0] = mini; //We sort the array to generate permutations!
                    curCombination[1] = tot - maxi - mini;
                    curCombination[2] = maxi;

                    combsNum[tot]++;
                    permutNum[tot] += getPermutations();
                    alreadyTaken[tot][mini][maxi] = true;
                }
            }
        }
    }
    
    
    
    while(1)
    {
        scanf("%d", &n);
        if(n <= 0) break;
        
        if(n > 180 || !canBeProduced[n]) {
            printf("THE SCORE OF %d CANNOT BE MADE WITH THREE DARTS.\n", n);
        }
        else
        {
            printf("NUMBER OF COMBINATIONS THAT SCORES %d IS %d.\n",n, combsNum[n] );
            printf("NUMBER OF PERMUTATIONS THAT SCORES %d IS %d.\n", n, permutNum[n]);
        }
        
        printf("**********************************************************************\n");
    }
    
    printf("END OF OUTPUT\n");
    
    return 0;
}