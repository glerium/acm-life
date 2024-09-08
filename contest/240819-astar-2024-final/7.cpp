#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int maxn = 3e5+10;
int n,m,k,cnt,head[maxn],dep[maxn],fa[maxn][20],cf[maxn],son[maxn];
struct Edge{
    int to,nxt;
    ll w;
}a[maxn<<1];
void add(int x,int y,ll w) {
    a[++cnt] = {y,head[x],w};
    head[x] = cnt;
}
ll ps[maxn];
struct BIT{
    int a[maxn];
    int lowbit(int x) {
        return x&-x;
    }
    void add(int x,int v){
        printf("Add %d %d\n",x,v);
        while(x <= maxn) {
            a[x] += v;
            x += lowbit(x);
        }
    }
    void add_range(int x,int y){
        add(x, 1);
        add(y+1, -1);
    }
    int query(int x) {
        int ans = 0;
        while(x) {
            ans += a[x];
            x -= lowbit(x);
        }
        return ans;
    }
} tree;
namespace HeavyLightDecompostition{
    int first[maxn*2], nxt[maxn*2], des[maxn*2];
    int tot, cnt=1;
    int tpos[maxn],dep[maxn],top[maxn],fa[maxn],wson[maxn],sz[maxn];
    void dfs1(int x,int from) {
        dep[x] = dep[from] + 1;
        fa[x] = from; sz[x] = 1;
        for(int i=head[x];i;i=a[i].nxt) {
            int to = a[i].to;
            if(to == from) continue;
            son[x] = to;
            ps[a[i].to] = a[i].w;
            dfs1(to, x);
            if(sz[to] > sz[wson[x]]) {
                wson[x] = to;
            }
            sz[x] += sz[to];
        }
    }
    void dfs2(int x,int from,int chain) {
        top[x] = chain; tpos[x] = ++cnt;
        if(wson[x]) {
            dfs2(wson[x], x, chain);
        }
        for(int i = head[x];i;i=a[i].nxt) {
            if(a[i].to == from || a[i].to == wson[x])
                continue;
            dfs2(a[i].to, x, a[i].to);
        }
    }
    int getlca(int x,int y){
        while(top[x] != top[y]) {
            if(dep[top[x]] < dep[top[y]])
                swap(x, y);
            x = fa[top[x]];
        }
        if(dep[x] < dep[y]) swap(x,y);
        return y;
    }

    void init() {
        dfs1(1, 0);
        dfs2(1, 0, 1);
    }

    void modify_(int x, int y) {
        while(top[x] != top[y]) {
            if(dep[top[x]] < dep[top[y]]) swap(x,y);
            tree.add_range(tpos[top[x]], tpos[x]);
            x = fa[top[x]];
        }
        if(dep[x] < dep[y]) swap(x,y);
        tree.add_range(tpos[y], tpos[x]);
    }
    
    int query_(int x) {
        return tree.query(tpos[x]);
    }
}
struct State{
    int i;
    ll p;
    ll ct;
    bool operator<(const State& rhs)const{
        ll d1 = p*ct - p/2*ct;
        ll d2 = rhs.p*rhs.ct - rhs.p/2*rhs.ct;
        return d1 < d2;
    }
};
int main() {
    // BIT bitt;
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    cin >> n >> m >> k;
    vector<int> edge;
    for(int i=1;i<=n-1;i++) {
        int x,y; ll w; cin>>x>>y>>w;
        add(x,y,w); add(y,x,w);
    }
    HeavyLightDecompostition::init();
    int from = 1;
    for(int i=1;i<=m;i++) {
        int x; cin >> x;
        HeavyLightDecompostition::modify_(from, x);
        from = x;
    }
    priority_queue<State> q;
    for(int i=2;i<=n-1;i++) {
        q.push({i, ps[i], HeavyLightDecompostition::query_(i)});
    }
    int kcnt = 0;
    while(!q.empty() && kcnt < k) {
        auto ima = q.top(); q.pop();
        
    }
    return 0;
}
