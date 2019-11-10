#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define ft first
#define sd second

int a[2005];
int p[2005];

int _find(int x)
{
    if(p[x]==x) return p[x];
    return p[x]=_find(p[x]);
}

bool _union(int x,int y)
{
    x=_find(x);
    y=_find(y);
    if(x==y) return false;
    p[x]=y;
    return true;
}

int main()
{
    int n;
    scanf("%d",&n);
    int i,j;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        p[i]=i;
    }
    priority_queue<pair<int,pair<int,int> > >pq;///w,u,v;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(i==j) continue;
            pq.push(mp(a[i]^a[j],mp(i,j)));
        }
    }
    unsigned long long ans=0;
    int cnt=0;
    while(!pq.empty())
    {
        int w=pq.top().ft;
        int x=pq.top().sd.ft;
        int y=pq.top().sd.sd;
        pq.pop();
        if(_union(x,y))
        {
            ans+=w;
            cnt++;
        }
        if(cnt==n-1) break;
    }
    printf("%lld",ans);
}
