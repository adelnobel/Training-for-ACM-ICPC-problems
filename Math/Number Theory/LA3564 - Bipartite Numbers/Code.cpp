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
#include <algorithm>
#include <cassert>
#include <queue>
#include <list>
#include <set>
#include <cmath>


using namespace std;
typedef long long ll;
typedef pair< pair<int, int>, pair<int, int> > pi;


#define MAXLEN 10000
#define N 100000
pi ans[N];

int lastMod[N][10];
vector< int > vals[N][10];
int cnt[2];
int vv[2];

bool isBipartite(int n){
    bool another = false;
    int prev = n % 10; 
    cnt[0] = 1, cnt[1] = 0;
    vv[0] = prev;
    n /= 10;
    while(n > 0){
        int c = n % 10;
        if(c != prev){
            if(another) return false;
            vv[1] = c;
            another = true;
            prev = c;
        }
        cnt[another]++;
        n /= 10;
    }
    return another;
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    /*freopen("in.in", "w", stdout);
    for(int i = 1; i < N; i++){
        cout << i << endl;
    }
    cout << 0 << endl;
    return 0;
     */
    int n;
    while(scanf("%d", &n), n != 0){
        bool bipartite = isBipartite(n);
        swap(cnt[0], cnt[1]);
        swap(vv[0], vv[1]);
        if(ans[n].first.first == 0){
            int curPow = 1;
            int mul = 1;
            for(int len = 1; len <= MAXLEN; len++){
                for(int d = 0; d < 10; d++){
                    int v = d * mul;
                    if(v >= n) v %= n;
                    if(lastMod[v][d] != n){
                        lastMod[v][d] = n;
                        vals[v][d].clear();
                    }
                    if(lastMod[v][d] == n){
                        vals[v][d].push_back(len);
                    }
                }
                curPow *= 10;
                mul += curPow;
                if(curPow >= n) curPow %= n;
                if(mul >= n) mul %= n;
            }
            int mini = MAXLEN;
            curPow = 1;
            mul = 1;
            for(int tLen = 1; tLen <= mini; tLen++){
                for(int sDigit = 1; sDigit < 10; sDigit++){
                    for(int tDigit = 0; tDigit < 10; tDigit++){
                        if(tDigit == sDigit) continue;
                        int rightSide = -(tDigit * mul) +(sDigit * mul);
                        rightSide %= n;
                        if(rightSide < 0) rightSide += n;
                        if(lastMod[rightSide][sDigit] == n){
                            int pos = upper_bound(vals[rightSide][sDigit].begin(), 
                                    vals[rightSide][sDigit].end(), tLen) - vals[rightSide][sDigit].begin();
                            if(pos < vals[rightSide][sDigit].size()){
                                if(vals[rightSide][sDigit][pos] < mini){
                                    if(bipartite && vals[rightSide][sDigit][pos] - tLen == cnt[0] && 
                                            sDigit == vv[0] && tLen == cnt[1] && tDigit == vv[1]) continue;
                                    mini = vals[rightSide][sDigit][pos];
                                    ans[n].first.first = vals[rightSide][sDigit][pos] - tLen, ans[n].first.second = sDigit
                                    , ans[n].second.first = tLen, ans[n].second.second = tDigit;
                                }else if(vals[rightSide][sDigit][pos] == mini){
                                    if(bipartite && vals[rightSide][sDigit][pos] - tLen == cnt[0] && 
                                            sDigit == vv[0] && tLen == cnt[1] && tDigit == vv[1]) continue;
                                    if(sDigit < ans[n].first.second){
                                        ans[n].first.first = vals[rightSide][sDigit][pos] - tLen, ans[n].first.second = sDigit
                                        , ans[n].second.first = tLen, ans[n].second.second = tDigit;
                                    }
                                }
                            }
                        }
                    }
                }
                curPow *= 10;
                mul += curPow;
                if(curPow >= n) curPow %= n;
                if(mul >= n) mul %= n;
            }
            assert(mini != MAXLEN);
        }
        
        printf("%d: %d %d %d %d\n", n, ans[n].first.first, ans[n].first.second
                , ans[n].second.first, ans[n].second.second);
    }
    
    
    return 0;
}