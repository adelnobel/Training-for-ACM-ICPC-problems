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

using namespace std;


typedef struct{
    int startP, endP;
    double length;
}edge;

typedef struct{
    double x, y;
    edge edges[101];
    int lastEdge;
}point;




int n, l;

bool marked[101];
point points[101];

struct mycmp{
    bool operator()(const edge e1, const edge e2)
    {
        return e1.length > e2.length;
    }
};

void push_edges(priority_queue<edge, vector<edge>, mycmp> &q, int node)
{
    for(int x = 0; x < points[node].lastEdge; x++)
    {
        q.push(points[node].edges[x]);
    }
}

int main()
{
    scanf("%d", &n);
    
    for(int x = 0; x < n; x++)
    {
        if(x > 0)
            printf("\n");
        memset(marked, false, sizeof(marked));
        
        priority_queue<edge, vector<edge>, mycmp> q;
        
        scanf("%d", &l);
        
        for(int a = 0; a < l; a++)
        {
            point p;
            scanf("%lf %lf", &p.x, &p.y);
            points[a] = p;
        }
        
        for(int a = 0; a < l; a++)
        {
            points[a].lastEdge = 0;
            for(int b = 0; b < l; b++)
            {
                if(a == b)
                    continue;
                
                double edgeLength = sqrt( pow(points[a].x - points[b].x, 2) + pow(points[a].y - points[b].y, 2) );
                
                edge e;
                e.startP = a;
                e.endP = b;
                e.length = edgeLength;
                points[a].edges[points[a].lastEdge] = e;
                points[a].lastEdge++;
                
                /**
                edge e1;
                e1.startP = b;
                e1.endP = a;
                e1.length = edgeLength;
                points[b].edges[points[b].lastEdge] = e1;
                points[b].lastEdge++;**/
            }
        }
         
        double tot = 0.0;
        
        push_edges(q, 0); //There will always be the node 0 according to the constraints.
        
        while( !q.empty() )
        {
            edge e = q.top();
            q.pop();
            
            if(marked[e.endP])
                continue;
            
            tot += e.length;
            marked[e.startP] = true;
            marked[e.endP] = true;
            
            push_edges(q, e.endP); //We push all edges of the new node we discovered
            
        }
        
        printf("%.2lf\n", tot);
        
    }
    
    return 0;
}
