#include<bits/stdc++.h>
using namespace std;

class vertex
{
public:

    int u,h,e;
    vertex()
    {
        this->u=0;
        this->h=0;
        this->e=0;
    }
    vertex(int u,int h,int e)
    {
        this->u=u;
        this->h=h;
        this->e=e;
    }
    bool operator==(vertex v)
    {
        return this->u==v.u;
    }
    void print()
    {
        printf("u: %d h: %d e: %d\n",u,h,e);
    }
};

class edge
{
public:

    int u,v;
    int f,c;
    edge(int u,int v,int f,int c)
    {
        this->u=u;
        this->v=v;
        this->f=f;
        this->c=c;
    }

    void print()
    {
        printf("u: %d v:%d f:%d c:%d\n",u,v,f,c);
    }
};

vector<vertex>V;
vector<edge>E;
int n,m,s,t;

bool push(vertex u)
{
    for(int i=0;i<E.size();i++)
    {
        ///u->v
        if(E[i].u==u.u)
        {
            if(E[i].f==E[i].c) continue;
            if(V[E[i].u].h<=V[E[i].v].h) continue;
            int flow=min(E[i].c-E[i].f,V[E[i].u].e);
            E[i].f+=flow;
            V[E[i].u].e-=flow;
            V[E[i].v].e+=flow;
            //E[i].print();
            return 1;
        }
    }
    for(int i=0;i<E.size();i++)
    {
        ///v->u (residual graph)
        if(E[i].v==u.u)
        {
            if(E[i].f==0) continue;
            if(V[E[i].v].h<=V[E[i].u].h) continue;
            int flow=min(E[i].f,V[E[i].v].e);
            E[i].f-=flow;
            V[E[i].u].e+=flow;
            V[E[i].v].e-=flow;
            return 1;
        }
    }
    return 0;
}

void relabel(int x)
{
    int mn=INT_MAX;
    vertex u = V[x];
    for(int i=0;i<E.size();i++)
    {
        if(E[i].u==u.u && E[i].f!=E[i].c)
            mn=min(mn,V[E[i].v].h);
        if(E[i].v==u.u && E[i].f!=0)
            mn=min(mn,V[E[i].u].h);
    }
    V[x].h=mn+1;
}



int main()
{
    int i,j;
    //while(1)
    //{
    if(1)
    {
        scanf("%d %d",&n,&m);
        //s--;
        //t--;
        s=0;
        t=n-1;
        V.clear();
        E.clear();
        for(i=0;i<n;i++)
            V.push_back(vertex(i,0,0));
        for(i=1;i<=m;i++)
        {
            int x,y,w;
            scanf("%d %d %d",&x,&y,&w);
            E.push_back(edge(x,y,0,w));
        }
        ///preflow
        V[s].h=n;
        for(i=0;i<m;i++)
        {
            if(E[i].u==s)
            {
                E[i].f=E[i].c;
                V[E[i].v].e=E[i].f;
            }
        }

        ///push&relabel
        while(1)
        {
            int next=-1;
            for(i=0;i<n;i++)
            {
                if(i==s || i==t) continue;
                if(V[i].e != 0)
                {
                    next=i;
                    break;
                }
            }
            if(next==-1) break;
            //printf("%daaa\n",next);
            if(V[next].e ==0) continue;
            if(!push(V[next]))
            {
                relabel(next);
                //printf("relabel %d\n",V[next].h);
            }
            //else printf("push\n");

        }
        int ans=0;
        for(i=0;i<E.size();i++)
        {
            //E[i].print();
            if(E[i].v==t) ans+=E[i].f;
        }
        //printf("Network %d\n",ncase);
        //printf("The bandwidth is %d.\n",ans);
        printf("%d\n",ans);
    }
    return 0;
}
