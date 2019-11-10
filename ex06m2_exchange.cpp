#include<bits/stdc++.h>
using namespace std;

double a[505][505];
int main()
{
    int n,q;
    int i,j,k;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                scanf("%lf",&a[i][j]);
            }
        }
        for(k=1;k<=n;k++)
        {
            for(i=1;i<=n;i++)
            {
                for(j=1;j<=n;j++)
                {
                    if(a[i][k]*a[k][j]>a[i][j])
                    {
                        a[i][j]=a[i][k]*a[k][j];
                        //printf("%d %d %d\n",i,j,k);
                    }
                }
            }
        }
        bool chk=0;
        for(i=1;i<=n;i++) if(a[i][i]>1) chk=1;
        if(chk) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
