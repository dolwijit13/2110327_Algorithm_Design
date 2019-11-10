#include<bits/stdc++.h>
using namespace std;
#define ft first
#define sd second
#define mp make_pair

pair<int,int>a[100005];

int main()
{
    int n;
    int i,j;
    int x,y;
    int mxy=-1;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d",&a[i].ft,&a[i].sd);
    }
    sort(a,a+n+1);
    int ans=0;
    for(i=n;i>=1;i--)
    {
        if(a[i].sd>mxy)
        {
            mxy=a[i].sd;
            ans++;
        }
    }
    printf("%d",ans);
}
