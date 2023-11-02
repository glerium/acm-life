#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
constexpr int maxn=2e5+10;
int n,m,cnt,head[maxn],dfn[maxn],low[maxn],dfcnt;
bitset<maxn> v,flag;
struct Edge{
    int to,nxt;
}a[maxn];
void add(int x,int y) {
    a[++cnt]={y,head[x]};
    head[x]=cnt;
}
void dfs(int x,int fa) {
    dfn[x]=low[x]=++dfcnt;
    v[x]=true;
    int child=0;
    for(int i=head[x];i;i=a[i].nxt) {
        if(!v[a[i].to]) {
            child++;
            dfs(a[i].to, x);
            low[x]=min(low[x],low[a[i].to]);
            if(fa!=-1&&low[a[i].to]>=dfn[x]) 
                flag[x]=true;
        }else if(a[i].to!=fa) {
            low[x]=min(low[x],dfn[a[i].to]);
        }
    }
    if(fa==-1&&child>=2) flag[x]=true;
}
int main() {
    ios::sync_with_stdio(false);
    cin>>n>>m;
    rep(i,1,m) {
        int x,y;
        cin>>x>>y;
        add(x,y);
        add(y,x);
    }
    rep(i,1,n) {
        if(!v[i])
            dfs(i,-1);
    }
    int cnt=0;
    rep(i,1,n) cnt+=flag[i];
    cout<<cnt<<endl;
    rep(i,1,n) if(flag[i]) cout<<i<<' ';
    cout<<endl;
    return 0;
}