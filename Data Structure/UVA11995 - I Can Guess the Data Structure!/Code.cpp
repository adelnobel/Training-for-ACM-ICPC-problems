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

int arr[1001];

bool isPush[1001];

int main()
{
    //freopen("in.in", "r", stdin);
    int n, a;
    
    while(scanf("%d", &n) != EOF)
    {
        memset(isPush, false, sizeof(isPush));
        for(int i = 0; i < n; i++){
            scanf("%d", &a);
            if(a == 1) isPush[i] = true;
            else isPush[i] = false;
            scanf("%d", &arr[i]);
        }
        priority_queue<int> pq;
        stack<int> st;
        queue<int> q;
        
        bool validPq = true, validStack = true, validQueue = true;
        
        for(int i = 0; i < n; i++){
            
            if(isPush[i]){
                pq.push(arr[i]);
                st.push(arr[i]);
                q.push(arr[i]);
            }
            
            else{
                if(validPq)
                {
                    if(pq.empty()) validPq = false;
                    else{
                        if(pq.top() != arr[i]) validPq = false;
                        pq.pop();
                    }
                }
                
                if(validStack)
                {
                    if(st.empty()) validStack = false;
                    else{
                        if(st.top() != arr[i]) validStack = false;
                        st.pop();
                    }
                }
                
                if(validQueue)
                {
                    if(q.empty()) validQueue = false;
                    else{
                        if(q.front() != arr[i]) validQueue = false;
                        q.pop();
                    }
                }
                
            }
            
        }
        
        if(validPq + validQueue + validStack > 1){
            printf("not sure\n");
        }
        else if(validPq + validQueue + validStack == 0){
            printf("impossible\n");
        }
        else{
            if(validPq) printf("priority queue\n");
            else if(validStack) printf("stack\n");
            else printf("queue\n");
        }
        
        
        
    }
    
    
    
    return 0;
}
