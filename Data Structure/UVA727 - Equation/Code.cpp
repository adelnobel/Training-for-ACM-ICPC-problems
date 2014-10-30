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

string infix;
int pointer;

string evaluate()
{
    string ret = "";
    ret.reserve(50);
    stack<char> st;
    for(; pointer < infix.size() && infix[pointer] != ')'; pointer++){
        if(infix[pointer] == '(' ){ //If current is '(' then we have a new expression inside that needs to be evaluated!
            pointer++; //Increase the pointer (to avoid infinite loops!)
            ret += evaluate(); //Evaluate this expression on its own and append the evaluated exp to the current string!
        }
        else if(isdigit(infix[pointer])){ //If a digit, we add to the postfix string
            ret += infix[pointer];
        }
        else if(infix[pointer] == '+' || infix[pointer] == '-'){//If is + or - operand
                while(!st.empty()){ //While the stack is not empty, keep popping the stack as long as the top of stack has higher or equal priority to - or + until it gets empty
                    ret += st.top(); //Append top of stack to the postfix string
                    st.pop(); //pop top of stack
                }
                st.push(infix[pointer]);  //push the + or - operand to top of stack!
        }
        else if(infix[pointer] == '*' || infix[pointer] == '/'){ //If is * or / operand
               while( !st.empty() && (st.top() == '*' || st.top() == '/') ){ //While stack is not empty, keep popping from the stack and appending to the postfix string, AS LONG AS top of stack has higher or equal priority to current operand
                     ret += st.top();
                     st.pop();
                }
                st.push(infix[pointer]); //Now we can push the operand to the stack
        }
    }
    
    while(!st.empty()){ //Pop all the operands on the stack and append to the postfix string
        ret += st.top();
        st.pop();
    }
    
    return ret;
}


int main()
{
    //freopen("in.in", "r", stdin);
    
    int n, cc = 0;
    char a[3];
    
    scanf("%d\n\n", &n );
    
    while(n--)
    {
        if(cc++) printf("\n");
        infix = "";
        while(1){
            a[0] = '\0';
            gets(a);
            if( a[0] == '\0' ) break;
            infix += a[0];
        }
        
        pointer = 0;
        printf("%s\n", evaluate().c_str());
        
    }
    
    
    return 0;
}
