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

char s[100010];

int main()
{
    //freopen("in.in", "r", stdin);
    
    
    while(gets(s) != NULL)
    {
        list<string> li;
        int c = 0;
        
        bool pushStart = true;
        string str = "";
        str.reserve(100010);
        
        while(s[c] != '\0')
        {
            if(s[c] == '['){
                if(pushStart)
                    li.push_front(str);
                else
                    li.push_back(str);
                pushStart = true;
                str = "";
            }
            else if(s[c] == ']'){
                if(pushStart)
                    li.push_front(str);
                else
                    li.push_back(str);
                pushStart = false;
                str = "";
            }
            else{
                str += s[c];
            }
            c++;
        }
         if(pushStart)
               li.push_front(str);
         else
               li.push_back(str);
        
        for(list<string>::iterator it = li.begin(); it != li.end(); it++)
            printf("%s", (*it).c_str() );
        printf("\n");
        
        s[0] = '\0';
    }
    

    return 0;
}