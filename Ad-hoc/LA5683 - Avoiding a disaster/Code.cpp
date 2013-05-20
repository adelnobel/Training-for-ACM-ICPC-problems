#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <ctime>

using namespace std;

char s[505];

int arr[3];

int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    
    int t, x, y, total = 12 * 60;
    
    scanf("%d", &t);
    
    while(t--){
        for(int i = 0; i < 3; i++){
            scanf(" %d:%d ", &x, &y);
            arr[i] = ((x-1) * 60) + y;
        }
        int tot = 0, ans = 0;
        bool valid = false;
        for(int i = 0; i < 3; i++){
            int j = (i+1)%3, k = (i+2)%3;
            if( ((arr[j] - arr[i]) + total) % total == ((arr[k] - arr[j]) + total) % total){
                //arr[j] += 60;
                int q = ((arr[j]+60)/60), w = ((arr[j]+60) % 60);
                sprintf(s, "The correct time is %d:%02d\n", q , w);
                if(ans != 0 && ans != arr[j]){
                    valid = false;
                }else{
                    valid = true;
                    ans = arr[j];
                }
            }
        }
        if(valid){
            printf("%s", s);
        }else{
            printf("Look at the sun\n");
        }
    }
    
    
   
    return 0;
}