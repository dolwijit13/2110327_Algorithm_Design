#include<bits/stdc++.h>
using namespace std;

int l,r;

bool g(int x,int idx)
{
    if(!(l<=idx && idx<=r)) return 0;
    return x%2;
}

int f(int x,int p,int q)
{
    if(q<l || r<p) return 0;
    if(x<=1) return x;
    int m=(q-p)/2;
    return f(x/2,p,p+m-1)+g(x,p+m)+f(x/2,p+m+1,q);
}

int main()
{
    int n;
    scanf("%d %d %d",&n,&l,&r);
    int last=(1<<(int(log2(n))+1))-1;
    printf("%d",f(n,1,last));
}
