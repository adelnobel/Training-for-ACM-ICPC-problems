/*
ID: adelnob1
PROG: namenum
LANG: C++
*/
#include <vector>
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

using namespace std;

char s[30];

char m[256];


int main()
{
#ifndef ONLINE_JUDGE
    freopen("namenum.in", "r", stdin);
    freopen("namenum.out", "w", stdout);
#endif
    
    m['A'] = m['B'] = m['C'] = '2';
    m['D'] = m['E'] = m['F'] = '3';
    m['G'] = m['H'] = m['I'] = '4';
    m['J'] = m['K'] = m['L'] = '5';
    m['M'] = m['N'] = m['O'] = '6';
    m['P'] = m['R'] = m['S'] = '7';
    m['T'] = m['U'] = m['V'] = '8';
    m['W'] = m['X'] = m['Y'] = '9';
    
    vector<string> valid; 
    
    string n;
    cin >> n;
    
    FILE* f = fopen("dict.txt", "r");
    while(fscanf(f, "%s", s) == 1){
        
        int l = strlen(s);
        if(l != n.size()) continue;
        int i = 0;
        while(n[i] == m[s[i]] && i < l) i++;
        if(i == l) valid.push_back(string(s));
    }
    
    if(valid.size() == 0) cout << "NONE" << endl;
    else{
        for(int i = 0; i < valid.size(); i++){
            cout << valid[i] << endl;
        }
    }
    


    
    return 0;
}