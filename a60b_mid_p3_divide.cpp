#include<bits/stdc++.h>
using namespace std;
#define mod 1997

int dp[505][505];

int main()
{
    int n,k;
    int i,j;
    scanf("%d %d",&n,&k);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=i;j++)
        {
            if(j==1 || i==j) dp[i][j]=1;
            else dp[i][j]=(j*dp[i-1][j]+dp[i-1][j-1])%mod;
        }
    }
    printf("%d",dp[n][k]);
    return 0;
}
