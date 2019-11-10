#include<bits/stdc++.h>
using namespace std;
#define ft first
#define sd second
#define mp make_pair

int l,r;

int mod(int x,int idx)
{
    if(l<=idx && idx<=r) return x%2;
    return 0;
}

//return count(1),range
pair<int,int> f(int x,int st)
{
    //printf("%d %d\n",x,st);
    if(x<=1)
    {
        if(l<=st && st<=r)
        {
            return mp(1,1);
        }
        return mp(0,1);
    }

    if(r < st)
        return mp(0,1);

    pair<int,int> next = f(x/2,st);
    if(st+next.sd*2<l)
        return mp(0,next.sd*2+1);
    pair<int,int> next2 = f(x/2,st+next.sd+1);
    return mp(next.ft+mod(x,st+next.sd)+next2.ft,next.sd*2+1);
}

int main()
{
    int n;
    scanf("%d %d %d",&n,&l,&r);
    printf("%d",f(n,1).ft);
    return 0;
}
