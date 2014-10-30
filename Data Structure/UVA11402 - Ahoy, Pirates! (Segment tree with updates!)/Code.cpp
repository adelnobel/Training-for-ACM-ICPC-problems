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

typedef struct node{
    int val;
    char flag;
}node;

#define treeSize 2 * (1 << 21) // (1 << (int)log2(1024000) + 1)
#define LEFT(node) node * 2
#define RIGHT(node) node * 2 + 1

node tree[treeSize];

char tempS[52];

char st[1024010];

void set_update(int node, int intervalSize, char flag)
{
    if(node >= treeSize || flag == ' ') return;
    if(flag == 'I'){
        tree[node].val = intervalSize - tree[node].val; //Invert pirates!
        if(tree[node].flag == ' ') tree[node].flag = 'I';
        else if(tree[node].flag == 'I') tree[node].flag = ' ';
        else if(tree[node].flag == 'F') tree[node].flag = 'E';
        else if(tree[node].flag == 'E') tree[node].flag = 'F';
        return;
    }
    else if(flag == 'F'){
        tree[node].val = intervalSize; //Set all pirates to Bacc
    } 
    else if(flag == 'E'){
        tree[node].val = 0; //Set all pirates to Barb
    }
    tree[node].flag = flag;
}

void propagateFlagToChilds(int node, int curLeft, int curRight)
{
    set_update(LEFT(node), (((curLeft+curRight) / 2) - curLeft) + 1 , tree[node].flag); //Propagate flag to LEFT child
    set_update(RIGHT(node), (curRight - ((curLeft+curRight) / 2 + 1)) + 1 , tree[node].flag); //Propagate flag to RIGHT child
    tree[node].flag = ' '; //Remove flag
}

void update_range(int node, int l, int r, int curLeft, int curRight, char flag)
{
    if(curLeft > r || curRight < l) return; //Current inteval is out of range STOP!
    
    if(curLeft >= l && curRight <= r){
        set_update(node, curRight - curLeft + 1 , flag); //Current interval is in the update range! update and set FLAG!
        //Note that all previous propagations on this node are already done by the parents of this node!
        return;
    }
    
    propagateFlagToChilds(node, curLeft, curRight);
    
    
    update_range(LEFT(node), l, r, curLeft, (curLeft+curRight) / 2, flag); //UPDATE left child range
    update_range(RIGHT(node), l, r, (curLeft+curRight) / 2 + 1, curRight, flag); //UPDATE right child range

    
    tree[node].val = tree[LEFT(node)].val + tree[RIGHT(node)].val; //Set value to equal total of childs!
    
}

int query_range(int node, int l, int r, int curLeft, int curRight)
{
    if(curLeft > r || curRight < l) return 0;
    
    int ret;
    if(curLeft >= l && curRight <= r){
        return tree[node].val; //Current interval is in the query range, return it!
        //Note that tree[node] now has the correct value, since we made all propagations at the parent of this node!
    }
    
    propagateFlagToChilds(node, curLeft, curRight);
    
    ret = query_range(LEFT(node), l ,r , curLeft, (curLeft+curRight) / 2) 
            +
          query_range(RIGHT(node), l ,r , (curLeft+curRight) / 2 + 1, curRight);
    
    tree[node].val = tree[LEFT(node)].val + tree[RIGHT(node)].val; //SET node value to equal the sum of the 2 childs!
    
    return ret; 
}

void build_st(int node, int l, int r)
{
    if(l == r){
        tree[node].val = st[l] - '0';
        tree[node].flag = ' ';
        return;
    }
    
    build_st(LEFT(node), l, (l+r)/2 );
    build_st(RIGHT(node), (l+r)/2 + 1, r );
    
    tree[node].val = tree[LEFT(node)].val + tree[RIGHT(node)].val;
    tree[node].flag = ' ';
    
    return;
}

int main()
{
    //freopen("in.in", "r", stdin);
    
    int T, M, a, q, s, e, curChar;
    char qu;
    
    scanf("%d", &T);
    
    for(int w = 1; w <= T; w++)
    {
        curChar = 0;
        scanf("%d", &M);
        
        printf("Case %d:\n", w);
        
        while(M--){
            scanf("%d", &a);
            scanf("%s", tempS);
            int len = strlen(tempS);
            for(int i = 0; i < a; i++){
                strcpy(st+curChar, tempS);
                curChar += len;
            }
        }
        int totalPirates = curChar;
        
        build_st(1, 0, totalPirates-1);
        
        scanf("%d", &q);
        
        int curQuery = 1;
        while(q--){
            scanf(" %c %d %d", &qu, &s, &e);
            
            if(qu == 'S'){
                printf("Q%d: %d\n", curQuery++, query_range(1, s, e, 0, totalPirates-1));
            }else{
                update_range(1, s, e, 0, totalPirates-1, qu);
            }
        }
    }

    return 0;
}