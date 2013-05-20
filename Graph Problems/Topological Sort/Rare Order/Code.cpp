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
#include <queue>
#include <stack>
#include <list>
#include <cstring>
#include <ctime>

using namespace std;


typedef struct node
{
    int n;
    int label;
    bool operator<(const node &n) const
    {
        return label < n.label;
    }
}node;

#define N 30

int n, e, a , b;

int connections[N][N];
bool marked[N];
bool present[N];

node orderings[N];
int cur_label;

char str1[30];
char str2[30];

void make_connection()
{
    int x = 0, y = 0;
    
    while(str1[x] != '\0' && str2[y] != '\0')
    {
        present[str1[x] - 'A'] = present[str2[y] - 'A'] = true;
        if(str1[x] != str2[y])
        {
            connections[str1[x] - 'A'][str2[y] - 'A'] = 1;
            break;
        }
        x++;
        y++;
    }
    
}

void dfs(int v)
{
    marked[v] = true;
    for(int x = 0; x < N; x++)
    {
        if(connections[v][x] && !marked[x])
            dfs(x);
    }
    orderings[v].label = cur_label;
    orderings[v].n = v;
    cur_label--;
}

int main()
{
    cur_label = N;
    scanf("%s", str1);
    while(1)
    {
        scanf("%s", str2);
        if(str2[0] == '#')
            break;
        
        make_connection();
        strcpy(str1, str2);
    }
    
    memset(marked, false, sizeof marked);
    for(int x = 0; x < N; x++)
    {
        if(!marked[x])
           dfs(x);
    }
    
    sort(orderings, orderings+N);
    
    for(int x = 0; x < N; x++)
    {
        if(present[orderings[x].n])
            printf("%c", orderings[x].n + 'A');
    }
    printf("\n");
    
    return 0;
}
  