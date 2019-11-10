#include<bits/stdc++.h>
using namespace std;

int k;
int a,b,c,d;
int a0,b0,c0,d0;

void f(int x)
{
    if(x==1)
    {
        return;
    }
    f(x/2);
    int a2=(a*a+b*c)%k;
    int b2=(a*b+b*d)%k;
    int c2=(a*c+c*d)%k;
    int d2=(b*c+d*d)%k;
    if(x%2==1)
    {
        a=(a2*a0+b2*c0)%k;
        b=(a2*b0+b2*d0)%k;
        c=(c2*a0+d2*c0)%k;
        d=(c2*b0+d2*d0)%k;
    }
    else
    {
        a=a2%k;
        b=b2%k;
        c=c2%k;
        d=d2%k;
    }
}

int main()
{
    int n;
    int i,j;
    int x,y;
    scanf("%d %d",&n,&k);
    scanf("%d %d %d %d",&a,&b,&c,&d);
    a%=k;
    b%=k;
    c%=k;
    d%=k;
    a0=a;
    b0=b;
    c0=c;
    d0=d;
    f(n);
    printf("%d %d %d %d",a,b,c,d);
    return 0;
}
