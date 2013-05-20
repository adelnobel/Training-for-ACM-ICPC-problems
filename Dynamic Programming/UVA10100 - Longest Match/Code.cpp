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

/**
 LCS DP
 */


short memo[1005][1005];


char s1[1005], s2[1005], temp[1005];
vector<string> v1, v2;

int solve(int idx1,int idx2){
    if(idx1 < 0 || idx2 < 0 ){
        return 0;
    }
    if(memo[idx1][idx2] != -1) return memo[idx1][idx2];
    short ret;
    if(v1[idx1] == v2[idx2]){
        ret = 1 + solve(idx1-1, idx2-1);
    }else{
        ret = max(solve(idx1-1, idx2), solve(idx1, idx2-1));
    }
    
    return memo[idx1][idx2] = ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    
    int c = 1;
    
    while((s1[0]=s2[0]='\0'), gets(s1) && gets(s2)){
        memset(memo, -1, sizeof memo);
        int l1 = strlen(s1), l2 = strlen(s2);
        printf("%2.d. ", c++);
        if(l1 == 0 || l2 == 0){
            printf("Blank!\n");
            continue;
        }
        for(int i = 0; i < l1; i++){
            if(!isalnum(s1[i])){
                s1[i] = ' ';
            }
        }
        for(int i = 0; i < l2; i++){
            if(!isalnum(s2[i])){
                s2[i] = ' ';
            }
        }
        
        v1.clear(); v2.clear();
        
        int cur = 0, cnt;
        while(sscanf(s1+cur,"%s%n", temp, &cnt) == 1){
             v1.push_back(string(temp));
            cur += cnt;
        }
        cur = 0;
        while(sscanf(s2+cur,"%s%n", temp, &cnt) == 1){
            v2.push_back(string(temp));
            cur += cnt;
        }
        
        
        printf("Length of longest match: %d\n", (int)solve(((int)v1.size())-1, ((int)v2.size())-1));
    }
    

    return 0;
}