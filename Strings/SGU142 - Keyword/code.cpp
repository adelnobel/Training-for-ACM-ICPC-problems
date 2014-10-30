#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <algorithm>
#include <iostream>
#include <map>
#include <cmath>
#include <set>
#include <cassert>
#include <ctime>
#include <bitset>

using namespace std;

typedef long long ll;

#define BASE 3

#define N 500008

unsigned int H[N];
char s[N];
int n, curLen;
char str[22];
vector< string > ans;

bool recur(int rem, unsigned int curHash){
    if(rem == 0){
        bool x = binary_search(H, H+n-curLen+1, curHash);
        if(!x) {
            str[curLen] = '\0';
            ans.push_back(str);
        }
        return !x;
    }
    str[curLen - rem] = 'a';
    bool a = recur(rem-1, curHash * BASE + 0);
    if(a) return true;
    str[curLen - rem] = 'b';
    bool b = recur(rem-1, curHash * BASE + 1);
    
    return b;
}

bool solve(int len){
    if(len > n) return true;
    unsigned int pLen = 1;
    H[0] = 0;
    for(int i = 0; i < len; i++){
        H[0] = (H[0] * BASE) + s[i] - 'a';
        pLen *= BASE;
    }
    pLen /= BASE;
    for(int i = len; i < n; i++){
        H[i - len + 1] = H[i-len] - ((s[i-len] - 'a') * pLen);
        H[i - len + 1] *= BASE;
        H[i - len + 1] += s[i] - 'a';
    }
    
    sort(H, H+n-len+1);
    curLen = len;
    return recur(len, 0);
}

bool cmp(const string& a, const string & b){
    if(a.size() != b.size()) return a.size() < b.size();
    return a < b;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    
    scanf("%d ", &n);
    gets(s);
    
    int lo = 1, hi = 20, mid, best;
    
    while(lo <= hi){
        mid = (lo+hi) / 2;
        if(solve(mid)){
            hi = mid - 1;
            best = mid;
        }else{
            lo = mid + 1;
        }
    }
    
    sort(ans.begin(), ans.end(), cmp);

    cout << best << endl;
    cout << ans[0] << endl;
    
    return 0;
}