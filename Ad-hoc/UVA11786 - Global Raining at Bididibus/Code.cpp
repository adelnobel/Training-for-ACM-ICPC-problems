#include <cstdlib> 
#include <iostream>
#include <vector> 
#include <cstring> 
#include <cassert>
#include <cstdio> 
#include <algorithm> 
#include <map>
#include <set>

using namespace std;


typedef long long ll;

int Y[10006 * 2];

int main() { 
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    
    ios::sync_with_stdio(false);
    
    string s;
    int n, tot = 0;
    cin >> n;
    getline(cin, s);
    while(n--){
        tot = 0;
        getline(cin, s);
        memset(Y, -1, sizeof Y);
        int curDepth = 10004;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '/'){
                curDepth++;
                if(Y[curDepth] != -1){
                    tot += i - Y[curDepth];
                }
            }else if(s[i] == '\\'){
                Y[curDepth] = i;
                --curDepth;
            }
        }
        
        cout << tot << endl;
    }
    
    return 0;
}