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

#define logVal 17 // (log2(100010)) + 1)

#define treeSize 2 * (1 << logVal)

int arr[100010];
int freq[100010];
int tree[ treeSize ];



#define INF 1 << 30

void build_st(int node, int l, int r)
{
    if(l == r){
        tree[node] = l;
        return;
    }
    
    build_st(node*2, l, (l+r)/2 );
    build_st(node*2+1, ((l+r)/2)+1, r );
    
    if(freq[tree[node*2]] >= freq[tree[node*2 + 1]]){
        tree[node] = tree[node*2];
    }else{
        tree[node] = tree[node*2 + 1];
    }
    return;
}

int query_max(int node, int l, int r, int curLeft, int curRight)
{
    if(curRight < l || curLeft > r) {
        return -1;
    }
    if(l <= curLeft && r >= curRight){
        return tree[node];
    }
    int leftChild = query_max(node*2, l, r, curLeft, (curLeft+curRight) / 2) ;
    int rightChild = query_max(node*2 + 1, l, r, ((curLeft+curRight) / 2) + 1 , curRight );
    
    if(leftChild == -1) return rightChild;
    if(rightChild == -1) return leftChild;
    
    if(freq[leftChild] >= freq[rightChild] )
        return leftChild;
    return rightChild;
    
}

int main()
{
    //freopen("in.in", "r", stdin);
    
    int n, q, s, e;
    
    while(1)
    {
        scanf("%d", &n);
        if(n == 0) break;
        scanf("%d", &q);
        
        int prev = INF;
        int startPos = -1;
        
        for(int i = 0; i < n; i++){
            scanf("%d", &arr[i]);
            if(arr[i] != prev){
                if(startPos != -1){
                    for(int j = startPos; j < i; j++){
                        freq[j] = i - startPos;
                    }
                }
                prev = arr[i];
                startPos = i;
            }
        }
        
        for(int j = startPos; j < n; j++){
            freq[j] = n - startPos;
        }
        
        
        build_st(1, 0, n-1);
        
        for(int i = 0; i < q; i++){
            scanf("%d %d", &s, &e);
            s -= 1; e -= 1;
            int middleStart = s, middleEnd = e;
            int maxi = 1, maxiPos = -1;
            if(s != 0 && arr[s-1] == arr[s]){
                int c = 0;
                while(s+c <= e && arr[s] == arr[s+c]) c++;
                if(c > maxi){
                    maxi = c; maxiPos = s;
                }
                middleStart = s+c;
            }
            if(e != n && arr[e] == arr[e+1]){ 
                int c = 0;
                while(e-c >= s && arr[e] == arr[e-c]) c++;
                if(c > maxi){
                    maxi = c, maxiPos = e;
                }
                middleEnd = e-c;
            }
            
            if(middleEnd - middleStart > 0){
                int middleMaxiPos = query_max(1, middleStart, middleEnd, 0, n-1);
                int middleMaxiVal = freq[middleMaxiPos];

                if(maxi < middleMaxiVal){
                    maxiPos = middleMaxiPos;
                    maxi = middleMaxiVal;
                }
            }
            
            printf("%d\n", maxi);
            
        }
    }
    
    
    return 0;
}