#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
constexpr int maxn=107;
int n,m,head[maxn],cnt,r[maxn];
map<pii,int> mp;
ll k,ans=1e18;
struct Edge{
    int x,y;
    ll w;
}a[maxn];
int fa[maxn],sz[maxn];
int find(int x) {
    if(x==fa[x]) return x;
    return fa[x]=find(fa[x]);
}
void merge(int x,int y) {
    x=find(x),y=find(y);
    if(x==y) return;
    fa[y]=x;
    sz[x]+=sz[y];
}
void dfs(int x) {
    if(r[x]==x) return;
    if(x==n) {
        for(int i=1;i<=n;i++) fa[i]=i,sz[i]=1;
        for(int i=1;i<=n-1;i++) {
            merge(i,r[i]);
        }
        if(sz[find(1)]==n) {
            ll ima=0;
            for(int j=1;j<=n-1;j++) {
                ima+=mp[{j,r[j]}];
                ima=ima%k;
            }
            ans=min(ans,ima);
        }
    }else{
        for(int i=1;i<=n;i++) {
            if(!mp.count(make_pair(x,i))) continue;
            r[x]=i;
            dfs(x+1);
        }
    }
}
signed main() {
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++) cin>>a[i].x>>a[i].y>>a[i].w, mp[{a[i].x,a[i].y}]=a[i].w, mp[{a[i].y,a[i].x}]=a[i].w;
    dfs(1);
    cout<<ans<<endl;
    return 0;
}