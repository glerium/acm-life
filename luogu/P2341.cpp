#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
constexpr int maxn=1e5+10;
int n,m,head[maxn],cnt,dfn[maxn],low[maxn],sccid[maxn],dfcnt,sz[maxn],scccnt;
bitset<maxn> instk;
vector<pair<int,int>> e;
stack<int> stk;
set<int> g[maxn];
struct Edge {
    int to,nxt;
} a[maxn];
void add(int x,int y) {
    a[++cnt]={y,head[x]}; 
    head[x]=cnt; 
    e.push_back({x,y});
}
void dfs(int x) {
    dfn[x]=low[x]=++dfcnt;
    stk.push(x);
    instk[x]=true;
    for(int i=head[x];i;i=a[i].nxt) {
        if(!dfn[a[i].to]) {
            dfs(a[i].to);
            low[x]=min(low[x],low[a[i].to]);
        }else{
            if(instk[a[i].to])
                low[x]=min(low[x],dfn[a[i].to]);
        }
    }
    if(low[x]==dfn[x]) {
        scccnt++;
        while(stk.top()!=x) {
            int now=stk.top(); stk.pop();
            sccid[now]=scccnt;
            sz[scccnt]++;
            instk[now]=false;
        }
        int now=stk.top(); stk.pop();
        sccid[now]=scccnt;
        sz[scccnt]++;
        instk[now]=false;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin>>n>>m;
    rep(i,1,m) {int x,y; cin>>x>>y; add(x,y);}
    rep(i,1,n) {
        if(!dfn[i])
            dfs(i);
    }
    rep(i,0,m-1) {
        if(sccid[e[i].first]!=sccid[e[i].second]) {
            g[sccid[e[i].first]].insert(sccid[e[i].second]);
        }
    }
    int okcnt=0,mx=0;
    rep(i,1,scccnt) {
        if(g[i].size()==0) {
            okcnt++;
            if(okcnt>=2) {
                cout<<0<<endl;
                return 0;
            }
            mx=max(mx,sz[i]);
        }
    }
    cout<<mx<<endl;
    return 0;
}