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


int main()
{
    //freopen("in.in", "r", stdin);
    
    int a, b;
    
    while(scanf("%d %d", &a, &b) != EOF){
        printf("%d\n", a ^ b);
    }
    

    return 0;
}