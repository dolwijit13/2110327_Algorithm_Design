#include<bits/stdc++.h>
using namespace std;

int a[100005];
int inv;

void ms(int st,int ed)
{
    if(st==ed) return;

    int mid=(st+ed)/2;
    ms(st,mid);
    ms(mid+1,ed);

    queue<int>tmp;
    int p=st,q=mid+1;
    while(p<=mid && q<=ed)
    {
        if(a[p]<=a[q])
        {
            tmp.push(a[p]);
            p++;
        }
        else
        {
            inv+=(mid-p+1);
            tmp.push(a[q]);
            q++;
        }
    }

    while(p<=mid)
    {
        tmp.push(a[p]);
        p++;
    }
    while(q<=ed)
    {
        tmp.push(a[q]);
        q++;
    }
    for(int i=st;i<=ed;i++)
    {
        a[i]=tmp.front();
        tmp.pop();
    }
    return;
}

int main()
{
    int n;
    int i,j;
    int x,y;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    ms(1,n);
    printf("%d\n",inv);
    return 0;
}
