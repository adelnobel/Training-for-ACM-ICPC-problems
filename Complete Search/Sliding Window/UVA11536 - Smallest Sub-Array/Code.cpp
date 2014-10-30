#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <cmath>
#include <iostream>
#include <bitset>
#include <map>
#include <ctime>
#include <set>
#include <complex>

using namespace std;

typedef long long ll;

#define N 1000005

int arr[N], occ[1005];

//bool dbg[1005];

ll mask1, mask2, checkee1, checkee2;

bool allOccurred(){
    return mask1 == checkee1 && mask2 == checkee2;
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
#endif
    
    int n, m, k, t, c = 1;
    
    scanf("%d", &t);
    //t = 1;
    while(t--){
        
        memset(occ, 0, sizeof occ);
        scanf("%d %d %d", &n, &m, &k);
        arr[0] = 1, arr[1] = 2, arr[2] = 3;
        //dbg[1] = dbg[2] = dbg[3] = true;
        for(int i = 4; i <= n; i++){
            arr[i-1] = (arr[i-2] + arr[i-3] + arr[i-4]) % m + 1;
            //dbg[arr[i-1]] = true;
        }
        /**
        for(int i = 1; i <= m; i++){
            if(!dbg[i]){
                cout << i << endl;
            }
        }

        return 0;**/
        
        checkee1 = 0, checkee2 = 0;

        if(k <= 50){
            checkee1 = (1LL << k) - 1;
        }else{
            checkee1 = (1LL << 50) - 1;
            checkee2 = (1LL << (k-50) ) - 1;
        }
        
        mask1 = 0, mask2 = 0; 
        int best = 1 << 28;
        
        int i = 0, j = 0;
        
        for(; i < n;){
            for(; j < n;){
                occ[arr[j]]++;
                if(arr[j] <= k){
                    if(arr[j] > 50){
                        //cout << j << " ww" << endl;
                        mask2 |= 1LL << ( (arr[j]-1) - 50);
                    }else{
                        mask1 |= 1LL << ((arr[j]-1));
                    }
                }
                j++;
                if(allOccurred()) {
                    //cout << i << " " << j << endl;
                    best = min(best, j - i);
                    break;
                }
            }
            if(j == n) break;
            bool stillValid = true;
            while(i < j && stillValid){
                if(arr[i] <= k){
                    occ[arr[i]]--;
                    if(occ[arr[i]] == 0){
                        stillValid = false;
                        if(arr[i] > 50){
                            mask2 &= ~(1LL << ( (arr[i]-1) - 50));
                        }else{
                            mask1 &= ~(1LL << ((arr[i]-1)));
                        }
                    }
                }
                i++;
                if(stillValid){
                    //cout << i << " " << j << endl;
                    best = min(best, j - i);
                }
            }
            //cout << "End! " << i << " " << j << endl;
        }
        
        printf("Case %d: ", c++);
        
        if(best > n){
            printf("sequence nai\n");
        }else{
            printf("%d\n", best);
        }
        
    }
    
    
    return 0;
}