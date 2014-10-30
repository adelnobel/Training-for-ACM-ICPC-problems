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
 
using namespace std;

double distanc, capacity, milesPerGallon, initialCost;

int totalStations;

double stations[60];

double costs[60];


double solveMin(double currentFuel, int currentStation)
{
    if(currentStation == totalStations) return 0.0;
    double distanceToNextStation = stations[currentStation+1] - stations[currentStation];
    double costToFillTankInThisStation = round(costs[currentStation] * (capacity - currentFuel));
    if( ((currentFuel * milesPerGallon) < distanceToNextStation) ){ //if current fuel cant make us reach the next station
        return 200 + costToFillTankInThisStation + solveMin(capacity - (distanceToNextStation / milesPerGallon), currentStation + 1);
    }
    
    if( (currentFuel > (capacity / 2.0)) ) {//If the tank has more than half and the car can reach the next station, then we can't fill the tank here!
        return solveMin(currentFuel - (distanceToNextStation / milesPerGallon), currentStation + 1 );
    }
    

    return min(200 + costToFillTankInThisStation + solveMin(capacity - (distanceToNextStation / milesPerGallon), currentStation + 1), 
               solveMin(currentFuel - (distanceToNextStation / milesPerGallon), currentStation + 1 )); //Minimum cost of filling in this station or not filling
}

int main()
{
    //freopen("in.in", "r", stdin);
    
    int cc = 1;
    
    while(1)
    {
        scanf("%lf", &distanc);
        if(distanc < 0 ) break;
        
        scanf("%lf %lf %lf %d", &capacity, &milesPerGallon, &initialCost, &totalStations);
        
        for(int i = 0; i < totalStations; i++)
            scanf("%lf %lf", &stations[i], &costs[i]);
        
        stations[totalStations] = distanc;
        
        printf("Data Set #%d\n", cc++);
        double solve = round(solveMin(capacity - (stations[0] / milesPerGallon ) , 0));
        
        printf("minimum cost = $%.2lf\n", ( (solve / 100.0) + initialCost ));
    }
    
    return 0;
}