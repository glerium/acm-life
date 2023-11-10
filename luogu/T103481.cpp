// 洛谷T103481 割边板子题 n=5e4,m=3e5
#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
constexpr int maxn=6e5+10;
int n,m,head[maxn],cnt,dfn[maxn],low[maxn],dfcnt;
set<pair<int,int>> st;
struct Edge{
    int to,nxt;
}a[maxn];
void add(int x,int y) {
    a[++cnt]={y,head[x]};
    head[x]=cnt;
}
void dfs(int x,int fa){
    dfn[x]=low[x]=++dfcnt;
    for(int i=head[x];i;i=a[i].nxt) {
        if(dfn[a[i].to]) {
            if(a[i].to!=fa)
                low[x]=min(low[x],dfn[a[i].to]);
            continue;
        }
        dfs(a[i].to,x);
        low[x]=min(low[x],low[a[i].to]);
        if(low[a[i].to]>dfn[x])
           st.insert({min(x,a[i].to),max(x,a[i].to)});
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin>>n>>m;
    rep(i,1,m) {
        int x,y; cin>>x>>y;
        add(x,y); add(y,x);
    }
    rep(i,1,n) {
        if(!dfn[i])
            dfs(i,-1);
    }
    cout<<st.size()<<endl;
}