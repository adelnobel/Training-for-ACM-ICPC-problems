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
#include <bitset>


using namespace std;


char num[10], s[10];
int len;
int x;

bool isWrapAround()
{
    int mask = (1 << len) - 1;
    int ptr = 0, next;
    do
    {
        mask &= ~(1 << ptr);
        next = (ptr + (num[ptr + (7-len)] - '0'))  % len;
        if( !((1 << next) & mask ) && ( next != 0 || mask != 0)  ) return false;
        ptr = next;
    }while(mask != 0);
    return true;
}


int main()
{
    //freopen("in.in", "r", stdin);
    int n, cc = 1;
    num[7] = '\0';
    while(1)
    {
        scanf("%s", s);
        if(s[0] == '0') break;
        len = strlen(s);
        strcpy(num+(7-len), s);
        

        for(int x = 0; x < 7-len; x++)
            num[x] = '0';
        
        bool found = false;
        
        bool numsInSeq[10];
        memset(numsInSeq, false, sizeof(numsInSeq));
        
        for(; num[0] <= '9' && !found; num[0]++)
        {
            if(num[0] - '0' != 0 && numsInSeq[num[0] - '0'] ){
                for(int l = 1; l < 7; l++) num[l] = '1';
                continue;
            }
            numsInSeq[num[0] - '0'] = true;
            for(; num[1] <= '9' && !found; num[1]++)
            {
                if(num[1] - '0' != 0 && numsInSeq[num[1] - '0'] ){
                    for(int l = 2; l < 7; l++) num[l] = '1';
                    continue;
                }
                numsInSeq[num[1] - '0'] = true;
                for(; num[2] <= '9' && !found; num[2]++)
                {
                    if(num[2] - '0' != 0 && numsInSeq[num[2] - '0'] ){
                        for(int l = 3; l < 7; l++) num[l] = '1';
                        continue;
                    }
                    numsInSeq[num[2] - '0'] = true;
                    for(; num[3] <= '9' && !found; num[3]++)
                    {
                        if(num[3] - '0' != 0 && numsInSeq[num[3] - '0'] ){
                            for(int l = 4; l < 7; l++) num[l] = '1';
                            continue;
                        }
                        numsInSeq[num[3] - '0'] = true;
                        for(; num[4] <= '9' && !found; num[4]++)
                        {
                            if(num[4] - '0' != 0 && numsInSeq[num[4] - '0'] ){
                                for(int l = 5; l < 7; l++) num[l] = '1';
                                continue;
                            }
                            numsInSeq[num[4] - '0'] = true;
                            for(; num[5] <= '9' && !found; num[5]++)
                            {
                                if(num[5] - '0' != 0 && numsInSeq[num[5] - '0'] ) {
                                    for(int l = 6; l < 7; l++) num[l] = '1';
                                    continue;
                                }
                                numsInSeq[num[5] - '0'] = true;
                                for(; num[6] <= '9' && !found; num[6]++)
                                {
                                    if(num[6] - '0' != 0 && numsInSeq[num[6] - '0'] ) continue;
                                    numsInSeq[num[6] - '0'] = true;
                                    if(isWrapAround())
                                    {
                                        found = true;
                                        printf("Case %d: ", cc++);
                                        int ptr = 0;
                                        for(; num[ptr] == '0'; ptr++ );
                                        printf("%s\n", num+ptr);
                                    }
                                    numsInSeq[num[6] - '0'] = false;
                                }
                                numsInSeq[num[5] - '0'] = false;
                                num[6] = '1';
                                len = ( num[6] == '1' && len < 2 ) ? ++len : len;
                            }
                            numsInSeq[num[4] - '0'] = false;
                            num[5] = num[6] = '1';
                            len = ( num[5] == '1' && len < 3 ) ? ++len : len;
                        }
                        numsInSeq[num[3] - '0'] = false;
                        num[4] = num[5] = num[6] = '1';
                        len = ( num[4] == '1' && len < 4 ) ? ++len : len;
                    }
                    numsInSeq[num[2] - '0'] = false;
                    num[3] = num[4] = num[5] = num[6] = '1';
                    len = ( num[3] == '1' && len < 5 ) ? ++len : len;
                }
                numsInSeq[num[1] - '0'] = false;
                num[2] = num[3] = num[4] = num[5] = num[6] = '1';
                len = ( num[2] == '1' && len < 6 ) ? ++len : len;
            }
            numsInSeq[num[0] - '0'] = false;
            num[1] = num[2] = num[3] = num[4] = num[5] = num[6] = '1';
            len = ( num[1] == '1' && len < 7 ) ? ++len : len;
        }
    }
    
   
    return 0;
}