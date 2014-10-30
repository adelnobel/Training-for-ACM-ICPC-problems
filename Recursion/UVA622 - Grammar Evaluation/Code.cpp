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
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>

using namespace std;

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
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <ctime>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pl;
typedef pair<int, int> pi;


enum TOKENNAME{
    INT,
    LPAREN,
    RPAREN,
    PLUS,
    MINUS,
    DIVIDE,
    MULTIPLY,
    ENDOFFILE
};

typedef struct TOKEN{
    ll val;
    TOKENNAME token;
    TOKEN(){};
    TOKEN(int a, TOKENNAME t): val(a), token(t){};
};

bool lexingError;

void raiseLexerError(){
    lexingError = true;
}

vector< TOKEN > lexer(const string& s){
    vector< TOKEN > ret;
    for(int i = 0; i < s.size(); ){
        if(isspace(s[i])){
            i++;
        }else if(isdigit(s[i])){
            ll val = 0;
            while(i < s.size() && isdigit(s[i])){
                val = val * 10 + s[i] - '0';
                i++;
            }
            ret.push_back(TOKEN(val, INT));
        }else{
            if(s[i] == '+') ret.push_back(TOKEN(0, PLUS));
            //else if(s[i] == '-') ret.push_back(TOKEN(0, MINUS));
            else if(s[i] == '*') ret.push_back(TOKEN(0, MULTIPLY));
            //else if(s[i] == '/') ret.push_back(TOKEN(0, DIVIDE));
            else if(s[i] == '(') ret.push_back(TOKEN(0, LPAREN));
            else if(s[i] == ')') ret.push_back(TOKEN(0, RPAREN));
            else{
                raiseLexerError();
            }
            i++;
        }
    }
    ret.push_back(TOKEN(0, ENDOFFILE));
    return ret;
}

/**
 * S -> E ENDOFFILE
 * E -> T + E | T - E | T
 * T -> F * T | F / T | F
 * F -> int | (E)
 * ----------------------------
 * RIGHT ASSOCIATIVE GRAMMAR -> parses 5 - 3 - 4 to 5 - (3 - 4)
 */

typedef pair< bool, ll> pb;
int currentToken = 0;

vector< TOKEN > tokens;

int total = 0;

bool checkAndConsume(TOKENNAME t){
    total++;
    if(currentToken < tokens.size() && tokens[currentToken].token == t){
        currentToken++;
        return true;
    }
    return false;
}

pb E();
pb T();
pb F();

pb S(){
    pb val = E();
    return pb(val.first && checkAndConsume(ENDOFFILE), val.second);
}

pb E(){
    int save = currentToken;
    pb ret1, ret2;
    if((ret1 = T(), ret1.first)){
        int save1 = currentToken;
        if(checkAndConsume(PLUS) && (ret2 = E(), ret2.first)){
            return pb(true, ret1.second + ret2.second);
        }
        currentToken = save1;
        if(checkAndConsume(MINUS) && (ret2 = E(), ret2.first)){
            return pb(true, ret1.second - ret2.second);
        }
        return ret1;
    }
    return pb(false, 0);
}

pb T(){
    int save = currentToken;
    pb ret1, ret2;
    if((ret1 = F(), ret1.first)){
        int save1 = currentToken;
        if(checkAndConsume(MULTIPLY) && (ret2 = T(), ret2.first)){
            return pb(true, ret1.second * ret2.second);
        }
        currentToken = save1;
        if(checkAndConsume(DIVIDE) && (ret2 = T(), ret2.first)){
            return pb(true, ret1.second / ret2.second);
        }
        return ret1;
    }
    return pb(false, 0);
}

pb F(){
    //int save = currentToken;
    pb ret1;
    if(checkAndConsume(INT)){
        return pb(true, tokens[currentToken - 1].val);
    }
    //currentToken = save;
    if(checkAndConsume(LPAREN) && (ret1 = E(), ret1.first) && checkAndConsume(RPAREN)){
        return ret1;
    }
    return pb(false, 0);
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T;
    cin >> T;
    while(T--){
        string s;
        currentToken = 0;
        lexingError = false;
        cin >> s;
        string x = "";
        for(int i = 0; i < s.size(); i++){
            if(!isspace(s[i])) x += s[i];
        }
        s = x;
        tokens = lexer(s);
        pb ret = S();
        if(lexingError || !ret.first) cout << "ERROR";
        else cout << ret.second;
        cout << '\n';
    }


    return 0;
}
