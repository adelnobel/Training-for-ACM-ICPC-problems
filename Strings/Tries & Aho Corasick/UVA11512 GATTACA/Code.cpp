#include <vector>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cctype>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long ll;

#define N 1010

char s[N];

int len, maxi, lastAddedNode;



typedef struct node{
    
    int childs[4];
    int wordsHere, start, end;
    
    node(){
        wordsHere = 0;
        start = end = -1;
        memset(childs, -1, sizeof childs);
    }
    
}node;

vector<node> trie;

int mapp[256];

void addToTrie(int st, int en)
{
    int i = st;
    int curNode = 0;
    while(i <= en && trie[curNode].childs[mapp[s[i]]] != -1){
        curNode = trie[curNode].childs[mapp[s[i]]];
        
        trie[curNode].wordsHere++;
        trie[curNode].start = st;
        trie[curNode].end = i;
        
        i++;
    }
    
    while(i <= en){
        trie[curNode].childs[mapp[s[i]]] = lastAddedNode+1;
        trie.push_back(node());
        lastAddedNode++;
        curNode = lastAddedNode;
        
        trie[curNode].wordsHere++;
        trie[curNode].start = st;
        trie[curNode].end = i;
        i++;
    }
    

}

int traverseTrie(int root)
{
    if(root == -1) return -1;
    
    int best = -1;
    if(trie[root].wordsHere > 1){
        best = root;
    }
    
    for(int i = 0; i < 4; i++){
        int cur = trie[root].childs[i] == -1 ? -1 : traverseTrie(trie[root].childs[i]);
        if(cur != -1){
            if(best == -1) best = cur;
            else if(trie[cur].end - trie[cur].start > trie[best].end - trie[best].start){
                best = cur;
            }
        }
    }
    
    return best;
    
}

int main()
{
    //freopen("in.in", "r", stdin);
    //freopen("in.out", "w", stdout);
    
    mapp['A'] = 0;
    mapp['C'] = 1;
    mapp['G'] = 2;
    mapp['T'] = 3;
    
    int t;
    scanf("%d ", &t);
    
    while(t--){
        trie.clear();
        trie.push_back(node());
        lastAddedNode = 0;
        maxi = 0;
        scanf("%s", s);
        len = strlen(s);
        
        for(int i = 0; i < len; i++){
                addToTrie(i, len-1);
        }

        maxi = traverseTrie(0);
        
        if(maxi == 0 || trie[maxi].wordsHere == 1 || maxi == -1){
            printf("No repetitions found!\n");
        }else{
            printf("%.*s %d\n", trie[maxi].end - trie[maxi].start + 1 , s + trie[maxi].start , trie[maxi].wordsHere);
        }
    
    }
    
    return 0;
}