#include<bits/stdc++.h>
using namespace std;

int a[100005];
int ans=0;
int n;

int f(int L,int R,int mid)
{
    while(L<R)
    {
        if(a[L]>=mid)
        {
            while(L<R && R>0)
            {
                if(a[R]<mid) break;
                R--;
            }
            if(L<R && R>0)
            {
                ans++;
                int tmp=a[L];
                a[L]=a[R];
                a[R]=tmp;
            }
        }
        L++;
    }
    /*
    for(int i=1;i<=n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    printf("%d %d\n",L,R);
    */
    return L;
}


int main()
{
    start:;
    ans=0;
    scanf("%d",&n);
    int i,j;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    int mid=f(1,n,2);
    f(1,mid,1);
    f(mid+1,n,3);
    printf("%d\n",ans);
    //goto start;
    return 0;
}
