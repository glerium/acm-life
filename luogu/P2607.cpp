#include <bits/stdc++.h>
using namespace std;
constexpr int maxn=1e6+10;
int n,head[maxn],cnt,w[maxn],xx,yy,ee;
long long f[maxn][2];
bitset<maxn> vis;
struct Edge{
    int to,nxt;
}a[maxn<<1];
void add(int x,int y) {
    a[cnt]={y,head[x]};
    head[x]=cnt++;
}
bool dfs(int x,int fa) {
    vis[x]=true;
    for(int i=head[x];~i;i=a[i].nxt) {
        const int u=a[i].to;
        if(fa==u) continue;
        if(vis[u]) {
            xx=x;
            yy=u;
            ee=i;
            return true;
        }
        if(dfs(u,x)) return true;
    }
    return false;
}
long long dfs2(int x,int from) {
    vis[x]=true;
    f[x][0]=0, f[x][1]=w[x];
    for(int i=head[x];~i;i=a[i].nxt) {
        const int u=a[i].to;
        if(from==(i^1)) continue;
        if(i==ee||i==(ee^1)) continue;
        dfs2(u,i);
        f[x][0]+=max(f[u][0],f[u][1]);
        f[x][1]+=f[u][0];
    }
    return f[x][0];
}
long long get_answer(int x) {
    xx=-1,yy=-1;
    dfs(x,-1);
    long long ans1=dfs2(xx,-1);
    long long ans2=dfs2(yy,-1);
    return max(ans1,ans2);
}
int main() {
    ios::sync_with_stdio(false);
    memset(head,-1,sizeof(head));
    cin>>n;
    for(int i=1;i<=n;i++) {
        int x; cin>>w[i]>>x;
        add(i,x); add(x,i);
    }
    long long ans=0;
    for(int i=1;i<=n;i++) {
        if(!vis[i]) {
            ans+=get_answer(i);
        }
    }
    cout<<ans<<endl;
    return 0;
}