#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int N=500005;
struct Edge{ll v,w,next;}G[N];
ll head[N],cnt,n,m,s,k,c[N],d;
ll dis[N];
inline void addedge(ll u,ll v,ll w)
{
    cnt++;
    G[cnt].w=w;
    G[cnt].v=v;
    G[cnt].next=head[u];
    head[u]=cnt;
}
struct node
{
    ll d,u;
    bool operator<(const node &t)const{return d>t.d;};
};
inline void dijkstra()
{
    for(int i=1;i<=n;i++)dis[i]=0x3f3f3f3f;
    dis[s]=0;
    priority_queue<node> q;
    q.push((node){0,s});
    while(!q.empty())
    {
        node tmp=q.top();q.pop();
        ll u=tmp.u,d=tmp.d;
        if(d!=dis[u])continue;
        for(int i=head[u];i;i=G[i].next)
        {
            ll v=G[i].v,w=G[i].w;
            if(dis[u]+w<dis[v])
            {
                dis[v]=dis[u]+w;
                q.push((node){dis[v],v});
            }
        }
    }
}
void solve()
{
    cin>>n>>m>>d;
    cnt=0;
    for(int i=1;i<=m;i++)
    {
        G[i]={0,0,0};
    }
    for(int i=1;i<=n;i++)
    {
        head[i]=0;dis[i]=0;
    }
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        addedge(x,y,1);
    }
    dijkstra();
    cin>>k;
    for(int i=1;i<=k;i++)cin>>c[i];
    for(int i=1;i<=n;i++)cout<<dis[i]<<" \n"[i==n];
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin>>t;while(t--)solve();
}