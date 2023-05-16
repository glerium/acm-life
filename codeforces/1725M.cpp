// CF1725M：分层图、Dijkstra
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+10;
const ll inf=1e15;
int n,m,head[maxn],ct;
ll dis[maxn];
struct Edge{
    int to;
    ll dis;
    int nxt;
}a[maxn<<2];
struct Node {
    int id;
    ll dis;
    bool operator<(const Node& rhs)const{
        return dis>rhs.dis;
    }
};
priority_queue<Node> q;

void add(int x,int y,ll z){
    // cout<<"Added "<<x<<"->"<<y<<endl;
    a[++ct]=(Edge){y,z,head[x]};
    head[x]=ct;
}
int main() {
    cin>>n>>m;
    {
        int x,y,z;
        for(int i=1;i<=m;i++) {
            cin>>x>>y>>z;
            add(x,y,z);
            add(y+n,x+n,z);     // 构造反向图
        }
        for(int i=1;i<=n;i++) add(i,i+n,0);
    }

    // dijkstra: 1 -> n+k
    for(int i=1;i<=n+n;i++) dis[i]=inf;
    dis[1]=0;
    q.push((Node){1,0});
    while(!q.empty()) {
        Node ima = q.top();
        q.pop();
        // cout<<ima.id<<endl;
        if(ima.dis != dis[ima.id]) continue;    // 非最新点，说明之前已被处理过
        for(int i=head[ima.id];i;i=a[i].nxt) {
            if(dis[a[i].to]>dis[ima.id]+a[i].dis) {
                dis[a[i].to]=dis[ima.id]+a[i].dis;
                q.push((Node){a[i].to,dis[a[i].to]});
            }
        }
    }
    for(int i=n+2;i<=n+n;i++) cout<<(dis[i]!=inf?dis[i]:-1)<<' ';
    return 0;
}