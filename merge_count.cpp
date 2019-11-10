#include<bits/stdc++.h>
using namespace std;

int k;

void f(int l,int r)
{
    //printf("%d %d %d\n",l,r,k);
    if(l==r)
    {
        printf("%d ",l);
        return;
    }
    int mid=(l+r)/2;
    if(k==1)
    {
        f(l,mid);
        f(mid+1,r);
    }
    else
    {
        k-=2;
        f(mid+1,r);
        f(l,mid);
    }
}

int main()
{
    int n;
    scanf("%d %d",&n,&k);
    if(k%2==0 || k>2*n-1)
    {
        printf("-1");
    }
    else
    {
        f(1,n);
    }
}
