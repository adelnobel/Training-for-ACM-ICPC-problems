/* In the name of ALLAH, most gracious, most merciful */
#include <iostream>
#include <string>
#include <ctime>
#include <map>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <iomanip>
#include <cstdio>

using namespace std;
typedef pair<int, int> pi;

#define IDX(c) (c == '.' ? 0 : 1)

typedef struct node{
    int CH[2];
    int endsHere;
    node(){CH[0] = CH[1] = -1, endsHere = 0;};
}node;
vector< node > trie;
string T[128];

string M, S;

void insert(){
    int cur = 0;
    char c;
    for(int i = 0; i < S.size(); i++){
        c = S[i];
        for(int j = 0; j < T[c].size(); j++){
            int p = IDX(T[c][j]);
            if(trie[cur].CH[p] == -1){
                trie[cur].CH[p] = trie.size();
                trie.push_back(node());
            }
            cur = trie[cur].CH[p];
        }
    }
    ++trie[cur].endsHere;
}

#define N 1005
int dp[N];

int solve(int idx){
    if(idx == M.size()) return 1;
    int& ret = dp[idx];
    if(ret != -1) return ret;
    ret = 0;
    int cur = 0;
    for(int i = idx; i < M.size(); ++i){
        cur = trie[cur].CH[IDX(M[i])];
        if(cur == -1) break;
        if(trie[cur].endsHere > 0) ret += trie[cur].endsHere * solve(i + 1);
    }
    return ret;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    T['A'] = ".-",  T['B'] = "-...",  T['C'] = "-.-.";
    T['D'] = "-..",  T['E'] = ".",  T['F'] = "..-."  ;
    T['G'] = "--.",  T['H'] = "....",  T['I'] = ".."  ;
    T['J'] = ".---",  T['K'] = "-.-",  T['L'] = ".-.."; 
    T['M'] = "--",  T['N'] = "-.",  T['O'] = "---"  ;
    T['P'] = ".--.",  T['Q'] = "--.-",  T['R'] = ".-."  ;
    T['S'] = "...",  T['T'] = "-",  T['U'] = "..-"  ;
    T['V'] = "...-",  T['W'] = ".--",  T['X'] = "-..-";
    T['Y'] = "-.--",  T['Z'] = "--..";
    bool L = false;
    int T, n;
    cin >> T;
    while(T--){
        if(L) cout << endl;
        L = true;
        trie.clear();
        trie.push_back(node());
        cin >> M;
        cin >> n;
        while(n--){
            cin >> S;
            insert();
        }
        memset(dp, -1, sizeof dp);
        cout << solve(0) << endl;
    }
    
    
    
    return 0;
}