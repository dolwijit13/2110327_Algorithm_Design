#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int i;
    int x;
    scanf("%d",&n);
    int cur=-999999999;
    int ans=-999999999;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&x);
        if(cur<0) cur = x;
        else cur+=x;
        ans=max(ans,cur);
    }
    printf("%d",ans);
}
