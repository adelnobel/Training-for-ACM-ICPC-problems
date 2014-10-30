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

#define N 30

int P, C, a;
char ch[3];

int main()
{
    int cou = 0;
    
    while(1)
    {
        scanf("%d %d", &P, &C);
        if(P == 0 && C == 0)
            break;
        cou++;
        int mini = min(P, C);
        list<int> listi;
        for(int x = 1; x <= mini; x++)
            listi.push_back(x);
        
        printf("Case %d:\n", cou);
        
        for(int x = 0; x < C; x++)
        {
            scanf("%s", ch);
            if(ch[0] == 'E')
            {
                scanf("%d", &a);
                listi.remove(a);
                listi.push_front(a);
            }
            else
            {
                printf("%d\n", listi.front());
                listi.push_back(listi.front());
                listi.pop_front();
            }
        }

    }
    return 0;
}