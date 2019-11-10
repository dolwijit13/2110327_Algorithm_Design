#include<bits/stdc++.h>
using namespace std;

int dp[35][35];

int main()
{
    int i,j;
    int n,k;
    scanf("%d %d",&n,&k);
    for(i=1;i<=n;i++)
    {
        for(j=0;j<=k;j++)
        {
            if(i==j||j==0) dp[i][j]=1;
            else dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
        }
    }
    printf("%d",dp[n][k]);
    return 0;
}
