#include<bits/stdc++.h>
using namespace std;

int a[100005];

int main()
{
    int n,d;
    scanf("%d %d",&n,&d);
    int i,j;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    int st=1,ed=1000000000;
    int k;
    int ans;
    for(j=1;j<=32;j++)
    {
        k=(st+ed)/2;
        ans=1;
        int last=0;
        for(i=1;i<=n;i++)
        {
            if(a[i]-last>k)
            {
                ans++;
                last=a[i-1];
                if(a[i]-a[i-1]>k) ans=999999999;
            }
        }
        //printf("%d %d\n",k,ans);
        if(ans>d) st=k+1;
        else ed=k;
    }
    printf("%d %d",k,ans);
}
