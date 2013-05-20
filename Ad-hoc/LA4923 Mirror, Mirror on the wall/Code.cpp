#include <cstring>
#include <algorithm>
#include <functional>
#include <vector>
#include <map>
#include <set>
#include <fstream>
#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>


using namespace std;

int arr[50];

char str[3000];

int main() 
{
    memset(arr, -1, sizeof(arr));
    
    arr['b' - 'a'] = 'd' - 'a';arr['i' - 'a'] = 'i' - 'a';arr['v' - 'a'] = 'v' - 'a';arr['x' - 'a'] = 'x' - 'a';
    arr['p' - 'a'] = 'q' - 'a';arr['o' - 'a'] = 'o' - 'a';arr['w' - 'a'] = 'w' - 'a';
    arr['d' - 'a'] = 'b' - 'a';arr['q' - 'a'] = 'p' - 'a';
    while(1)
    {
        scanf("%s", str);
        if(str[0] == '#')
            break;
        
        string s = "";
        bool valid = true;
        int co = 0;
        while(str[co] != '\0')
        {
            if( arr[str[co] - 'a'] == -1 )
            {
                valid = false; 
                break;
            }
            s += arr[str[co] - 'a'] + 'a';
            co++;
        }
        
        if(valid)
            cout << string(s.rbegin(), s.rend()) << endl;
        else
            cout << "INVALID" << endl;
        
    }
    
    return 0;
}


