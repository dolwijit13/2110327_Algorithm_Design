#include<bits/stdc++.h>
using namespace std;

int v[505],w[505];
int a[505][505];
int main()
{
    int n,m;
    int i,j;
    queue<int>q;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++) scanf("%d",&v[i]);
    for(i=1;i<=n;i++) scanf("%d",&w[i]);

    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    j=m;
    for(i=n;i>=1;i--)
    {
        if(j-w[i]<0) continue;
        if(a[i-1][j-w[i]]==a[i][j]-v[i])
        {
            q.push(i);
            j-=w[i];
        }
        if(j<=0) break;
    }
    printf("%d\n",q.size());
    while(!q.empty())
    {
        printf("%d ",q.front());
        q.pop();
    }
    return 0;
}
