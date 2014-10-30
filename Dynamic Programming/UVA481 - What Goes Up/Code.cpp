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

#define strictlyIncreasing

#define N 20


int parents[N]; //Store parent for each element!
int sequences[N]; //This array contains the sequences, sequences[i] = a position in the array 'arr' which is the last element
//in a subsequence of length i !
// Note this array 'sequences' is always sorted in terms of arr[subsequence[i]]
int arr[N]; 

stack<int> seq; //The sequence is reversed!

int mycmp(int first, int second)
{
    if(first == -1) return false; //If there is no previously known sequence that ends here!
    if(second == -1) return true; // same as above
    return arr[first] < arr[second];
}

int main()
{
    freopen("in.in", "r", stdin);
    
    memset(sequences, -1, sizeof sequences); //Initialize sequences positions with -1
    
    int c = 0;
    
    while(scanf("%d", &arr[c]) != EOF){
        c++;
    };
    
    int maxiSoFar = 0;
    
    for(int i = 0; i < c; i++){
        int pos = (int)(upper_bound(sequences, sequences+maxiSoFar+1, i, mycmp) - sequences);
        
#ifdef strictlyIncreasing
        if(pos != 0){
            if(arr[sequences[pos-1]] == arr[i]){
                pos--;
            }
        }
#endif 
        sequences[pos] = i;
        maxiSoFar = max(maxiSoFar, pos);
        if(pos == 0){
            parents[i] = -1;
        }else{
            parents[i] = sequences[pos-1];
        }
    }
    
    int cur = sequences[maxiSoFar];
    
    for(int x = maxiSoFar; x >= 0; x--){
        seq.push(arr[cur]);
        cur = parents[cur];
    }
    
    printf("%d\n-\n", maxiSoFar+1);
    
    while(!seq.empty()){
        printf("%d\n", seq.top());
        seq.pop();
    }
    
   
    return 0;
}

