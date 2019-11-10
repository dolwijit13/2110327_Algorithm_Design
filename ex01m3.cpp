#include<bits/stdc++.h>
using namespace std;

int a[1005];

int main()
{
    int n,q;
    scanf("%d %d",&n,&q);
    int i,j;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    while(q--)
    {
        long long x;
        scanf("%lld",&x);
        long long st=0,ed=1000000000000000LL;
        for(i=1;i<=60;i++)
        {
            long long mid=(st+ed)/2;
            long long dkr=n;
            for(j=1;j<=n;j++)
            {
                dkr+=(mid/a[j]);
            }
            if(dkr>=x)
            {
                ed=mid;
            }
            else
            {
                st=mid+1;
            }
        }
        printf("%lld\n",ed);
    }
    return 0;
}
