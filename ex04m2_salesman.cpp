#include<bits/stdc++.h>
using namespace std;

int a[1005];
int t[1005];
int r[1005];
int l[1005];

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int i,j;
    for(i=0;i<m;i++) scanf("%d",&a[i]);
    for(i=0;i<m;i++) scanf("%d",&t[i]);
    for(i=1;i<=n;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        l[0]=0;
        r[0]=0;
        for(i=1;i<m;i++)
        {
            l[m-i]=l[m+i]+t[i];
            r[i]=r[i-1]+t[i-1];
        }
        l[0]=l[1]+t[0];
        r[0]=r[m-1]+t[m-1];
    }
    return 0;
}
