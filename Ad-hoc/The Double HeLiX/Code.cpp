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

int arr1[10001];
int arr2[10001];

int n1, n2, i, j;

vector< pair<int, int> > ints;

int main() 
{
    while(1)
    {
        scanf("%d", &n1);
        if(n1 == 0) break;
        for(int x = 0; x < n1; x++)
            scanf("%d", &arr1[x]);
        scanf("%d", &n2);
        for(int x = 0; x < n2; x++)
            scanf("%d", &arr2[x]);
        
        i = j = 0;
        
        ints.clear();
        ints.push_back(make_pair(0, 0));
        
        while(i < n1 && j < n2)
        {
            if(arr1[i] == arr2[j])
            {
                ints.push_back(make_pair(i, j));
                i++;
                j++;
            }
            else if(arr1[i] > arr2[j])
            {
                j++;
            }
            else
            {
                i++;
            }
        }
        ints.push_back(make_pair(n1, n2));
        int tot = 0;
        
        for(int x = 0; x < ints.size() - 1; x++)
        {
            int tot1 = 0, tot2 = 0;
            for(int a = ints[x].first; a < ints[x+1].first; a++)
                tot1 += arr1[a];
            for(int a = ints[x].second; a < ints[x+1].second; a++)
                tot2 += arr2[a];
            tot += max(tot1, tot2);
        }
        
        printf("%d\n", tot);
        
        
        
    }
    return 0;
}


