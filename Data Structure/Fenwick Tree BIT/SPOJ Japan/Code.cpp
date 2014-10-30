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
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>

using namespace std;


void update(vector< long long > &tree, int ind)
{
    do
    {
        tree[ind] += 1;
        ind += (ind & -ind);
    }while(ind <= (int)tree.size());
}

long long getSumTo(vector< long long > &tree, int ind)
{
    long long sum = 0;
    do
    {
        sum += tree[ind];
        //ind = ind & ~(ind & -ind);
           ind = ind - (ind & -ind); //Both are the same
    }while(ind > 0);
    return sum;
}

typedef struct crossing
{
    int a, b;
    bool operator<(const crossing &c) const
    {
        if(a != c.a) return a > c.a;
        return b > c.b;
    }
}crossing;

int main()
{
    //freopen("in2.in", "r", stdin);
    
    int T, N, M, K, s, d;
    
    scanf("%d", &T);
    

    for(int x = 1; x <= T ; x++)
    {
        scanf("%d %d %d", &N, &M, &K);
        vector< crossing > v(K);
        
        vector< long long > tree(M+1, 0);
        
        for(int a = 0; a < K; a++)
        {
            scanf("%d %d", &s, &d);
            crossing c; c.a = s; c.b = d;
            v[a] = c;
        }
        sort(v.begin(), v.end());
        
        long long tot = 0;
        
        for(int a = 0; a < v.size(); a++)
        {
            tot += getSumTo(tree, v[a].b - 1);
            update(tree, v[a].b);
        }
        
        printf("Test case %d: %lld\n", x, tot);
        
    }

    return 0;
}