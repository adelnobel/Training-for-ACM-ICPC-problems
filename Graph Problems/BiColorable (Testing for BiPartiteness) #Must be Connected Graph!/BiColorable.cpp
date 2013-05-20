
//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=945

#include <stdio.h>
#include <cctype>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <functional>
#include <stack>
#include <iostream>
#include <queue>

using namespace std;


int n, e, a, b;

struct node
{
    int x;
    int color;
};


bool isBiPartite(vector< vector<int> > conns, int randomVertex)
{
    map<int, int> marked;
    bool flag = true;
    queue<node> q;
    node start;
    start.x = randomVertex;
    start.color = 0;
    q.push(start);
    
    while(q.size() != 0 && flag)
    {
        node cur = q.front();
        q.pop();
        int curColor = cur.color;
        int curNode = cur.x;
        for(int x = 0; x < n;x++)
        {
            if(conns[curNode][x]) //Found Neighbor
            {
               if(marked.count(x) > 0 )//Visited Before; check for prev color!
               {
                   if(marked[x] == curColor) //INVALID! SAME COLOR!
                   {
                       flag = false; //Not BiPartite nor BICOLORABLE
                   }
               }
               else
               {
                   marked[x] = (curColor + 1 ) % 2; //MARK Neighbor with the other color
                   node newNode; 
                   newNode.x = x;
                   newNode.color = (curColor + 1 ) % 2; //Make a new node for the neighbour with other color
                   q.push(newNode);
               }
            }
        }
    }
    
    
    return flag;
}


int main()
{
    while(1)
    {
        scanf("%d", &n);
        if(n == 0)
            break;
        
        
        vector< vector<int> > conns;
        
        for(int x = 0; x < n; x++)
        {
            vector<int> q(n, 0);
            conns.push_back(q);
        }
        
        //vector<int> colors(n, 0);
        scanf("%d", &e);
        
        for(int x = 0; x < e; x++)
        {
            scanf("%d %d", &a, &b);
            conns[a][b] = true;
            conns[b][a] = true;
            
        }
        
        
        if(isBiPartite(conns, a))
            printf("BICOLORABLE.\n");
        else
            printf("NOT BICOLORABLE.\n");
    }
    
    return 0;
}