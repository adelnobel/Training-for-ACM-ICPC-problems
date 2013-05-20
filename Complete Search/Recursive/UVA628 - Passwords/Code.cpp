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

char dict[105][300];

char rules[1005][300];
    
int d, l;

void solve(int curInd, int curRule, string s){
    if(rules[curRule][curInd] == '\0'){
        printf("%s\n", s.c_str());
        return;
    }
    if(rules[curRule][curInd] == '0'){
        for(int i = 0; i < 10; i++){
            //printf("%d", i);
            solve(curInd + 1, curRule, s + (char)(i+'0') );
        }
    }
    else if(rules[curRule][curInd] == '#'){
        for(int i = 0; i < d; i++){
            //printf("%s", dict[i]);
            solve(curInd + 1, curRule, s + dict[i]);
        }
    }
    
}

int main()
{
    //freopen("in.in", "r", stdin);
    
    while(scanf("%d", &d) != EOF)
    {
        for(int i = 0; i < d; i++)
            scanf("%s", dict[i]);
        
        scanf("%d", &l);
        printf("--\n");
        
        for(int i = 0; i < l; i++){
            scanf("%s", rules[i]);
            solve(0, i, "");
        }
    }

    return 0;
}