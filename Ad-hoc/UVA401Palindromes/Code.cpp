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

char str[3000];

map<char, char> ma;

bool isReversed(string s)
{
    string rev = s;
    for(int x = 0; x < s.size(); x++)
    {
        if(ma.count(s[x]) > 0)
        {
            rev[x] = ma[s[x]];
        }
        else
            return false;
    }
    if(s == string(rev.rbegin(), rev.rend()))
        return true;
    return false;
}

int main() 
{
    ma['A'] = 'A'; ma['E'] = '3'; ma['H'] = 'H'; ma['I'] = 'I'; ma['J'] = 'L'; ma['L'] = 'J';
    ma['M'] = 'M'; ma['O'] = 'O'; ma['S'] = '2'; ma['T'] = 'T'; ma['W'] = 'W'; ma['U'] = 'U';
    ma['V'] = 'V'; ma['X'] = 'X'; ma['Y'] = 'Y'; ma['Z'] = '5'; ma['1'] = '1'; ma['2'] = 'S';
    ma['3'] = 'E'; ma['5'] = 'Z'; ma['8'] = '8';
    
    
    
    while(scanf("%s", str) != EOF)
    {
        string s = str;
        
        bool pal = false;
        bool rev = false;
        
        if(s == string( s.rbegin(), s.rend() ) )
            pal = true;
        if(isReversed(s))
            rev = true;
        
        
        if(!pal && !rev)
            cout << s << " -- is not a palindrome." << endl;
        else if(pal && !rev)
            cout << s << " -- is a regular palindrome." << endl;
        else if(!pal && rev)
            cout << s << " -- is a mirrored string." << endl;
        else if(pal && rev)
            cout << s << " -- is a mirrored palindrome." << endl;
        
        cout << endl;
        
        
    }
                        
                        
    
    return 0;
}


