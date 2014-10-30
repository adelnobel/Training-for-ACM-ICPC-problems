#include <iostream>
#include <cstdlib>
#include <vector>
#include <cstdio>
#include <ios>
#include <map>
#include <set>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <queue>
#include <cassert>
#include <cmath>
#include <string>
#include <stack>

using namespace std;
typedef long long ll;
typedef vector< vector< ll > > VV;
#define MOD 1000000007

int cnt[1<<7];
vector< int > MASKS;

inline int getKthBitPos(const int& mask, int k){
    int cur = 0;
    for(int i = 0; i < 7; i++){
        if((1 << i) & mask) ++cur;
        if(cur == k) return i;
    }
    assert(false);
    return -1;
}

inline int getMaskPos(const int& mask){
    assert(mask < (1<<7) && cnt[mask] == 4);
    return (int)(lower_bound(MASKS.begin(), MASKS.end(), mask) - MASKS.begin());
}

VV matMul(const VV& a, const VV& b){
    assert(a[0].size() == b.size());
    VV ret(a.size(), vector< ll >(b[0].size(), 0));
    for(int i = 0; i < a.size(); i++){
        for(int j = 0; j < b[0].size(); j++){
            for(int k = 0; k < b.size(); k++){
                ret[i][j] += a[i][k] * b[k][j];
                if(ret[i][j] >= MOD) ret[i][j] %= MOD;
            }
        }
    }
    return ret;
}

VV fastPow(const VV& base, int P){
    if(P == 1) return base;
    VV ret = fastPow(base, P>>1);
    ret = matMul(ret, ret);
    if(P & 1) ret = matMul(ret, base);
    return ret;
} 

int main() {
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    int T, n, to = 1<<7, x;
    for(int i = 0; i < to; i++){
        cnt[i] = __builtin_popcount(i);
        if(cnt[i] == 4) MASKS.push_back(i);
    }

    cin >> T;
    while(T--){
        cin >> n;
        int s = 0;
        for(int i = 0; i < 7; i++){
            cin >> x;
            if(x != 0) s |= 1 << i;
        }
        if(n == 1){
            cout << 1 << endl;
            continue;
        }
        VV M(MASKS.size(), vector<ll>(MASKS.size(), 0));
        
        for(int i = 0; i < MASKS.size(); i++){
            for(int movesMask = 0, t = 1<<4; movesMask < t; movesMask++){
                int nextState = 0;
                bool ok = true;
                for(int j = 0; j < 4 && ok; j++){
                    int pos = getKthBitPos(MASKS[i], j+1);
                    if(movesMask & (1<<j)){
                        ++pos;
                    }else{
                        --pos;
                    }
                    if(pos == 7 || pos == -1 || (nextState & (1<<pos))){
                        ok = false;
                    }else{
                        nextState |= 1 << pos;
                    }
                }
                if(ok){
                    assert(cnt[nextState] == 4);
                    M[i][getMaskPos(nextState)] = 1; 
                }
            }
        }
        
        int ans = 0, pos = getMaskPos(s);
        M = fastPow(M, n-1);
        for(int i = 0; i < MASKS.size(); i++){
            ans += M[pos][i];
            if(ans >= MOD) ans %= MOD;
        }
        
        cout << ans << endl;
        
    }
    
    return 0;
}