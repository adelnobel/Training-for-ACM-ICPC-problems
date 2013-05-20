#include <iostream>
#include <cstdio>

using namespace std;

int arr[30];
int dp[30];

int main()
{
    int n;
    scanf("%d", &n);
    int maxi = 0;
    for(int x = 1; x <= n; x++)
    {
        scanf("%d", &arr[x]);
        int nmax = 0;
        for(int w = x - 1; w >= 0; w--)
        {
            if(arr[w] < arr[x])
            {
                nmax = max(nmax, dp[w]);
            }
        }
        dp[x] = nmax + 1;
        maxi = max(maxi, dp[x]);
    }

    printf("%d", maxi);
}

