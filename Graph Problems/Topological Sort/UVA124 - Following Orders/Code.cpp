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

typedef long long ll;

bool mat[27][27];

bool chars[27];

char s[1000];
char s2[1000];

char order[1000];

int tot;

void go(int cur, int takenMask, int depth)
{
    if(depth == tot){
        order[depth] = '\0';
        for(int i = 0; i < depth; i++){
            for(int j = i+1; j < depth; j++){
                if(mat[order[j]-'a'][order[i]-'a']){
                    return;
                }
            }
        }
        printf("%s", order);
        printf("\n");
        return;
    }
    
    for(int i = 0; i < 27; i++){
        if(i == cur || ((1 << i) & takenMask)) continue;
        if(mat[cur][i] || ( chars[i] && !mat[i][cur])){
            order[depth] = i+'a';
            go(i, (1 << i) | takenMask, depth+1);
        }
    }
    
}

int main()
{
    //freopen("in.in", "r", stdin);
    int cc = 0;
    char a, b;
    
    while(1){
        s[0] = '\0';
        gets(s);
        if(s[0] == '\0') break;
        gets(s2);
        if(cc > 0) printf("\n");
        cc++;
        memset(chars, false, sizeof chars);
        memset(mat, false, sizeof mat);
        tot = 0;
        
        int lastScanned = 0, totScanned;
        while(sscanf(s+lastScanned, "%c %n", &a, &totScanned) == 1){
            lastScanned += totScanned;
            chars[a-'a'] = true;
            tot++;
        }
        lastScanned = 0;
        while(sscanf(s2+lastScanned, "%c %c %n", &a, &b, &totScanned) == 2){
            lastScanned += totScanned;
            mat[a-'a'][b-'a'] = 1;
            mat[b-'a'][a-'a'] = 0;
        }
        
        for(int k = 0; k < 27; k++){ //Transitive closure!
            for(int i = 0; i < 27; i++){
                for(int j = 0; j < 27; j++){
                    if(mat[i][k] && mat[k][j]){
                        mat[i][j] = 1;
                    }
                }
            }
        }
        
        /**
        for(int i = 0; i < 27; i++){
            for(int j = 0; j < 27; j++){
                if(mat[i][j]){
                    //printf("%c < %c\n", i+'a', j+'a');
                }
            }
        }**/
        
        for(int i = 0; i < 27; i++){
            if(chars[i]){
                order[0] = i+'a';
                go(i, 1 << i, 1);
            }
        }
        
        
    }
    
    
    return 0;
}