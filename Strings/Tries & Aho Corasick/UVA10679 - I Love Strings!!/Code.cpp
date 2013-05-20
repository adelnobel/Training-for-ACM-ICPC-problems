#include <vector>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cctype>

using namespace std;

typedef long long ll;


typedef struct node{
    int childs[52];
    vector<int> wordIdices;
    int fail;
    node(){
        memset(childs, -1, sizeof childs);
        wordIdices = vector<int>();
        fail = 0;
    }
    
    node(int wi, int f){
        wordIdices = vector<int>();
        fail = f;
        memset(childs, -1, sizeof childs);
    }
}node;

typedef struct failureNode{
    int father, node, nodeChar;
    failureNode(){};
    failureNode(int f, int n, int nc){
        father = f;
        node = n;
        nodeChar = nc;
    }
}failureNode;

vector<node> trie;

char s[100010];

char query[2010];

bool answers[1010];

int lastAddedNode;

int getPos(char a)
{
    if(a <= 'Z'){
        return (a - 'A') + 26;
    }else{
        return a - 'a';
    }
}

void addToTrie(int curWord)
{
    int curChar = 0;
    int curNode = 0;
    
    while(query[curChar] != '\0' && trie[curNode].childs[getPos(query[curChar])] != -1){
        curNode = trie[curNode].childs[getPos(query[curChar])];
        curChar++;
    }
    
    while(query[curChar] != '\0'){
        trie[curNode].childs[getPos(query[curChar])] = lastAddedNode+1;
        trie.push_back(node(-1, 0));
        lastAddedNode++;
        curNode = lastAddedNode;
        curChar++;
    }
    trie[curNode].wordIdices.push_back(curWord);
}

void generateFails()
{
    queue<failureNode> q;
    
    for(int i = 0; i < 52; i++){
         if(trie[0].childs[i] != -1){
              q.push(failureNode(0, trie[0].childs[i], i));
         }
    }
    
    while(!q.empty()){
        failureNode cur = q.front(); q.pop();
        int fatherFail = trie[cur.father].fail;
        int nodeChar = cur.nodeChar;
        while(fatherFail != -1){
            if(trie[fatherFail].childs[nodeChar] != -1){
                trie[cur.node].fail = trie[fatherFail].childs[nodeChar];
                break;
            }else{
                fatherFail = trie[fatherFail].fail;
            }
        }
        for(int i = 0; i < 52; i++){
            if(trie[cur.node].childs[i] != -1){
                q.push(failureNode(cur.node, trie[cur.node].childs[i], i));
            }
        }
    }
}

bool memo[1000010];

void getFailures(int node)
{
    while( !(node == 0 || node == -1) ){
      if(memo[node] != false) {
          return;
      }
      memo[node] = true;
      for(int i = 0; i < trie[node].wordIdices.size(); i++){
           answers[trie[node].wordIdices[i]] = true;
      }
      node = trie[node].fail;
    }
}

int main()
{
    /**
    freopen("in.in", "w", stdout);
    printf("%d\n", 10);
    
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10000/2; j++){
            printf("%c", (rand() % 26) + 'a' );
            printf("%c", (rand() % 26) + 'A' );
        }
        printf("\n1000\n");
        for(int j = 0; j < 1000; j++){
            for(int k = 0; k < 1000/2;k++){
                printf("%c", (rand() % 26) + 'a' );
                printf("%c", (rand() % 26) + 'A' );
            }
            printf("\n");
        }
        
    }
    **/

    //freopen("in.in", "r", stdin);
    
    int t, q;
    
    scanf("%d", &t);
    
    while(t--){
        trie.clear();
        memset(memo, false, sizeof memo);
        memset(answers, false, sizeof answers);
        lastAddedNode = 0;
        scanf("%s", s);
        trie.push_back(node(-1, -1));
        scanf("%d", &q);
        for(int i = 0; i < q; i++){
              scanf("%s", query);
              addToTrie(i);
        }
        
        generateFails();

        int len = strlen(s), tot = 0;
        
        
        for(int i = 0; i < len;i++){
            int curNode = 0;
            int c = i;
            int next = trie[curNode].childs[getPos(s[c])];
            while(next != -1 && next != 0)
            {
                curNode = next;
                getFailures(curNode);
                c++;
                if(c >= len) break;
                next = trie[curNode].childs[getPos(s[c])];
                if(next == -1){
                    next = trie[curNode].fail;
                    c--;
                }
            }
            if(c != i) i = c-1;
        }
        
        for(int i = 0; i < q; i++){
            if(answers[i]){
                printf("y\n");
            }else{
                printf("n\n");
            }
        }
    }
    
    
    return 0;
}