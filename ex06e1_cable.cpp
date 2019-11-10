#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define ft first
#define sd second

int a[1005][1005];
bool chk[1005];

int main()
{
    int n;
    scanf("%d",&n);
    int i,j;
    priority_queue<pair<int,int> >pq; ///-w u
    for(i=1;i<=n-1;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
            a[j][i]=a[i][j];
        }
    }
    pq.push(mp(0,1));
    int cnt=0;
    int ans=0;
    while(!pq.empty())
    {
        int w=-pq.top().ft;
        int u=pq.top().sd;
        pq.pop();

        //printf("--%d %d %d %d\n\n",w,u,chk[u],cnt);
        if(chk[u]) continue;
        chk[u]=1;
        cnt++;
        ans+=w;
        if(cnt==n) break;

        for(i=1;i<=n;i++)
        {
            //printf("%d %d\n",i,chk[i]);
            if(chk[i]) continue;
            pq.push(mp(-a[u][i],i));
        }
    }
    printf("%d",ans);
    return 0;
}
