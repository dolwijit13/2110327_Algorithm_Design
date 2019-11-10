#include<bits/stdc++.h>
using namespace std;

int dp[1005][1005];
int a[1005][1005];

int qs(int x1,int y1,int x2,int y2)
{
    x1--;
    y1--;
    return dp[x2][y2]-dp[x2][y1]-dp[x1][y2]+dp[x1][y1];
}

int main()
{
    int n,m;
    int i,j,k;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
    {
        char s[1005];
        scanf("%s",s);
        for(j=1;j<=m;j++)
        {
            a[i][j]=s[j-1]-'0';
            dp[i][j]=a[i][j]+dp[i][j-1]+dp[i-1][j]-dp[i-1][j-1];
            //printf("%d ",dp[i][j]);
        }
        //printf("\n");
    }
    int x,y;
    int mx=0;
    for(k=1;k<=min(n,m);k++)
    {
        for(i=1;i<=n;i++)
        {
            x=i+k-1;
            if(x>n) break;
            for(j=1;j<=m;j++)
            {
                y=j+k-1;
                if(y>m) break;
                //printf("%d %d %d %d %d\n",i,j,x,y,qs(i,j,x,y));
                if(qs(i,j,x,y)==k*k) mx=max(mx,k);
            }
        }
    }
    printf("%d",mx);
    return 0;
}
