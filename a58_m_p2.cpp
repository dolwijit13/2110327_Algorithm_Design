#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define ft first
#define sd second

int dp[1005];

int main()
{
    int n;
    scanf("%d",&n);
    int i,j;
    int x;
    int m=0;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&x);
        if(i==1)
        {
            dp[1]=x;
            m=1;
            continue;
        }
        if(x>dp[m])
        {
            dp[m+1]=x;
            m++;
            continue;
        }
        int st=1,ed=m;
        while(st<ed)
        {
            int mid=(st+ed)/2;
            if(dp[mid]<=x) st=mid+1;
            else ed=mid;
        }
        dp[ed]=x;
    }
    printf("%d",m);

}
