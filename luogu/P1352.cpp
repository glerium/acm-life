#include <bits/stdc++.h>
using namespace std;
constexpr int maxn=1e5+10;
int n,w[maxn],head[maxn],cnt,f[maxn][2],in[maxn];
struct Edge{
    int to,nxt;
}a[maxn];
void add(int x,int y) {
    a[++cnt]={y,head[x]};
    head[x]=cnt;
}
void dfs(int x) {
    for(int i=head[x];i;i=a[i].nxt) {
        const int u=a[i].to;
        dfs(u);
        f[x][0]+=max(f[u][0],f[u][1]);
        f[x][1]+=f[u][0];
    }
    f[x][1]+=w[x];
}
int main() {
    cin>>n;
    for(int i=1;i<=n;i++) cin>>w[i];
    for(int i=1;i<=n-1;i++) {
        int x,y; cin>>x>>y;
        add(y,x);
        in[x]++;
    }
    int root;
    for(int i=1;i<=n;i++) if(!in[i]) {root=i; break;}
    dfs(root);
    cout<<max(f[root][0],f[root][1])<<endl;
    return 0;
}