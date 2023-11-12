#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
constexpr int maxn=4e6+10;
int n,m,head[maxn],cnt,dfn[maxn],low[maxn],dfcnt,bcccnt;
vector<int> st[maxn];
stack<int> stk;
struct Edge{
    int to,nxt;
}a[maxn];
void add(int x,int y) {
    a[++cnt]={y,head[x]};
    head[x]=cnt;
}
void dfs(int x,int fa) {
    dfn[x]=low[x]=++dfcnt;
    int son=0;
    stk.push(x);
    for(int i=head[x];i;i=a[i].nxt) {
        if(a[i].to!=x) son++;
        if(dfn[a[i].to]) {
            if(a[i].to!=fa)
                low[x]=min(low[x],dfn[a[i].to]);
            continue;
        }
        dfs(a[i].to,x);
        low[x]=min(low[x],low[a[i].to]);
        if(low[a[i].to]>=dfn[x]) {
            bcccnt++;
            int last_pop=-1;
            do {
                st[bcccnt].push_back(last_pop=stk.top());
                stk.pop();
            } while(last_pop!=a[i].to);
            st[bcccnt].push_back(x);
        }
    }
    if(son==0&&fa==-1)
        st[++bcccnt].push_back(x);
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
    // rep(i,1,n){
    //     cout<<":"<<dfn[i]<<' '<<low[i]<<endl;
    // }
    cout<<bcccnt<<endl;
    rep(i,1,bcccnt) {
        cout<<st[i].size()<<' ';
        for(auto j:st[i]) cout<<j<<' ';
        cout<<endl;
    }
    return 0;
}