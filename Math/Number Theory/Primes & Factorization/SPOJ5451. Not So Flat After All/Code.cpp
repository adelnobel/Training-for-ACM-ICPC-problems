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

int a, b;
map<int, int> m1;
map<int, int> m2;

int main()
{
    //freopen("in.in", "r", stdin);
    int c = 1;
    while(1)
    {
        scanf("%d %d", &a, &b);
        if(a == 0 && b == 0) break;
        
        m1.clear();
        m2.clear();
        
        int to = sqrt(a) + 1;

        for(int i = 2; i <= to; i++){
            while(a % i == 0){
                a /= i;
                to = sqrt(a) + 1;
                m1[i]++;
            }
        }
        if(a != 1)
            m1[a]++;
        
        
        to = sqrt(b) + 1;
        
        for(int i = 2; i <= to; i++){
            while(b % i == 0){
                b /= i;
                to = sqrt(b) + 1;
                m2[i]++;
            }
        }
        if(b != 1)
            m2[b]++;
        
        map<int, int>::iterator it;
        
        int space = 0;
        int total = 0;
        
        for(it = m1.begin(); it != m1.end(); it++){
            total += abs(it->second - m2[it->first]);
            space++;
        }
        
        for(it = m2.begin(); it != m2.end(); it++){
            if(m1.count(it->first) == 0) {
                total += it->second;
                space++;
            }
        }
        
        printf("%d. %d:%d\n", c++, space, total);
        
    }
    
    return 0;
}

