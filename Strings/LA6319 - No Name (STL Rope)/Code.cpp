#include <cstdio>
#include <cstring>
#include <queue>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <bitset>
#include <map>
#include <complex>
#include <ctime>
#include <numeric>
#include <set>
#include <cassert>

#include <ext/rope>

using namespace std;

typedef pair<int, int> pi;
typedef long long ll;

using namespace __gnu_cxx; 

char s[(int)1e6 + 5];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
    int T, p, a, b;
    scanf("%d ", &T);
    while(T--){
        rope< char > r;
        scanf("%s", s);
        r.insert(0, s);
        while(scanf("%s", s), !(s[0] == 'E' && s[1] == 'N' && s[2] == 'D')){
            if(s[0] == 'I'){
                scanf("%s %d ", s, &p);
                r.insert(p, s);
            }else{
                scanf("%d %d ", &a, &b);
                cout << r.substr(a, b-a+1) << endl;
            }
        }
    }
   
    
    
    return 0;
}
