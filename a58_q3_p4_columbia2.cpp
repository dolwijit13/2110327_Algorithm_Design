#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define ft first
#define sd second

vector<vector<int> >a;
vector<vector<int> >dp[3]; ///dp[x] -> used tear x times

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int i,j;
    for(i=0;i<n;i++)
    {
        vector<int>tmp;
        a.push_back(tmp);
        dp[0].push_back(tmp);
        dp[1].push_back(tmp);
        dp[2].push_back(tmp);
        for(j=0;j<m;j++)
        {
            int x;
            scanf("%d",&x);
            a[i].push_back(x);
            dp[0][i].push_back(999999999);
            dp[1][i].push_back(999999999);
            dp[2][i].push_back(999999999);
        }
    }
    priority_queue<pair<pair<int,int>,pair<int,int> > >pq;///-w,times,x,y
    pq.push(mp(mp(0,0),mp(0,0)));
    while(!pq.empty())
    {
        int w=-pq.top().ft.ft;
        int time=pq.top().ft.sd;
        int x=pq.top().sd.ft;
        int y=pq.top().sd.sd;
        pq.pop();
        if(dp[time][x][y]<=w) continue;
        dp[time][x][y]=w;
        for(i=-1;i<=1;i++)
        {
            for(j=-1;j<=1;j++)
            {
                if(x+i<0 || x+i>=n) continue;
                if(y+j<0 || y+j>=m) continue;
                if(abs(i+j)!=1) continue;
                if(dp[time][x+i][y+j]<=w+a[x+i][y+j]) continue;
                pq.push(mp(mp(-w-a[x+i][y+j],time),mp(x+i,y+j)));
            }
        }
        if(time==2) continue;
        for(i=-2;i<=2;i++)
        {
            for(j=-2;j<=2;j++)
            {
                if(x+i<0 || x+i>=n) continue;
                if(y+j<0 || y+j>=m) continue;
                if(abs(i)==2 && j!=0) continue;
                if(abs(j)==2 && i!=0) continue;
                if(dp[time+1][x+i][y+j]<=w) continue;
                pq.push(mp(mp(-w,time+1),mp(x+i,y+j)));
            }
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++) printf("%d ",dp[2][i][j]);
        printf("\n");
    }
}
