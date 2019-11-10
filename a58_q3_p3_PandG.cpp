#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define ft first
#define sd second

int chk[105][105];
int main()
{
    int k;
    scanf("%d",&k);
    int r,c;
    int n,t,rp,cp;
    int i,j;
    int x,y;
    char s[105][105];
    while(k--)
    {
        scanf("%d %d %d %d %d %d",&r,&c,&n,&t,&rp,&cp);
        queue<pair<pair<pair<int,int>,bool>,pair<int,int> > >q;
        ///weight time_start type(0->pac/1->ghost) x y
        for(i=0;i<n;i++)
        {
            int ti,ri,ci;
            scanf("%d %d %d",&ti,&ri,&ci);
            q.push(mp(mp(mp(0,ti),1),mp(ri,ci)));
        }
        for(i=0;i<r;i++)
        {
            scanf("%s",s[i]);
            for(j=0;j<c;j++) chk[i][j]=0; ///0->.# / 1p / 2g
        }

        q.push(mp(mp(mp(0,0),0),mp(rp,cp)));
        while(!q.empty())
        {
            int w=q.front().ft.ft.ft;
            int ts=q.front().ft.ft.sd;
            bool type=q.front().ft.sd;
            x=q.front().sd.ft;
            y=q.front().sd.sd;
            q.pop();
            if(w<ts)
            {
                q.push(mp(mp(mp(w+1,ts),type),mp(x,y)));
                continue;
            }
            if(!type && chk[x][y]==0) chk[x][y]=1; ///pacman
            else if(type) chk[x][y]=2; ///ghost;
            //printf("%d %d %d %d %d\n",w,ts,type,x,y);

            if(w+1>t) continue;
            for(i=-1;i<=1;i++)
            {
                for(j=-1;j<=1;j++)
                {
                    if(x+i <0 || x+i>=r || y+j<0 || y+j>=c) continue;
                    if(abs(i+j)!=1) continue;
                    if(chk[x+i][y+j]==2) continue;
                    if(chk[x+i][y+j]==1 && !type) continue;

                    if(s[x+i][y+j]=='#') continue;
                    if(!type) chk[x+i][y+j] = 1; ///pacman
                    if(type) chk[x+i][y+j] = 2; ///ghost
                    q.push(mp(mp(mp(w+1,ts),type),mp(x+i,y+j)));
                }
            }
        }
        bool ans=0;
        for(i=0;i<r;i++)
        {
            for(j=0;j<c;j++)
            {
                //printf("%d ",chk[i][j]);
                if(chk[i][j]==1) ans=1;
            }
            //printf("\n");
        }
        if(ans) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
