#include<bits/stdc++.h>
using namespace std;
#define ft first
#define sd second
#define mp make_pair

class item
{
public:
    int mx;
    set<int>person;
    vector<pair<int,int > >value; ///price person
};

vector<int>won[1000005];
item k[1000005];
int main()
{
    int n,m,a;
    scanf("%d %d %d",&n,&m,&a);
    int i,j;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&k[i].mx);
    }
    ///(bid) user item value
    ///(withdraw) user item -1
    stack<pair<int,pair<int,int> > >st;
    while(a--)
    {
        char s[5];
        scanf("%s",s);
        if(s[0]=='B')
        {
            ///user item value
            int u,x,v;
            scanf("%d %d %d",&u,&x,&v);
            st.push(mp(u,mp(x,v)));
        }
        else
        {
            int u,x;
            scanf("%d %d",&u,&x);
            st.push(mp(u,mp(x,-1)));
        }
    }
    while(!st.empty())
    {
        bool t;
        int u,x,v;
        u=st.top().ft; //user
        x=st.top().sd.ft; //item
        v=st.top().sd.sd; //value
        if(v==-1) t=1; ///withdraw
        else t=0; ///bid
        st.pop();

        if(k[x].person.find(u) != k[x].person.end())
        {
            continue;
        }
        k[x].person.insert(u);
        if(t==0) k[x].value.push_back(mp(-v,-u));
    }

    for(i=1;i<=n;i++)
    {
        sort(k[i].value.begin(),k[i].value.end());
        int sz=k[i].value.size();
        for(j=0;j<k[i].mx && j<sz;j++)
        {
            won[-k[i].value[j].sd].push_back(i);
        }
    }
    for(i=1;i<=m;i++)
    {
        int sz=won[i].size();
        if(sz==0)
        {
            printf("NONE\n");
            continue;
        }
        for(j=0;j<sz;j++)
        {
            printf("%d ",won[i][j]);
        }
        printf("\n");
    }
    return 0;
}
