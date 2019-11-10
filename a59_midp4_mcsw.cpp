#include<bits/stdc++.h>
using namespace std;
#define len j-i+1

int a[200005];
int qs[200005];

int main()
{
    int n,w;
    int i,j;
    scanf("%d %d",&n,&w);
    int ans=-INT_MAX;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        qs[i] = qs[i-1]+a[i];
        ans=max(ans,a[i]);
    }

    i=1;
    ///len = j-i+1
    deque<int>dq;
    for(j=1;j<=n;j++)
    {
        if(!dq.empty() && j-dq.front() >w) dq.pop_front();
        while(!dq.empty() && qs[dq.back()]>qs[j]) dq.pop_back();
        dq.push_back(j);
        printf("%d %d %d\n",j,qs[j],qs[dq.front()]);
        if(j!=dq.front())   ans=max(ans,qs[j]-qs[dq.front()]);
    }
    printf("%d",ans);
    return 0;
}
