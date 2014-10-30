/* In the name of ALLAH, most gracious, most merciful */
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
#include <cassert>

using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

#define N 101015

int ranks[18][N];
int sArr[N];
int lcpArray[N];
int indices[N];
int totalIncluded[N];
char S[N];

int curLog, len;

bool cmp(int a, int b){
    if(ranks[curLog - 1][a] != ranks[curLog - 1][b]) return ranks[curLog - 1][a] < ranks[curLog - 1][b];
    return ranks[curLog - 1][a + (1<<(curLog - 1))] < ranks[curLog - 1][b + (1<<(curLog - 1))];
}

int LCP(int a, int b){
    int ret = 0, offset = 0;
    for(int i = curLog - 1; i >= 0; i--){
        if(ranks[i][a + offset] == ranks[i][b + offset]){
            ret += 1 << i;
            offset += 1 << i;
        }
    }
    return ret;
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    bool printed = false;
    int n;
    while(scanf("%d", &n), n != 0){
        if(printed) printf("\n");
        printed = true;
        memset(ranks, -1, sizeof ranks);
        memset(totalIncluded, 0, sizeof totalIncluded);
        int prevIdx = 0;
        int separator = 1;
        assert(n <= 100);
        for(int i = 0; i < n; i++){
            scanf("%s", S + prevIdx);
            int l = strlen(S + prevIdx);
            S[prevIdx + l++] = separator++;
            if(separator == 97) separator = 123;
            for(int j = 0; j < l; j++){
                indices[prevIdx + j] = i;
            }
            prevIdx += l;
        }
        if(n == 1){
            printf("%s\n", S);
            continue;
        }
        len = prevIdx;
        for(int i = 0; i < len; i++){
            ranks[0][i] = S[i];
            sArr[i] = i;
        }
        for(curLog = 1; (1 << curLog) <= len; curLog++){
            sort(sArr, sArr + len, cmp);
            int curRank = 0;
            ranks[curLog][sArr[0]] = 0;
            for(int j = 1; j < len; j++){
                if(cmp(sArr[j - 1], sArr[j])){
                    ++curRank;
                }
                ranks[curLog][sArr[j]] = curRank;
            }
        }
        lcpArray[0] = len - indices[0];
        for(int i = 0; i < len; i++){
            lcpArray[i] = LCP(sArr[i], sArr[i - 1]);
            //cout << lcpArray[i] << " " << S + sArr[i] << endl;
        }
        vector< int > start;
        deque<int> dq;
        int total = 0;
        int besti = 0;
        for(int i = 0, j = 0; i < len;){
            if(total > n / 2 || j == len){
                if(--totalIncluded[indices[sArr[i]]] == 0){
                    --total;
                }
                if(!dq.empty() && dq.front() == lcpArray[i]) dq.pop_front();
                ++i;
            }else{
                if(++totalIncluded[indices[sArr[j]]] == 1){
                    ++total;
                }
                while(!dq.empty() && dq.back() > lcpArray[j]) dq.pop_back();
                dq.push_back(lcpArray[j]);
                ++j;
            }
            if(total > n / 2){
                bool rmv = false;
                if(!dq.empty() && dq.front() == lcpArray[i]) dq.pop_front(), rmv = true;
                if(dq.front() > besti){
                    start.clear();
                    besti = dq.front();
                }
                if(dq.front() == besti){
                    start.push_back(sArr[i]);
                }
                if(rmv) dq.push_front(lcpArray[i]);
            }
        }
        if(besti == 0){
            printf("?\n");
        }else{
            set< string > se;
            for(int i = 0; i < start.size(); i++){
                string ss = "";
                for(int j = 0; j < besti; j++){
                    ss += S[start[i] + j];
                }
                se.insert(ss);
            }
            for(set<string>::iterator it = se.begin(); it != se.end(); it++){
                printf("%s\n", it->c_str());
            }
        }
        
    }
    
    return 0;
}
