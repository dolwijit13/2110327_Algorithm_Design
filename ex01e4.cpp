#include<bits/stdc++.h>
using namespace std;

int x,k;

int f(int y)
{
    if(y==0) return 1;
    if(y==1) return x%k;
    int tmp = f(y/2);
    tmp= (tmp*tmp)%k;
    if(y%2==1)
        tmp = (tmp*x)%k;
    return tmp%k;
}

int main()
{
    int n;
    scanf("%d %d %d",&x,&n,&k);
    printf("%d",f(n));
    return 0;
}
