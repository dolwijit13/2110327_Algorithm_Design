#include<bits/stdc++.h>
using namespace std;
#define mp make_pair
#define ft first
#define sd second

long long d[47][35][35]; ///d[i][j] = floor 2^(i),from,to
long long a[35][7]; ///a[room][1..5]
long long b[35][35]; ///adj matrix
long long ans[35][35];
int main()
{
    int n,m,p;
    scanf("%d %d %d",&n,&m,&p);
    int i,j,k;
    long long x=(2<<30)-1;
    long long inf = x*x;
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {
            b[i][j]=inf;
            ans[i][j]=0;
            d[0][i][j]=inf;
        }
        b[i][i]=0;
        for(j=0;j<5;j++)
        {
            scanf("%lld",&a[i][j]);
        }
        int bf=(i-1+m)%m;
        int nt=(i+1)%m;
        b[i][bf]=a[i][0];
        b[i][nt]=a[i][1];
        d[0][i][bf]=a[i][2];
        d[0][i][i]=a[i][3];
        d[0][i][nt]=a[i][4];
    }
    ///find apsp only floor 0
    for(k=0;k<m;k++)
    {
        for(i=0;i<m;i++)
        {
            for(j=0;j<m;j++)
            {
                b[i][j]=min(b[i][j],b[i][k]+b[k][j]);
                d[0][i][j]=min(d[0][i][j],d[0][i][k]+b[k][j]);
            }
        }
    }
    /*
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("%lld ",d[0][i][j]);
        }
        printf("\n");
    }
    */
    int cnt=1;
    x=2;
    while(x<n)
    {
        for(i=0;i<m;i++)
        {
            for(j=0;j<m;j++)
            {
                d[cnt][i][j]=inf;
                for(k=0;k<m;k++)
                {
                    d[cnt][i][j]=min(d[cnt][i][j],d[cnt-1][i][k]+d[cnt-1][k][j]);
                }
            }
        }
        for(k=0;k<m;k++)
        {
            for(i=0;i<m;i++)
            {
                for(j=0;j<m;j++)
                {
                        d[cnt][i][j]=min(d[cnt][i][j],d[cnt][i][k]+b[k][j]);
                        //printf("%lld %lld\n",d[cnt][i][j],d[cnt][i][k]+b[k][j]);
                }
            }
        }
        /*
        printf("--%d %lld\n",cnt,x);
        for(i=0;i<m;i++)
        {
            for(j=0;j<m;j++)
            {
                printf("%lld ",d[cnt][i][j]);
            }
            printf("\n");
        }
        */
        cnt++;
        x*=2;
    }
    long long tmp[35][35];
    n--;
    while(cnt>0)
    {
        cnt--;
        x/=2;
        if(n<x) continue;
        //printf("--%d %lld %d\n",cnt,x,n);
        n-=x;
        for(i=0;i<m;i++)
        {
            for(j=0;j<m;j++)
            {
                tmp[i][j]=inf;
            }
        }
        for(k=0;k<m;k++)
        {
            for(i=0;i<m;i++)
            {
                for(j=0;j<m;j++)
                {
                    tmp[i][j]=min(tmp[i][j],b[i][k]+d[cnt][k][j]);
                    //printf("%d %d %d\n",cnt,k,j);
                }
            }
        }
        for(i=0;i<m;i++)
        {
            for(j=0;j<m;j++)
            {
                b[i][j]=tmp[i][j];
            }
        }
    }
    /*
    while(x<=n*2)
    {
        //printf("---%d %lld\n",i,x);
        for(j=0;j<k;j++)
            pq.push(mp(-d[i-1][j],mp(i-1,j)));
        while(!pq.empty()) ///only floor 0
        {
            long long w=-pq.top().ft;
            int f=pq.top().sd.ft;
            int r=pq.top().sd.sd;
            pq.pop();
            if(d[f][r]<w) continue;
            printf("%lld %d %d\n",w,f,r);
            d[f][r]=w;
            int bf=(r-1+k)%k;
            int nt=(r+1)%k;
            if(f==i-1)
            {
                if(d[f+1][bf]>w)
                    pq.push(mp(-w-a[r][2],mp(f+1,bf)));
                if(d[f+1][r]>w)
                    pq.push(mp(-w-a[r][3],mp(f+1,r)));
                if(d[f+1][nt]>w)
                    pq.push(mp(-w-a[r][4],mp(f+1,nt)));
            }
            else if(f==i)
            {
                if(d[f][bf]>w)
                    pq.push(mp(-w-a[r][0],mp(f,bf)));
                if(d[f][nt]>w)
                    pq.push(mp(-w-a[r][1],mp(f,nt)));
            }
        }
        for(int i2=0;i2<k;i2++)
        {
            for(j=0;j<5;j++) a[i2][j]=
        }
        i++;
        x*=2;
    }
    */
    /*
    for(int i=0;i<1;i++)
    {
    for(int j=0;j<m;j++)
    {
        for(k=0;k<m;k++) printf("%lld ",d[i][j][k]);
        printf("\n");
    }
    printf("\n");
    }
    */
    /*
    printf("---ans---\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<m;j++)
        {
            printf("%lld ",b[i][j]);
        }
        printf("\n");
    }
    */
    //long long superans=inf;
    //for(i=0;i<m;i++) superans=min(superans,b[0][i]+ans[i][p]);

    printf("%lld",b[0][p]);
    return 0;
}
