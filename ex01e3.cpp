#include<bits/stdc++.h>
using namespace std;

int a[100005];

int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    int i,j;
    int x,y;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=1;i<=k;i++)
    {
        scanf("%d",&x);
        int st=1,ed=n;
        for(j=1;j<=20;j++)
        {
            int mid=(st+ed)/2;
            if(a[mid]<=x) st=mid+1;
            else ed=mid-1;
        }
        if(ed==0) printf("-1\n");
        else printf("%d\n",a[ed]);
    }
    return 0;
}
