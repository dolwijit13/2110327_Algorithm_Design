#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define ft first
#define sd second

bool a[1005][1005];
bool chk[1005][1005];
int main()
{
    int n,hx,hy;
    scanf("%d %d %d",&n,&hx,&hy);
    int i,j;
    for(i=1;i<=n;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        a[x][y]=1;
    }
    priority_queue<pair<int,pair<int,int> > >pq; ///-w,x,y;
    pq.push(mp(0,mp(hx,hy)));
    while(!pq.empty())
    {
        int w=-pq.top().ft;
        int x=pq.top().sd.ft;
        int y=pq.top().sd.sd;
        pq.pop();
        if(chk[x][y]) continue;
        chk[x][y]=1;
        if(x==1 || x==1000 || y==1 || y==1000)
        {
            printf("%d",w);
            break;
        }
        for(i=-1;i<=1;i++)
        {
            for(j=-1;j<=1;j++)
            {
                if(abs(i+j)!=1) continue;
                if(a[x+i][y+j]) pq.push(mp(-w-1,mp(x+i,y+j)));
                else pq.push(mp(-w,mp(x+i,y+j)));
            }
        }
    }
    return 0;
}
