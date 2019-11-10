#include<bits/stdc++.h>
using namespace std;

class point
{
public:
    int x;
    int y;

    point(int x,int y)
    {
        this->x=x;
        this->y=y;
    }

    void print()
    {
        //for debug
        printf("---%d %d---\n",x,y);
    }

    void print(point black)
    {
        int type;
        if(x == black.x)
        {
            if(y == black.y) type= 0;
            else  type= 2;
        }
        else
        {
            if(y == black.y)  type= 1;
            else  type= 3;
        }
        printf("%d %d %d\n",type,x,y);
    }

    int type(point black)
    {
        if(black.x < x)
        {
            if(black.y < y) return 0;
            else return 2;
        }
        else
        {
            if(black.y < y) return 1;
            else return 3;
        }
        return -1;
    }
};


void f(point nw,int k,point black)
{
    if(k==2)
    {
        nw.print(black);
        return;
    }
    point mid = point(nw.x+k/2,nw.y+k/2);
    int type=mid.type(black);

    if(type!=1)
        f(point(mid.x,nw.y),k/2,point(mid.x,mid.y-1));
    else
        f(point(mid.x,nw.y),k/2,black);

    if(type!=0)
        f(nw,k/2,point(mid.x-1,mid.y-1));
    else
        f(nw,k/2,black);

    if(type!=2)
        f(point(nw.x,mid.y),k/2,point(mid.x-1,mid.y));
    else
        f(point(nw.x,mid.y),k/2,black);

    if(type!=3)
        f(mid,k/2,point(mid.x,mid.y));
    else
        f(mid,k/2,black);

    printf("%d %d %d\n",type,mid.x-1,mid.y-1);
}

int main()
{
    int n,m;
    int i,j;
    int x,y;
    scanf("%d %d %d",&n,&x,&y);
    printf("%d\n",((n*n)-1)/3);
    f(point(0,0),n,point(x,y));
    return 0;
}
