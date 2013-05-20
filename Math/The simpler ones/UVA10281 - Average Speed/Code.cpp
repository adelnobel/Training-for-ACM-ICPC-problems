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

char line[300];
char s[50];
int speed;

int getTime(){
    
    
    int hours = (s[0] - '0');
    hours = (hours * 10) + (s[1] - '0');
    
    int minutes = (s[3] - '0');
    minutes = (minutes * 10) + (s[4] - '0');
    
    int seconds = (s[6] - '0');
    seconds = (seconds * 10) + (s[7] - '0');
    
    int ret = (hours * 60 * 60) + (minutes * 60) + seconds;
    
    return ret;
    
}

int main()
{
    //freopen("in.in", "r", stdin);
    
    double lastDistance = 0.0;
    double lastSpeed = 0.0;
    
    int lastTime = 0;
    
    while(1){
        
        line[0] = '\0';
        gets(line);
        if(line[0] == '\0') break;
        
        sscanf(line, "%s", s);
        
        if(sscanf(line+8, "%d", &speed) == 1){
            int curTime = getTime();
            int elpased = curTime - lastTime;
            lastDistance  = (elpased * lastSpeed + lastDistance);
            lastSpeed = speed / 60. / 60.;
            
            lastTime = curTime;
            
        }
        else{
            int curTime = getTime();
            int elpased = curTime - lastTime;
            
            lastDistance  = (elpased * lastSpeed + lastDistance);
            
            printf("%s %.2lf km\n",s, lastDistance);
            
            lastTime = curTime;
            
            
        }
        
    }

    return 0;
}