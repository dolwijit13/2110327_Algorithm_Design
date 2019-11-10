#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define ft first
#define sd second

int d[105][105];

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    char s[105][105];
    int i,j;
    for(i=1;i<=n;i++)
    {
        scanf("%s",s[i]+1);
    }
    queue<pair<int,int> >q; ///(r,c)
    q.push(mp(1,1));
    while(!q.empty())
    {
        int x,y;
        x=q.front().ft;
        y=q.front().sd;
        q.pop();
        if(x<1 || x>n) continue;
        if(y<1 || y>m) continue;
        if(x==n && y==m)
        {
            printf("%d",d[x][y]);
            break;
        }
        if(d[x-1][y]==0 && s[x-1][y]=='.')
        {
            d[x-1][y]=d[x][y]+1;
            q.push(mp(x-1,y));
        }
        if(d[x+1][y]==0 && s[x+1][y]=='.')
        {
            d[x+1][y]=d[x][y]+1;
            q.push(mp(x+1,y));
        }
        if(d[x][y-1]==0 && s[x][y-1]=='.')
        {
            d[x][y-1]=d[x][y]+1;
            q.push(mp(x,y-1));
        }
        if(d[x][y+1]==0 && s[x][y+1]=='.')
        {
            d[x][y+1]=d[x][y]+1;
            q.push(mp(x,y+1));
        }
    }
    if(d[n][m]==0) printf("-1");
    return 0;
}
