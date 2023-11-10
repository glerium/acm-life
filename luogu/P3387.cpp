#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;

constexpr int maxn=1e5+10;
int n,m,head[maxn],head2[maxn],w[maxn],w2[maxn],cnt,cnt2,low[maxn],dfn[maxn],dfscnt,sccid[maxn],scccnt,ans,f[maxn];
vector<pair<int,int>> e;
set<pair<int,int>> newe;
stack<int> stk;
bitset<maxn> v,v2,instk;
struct Edge{
    int to,nxt;
}a[maxn],b[maxn];

void dfs(int x) {           // tarjan求强联通分量
    v[x]=true;
    dfn[x]=++dfscnt;
    low[x]=dfn[x];          // 初始化low=dfn
    instk[x]=true;
    stk.push(x);

    /* 下面这部分处理递归的逻辑注意不要写错 */
    for(int i=head[x];i;i=a[i].nxt) {
        if(v[a[i].to]) {
            if(instk[a[i].to])
                low[x]=min(low[x],dfn[a[i].to]);
            continue;
        }
        dfs(a[i].to);
        low[x]=min(low[x],low[a[i].to]);
    }
    /* 上面这部分处理递归的逻辑注意不要写错 */

    if(dfn[x]==low[x]) {
        int id=++scccnt;
        while(dfn[stk.top()]!=low[stk.top()]) {
            int now=stk.top();
            stk.pop();
            sccid[now]=id;
            instk[now]=false;
            w2[scccnt]+=w[now];
        }
        int now=stk.top();
        stk.pop();
        sccid[now]=id;
        instk[now]=false;
        w2[scccnt]+=w[now];     // 构建新图的点权
    }
}

int dfs2(int x) {           // 第二次dfs，在新图上搜索答案
    if(v2[x]) return f[x];
    int ret=w2[x],mx=0;
    for(int i=head2[x];i;i=b[i].nxt) {
        mx=max(mx,dfs2(b[i].to));
    }
    return f[x]=ret+mx;
}

void add(int x,int y) {     // 在原图上连边
    e.push_back({x,y});
    a[++cnt]={y,head[x]};
    head[x]=cnt;
}

void add2(int x,int y) {    // 在新图（DAG）上连边
    newe.insert({x,y});
    b[++cnt2]={y,head2[x]};
    head2[x]=cnt2;
}

int main() {
    ios::sync_with_stdio(false);
    cin>>n>>m;
    rep(i,1,n) cin>>w[i];   // 点权
    rep(i,1,m) {
        int u,v; cin>>u>>v;
        add(u,v);
    }
    rep(i,1,n) {            // tarjan求scc
        if(!v[i]) 
            dfs(i);
    }
    for(auto r:e) {         // 在缩点的基础上连新图
        int x=r.first, y=r.second;
        if(sccid[x]!=sccid[y]&&!newe.count({x,y}))      // 第二个条件是为了保证不出现重边
            add2(sccid[x],sccid[y]);
    }
    // cout<<":"<<scccnt<<endl;
    rep(i,1,scccnt) {       // dfs计算答案
        ans=max(ans,dfs2(i));
    }
    cout<<ans<<endl;
    return 0;
}