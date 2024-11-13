#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 1e5+10;
int n,m,ct,head[maxn],pre[maxn],lowlink[maxn],sccno[maxn],dfs_clock,scc_cnt,in[maxn],out[maxn];
struct Edge {
    int to, nxt;
}a[maxn << 1];
stack<int> stk;
void add(int x, int y) {
    a[++ct] = {y, head[x]};
    head[x] = ct;
}
void dfs(int u) {
    pre[u] = lowlink[u] = ++dfs_clock;
    stk.push(u);
    for(int i=head[u];i;i=a[i].nxt) {
        int v = a[i].to;
        if(!pre[v]) {
            dfs(v);
            lowlink[u] = min(lowlink[u], lowlink[v]);
        }else if(!sccno[v]) {
            lowlink[u] = min(lowlink[u], pre[v]);
        }
    }
    if(lowlink[u] == pre[u]) {
        scc_cnt++;
        in[scc_cnt] = out[scc_cnt] = 0;
        while(true) {
            int x = stk.top(); stk.pop();
            sccno[x] = scc_cnt;
            if(x == u) break;
        }
    }
}
void solve() {
    cin >> n >> m;
    ct = dfs_clock = scc_cnt = 0;
    memset(head, 0, sizeof(head[0]) * (n + 5));
    memset(pre, 0, sizeof(pre[0]) * (n + 5));
    memset(lowlink, 0, sizeof(lowlink[0]) * (n + 5));
    memset(sccno, 0, sizeof(sccno[0]) * (n + 5));
    while(!stk.empty()) stk.pop();
    for(int i=1;i<=m;i++) {
        int x, y; cin >> x >> y;
        add(x, y);
    }
    for(int i=1;i<=n;i++) {
        if(!pre[i])
            dfs(i);
    }
    if(scc_cnt == 1) {
        cout << 0 << endl;
        return;
    }
    for(int u=1;u<=n;u++) {
        for(int i=head[u];i;i=a[i].nxt) {
            int v = a[i].to;
            if(sccno[u] != sccno[v]) {
                out[sccno[u]]++;
                in[sccno[v]]++;
            }
        }
    }
    int win = 0, wout = 0;
    for(int i=1;i<=scc_cnt;i++) {
        if(!in[i]) win++;
        if(!out[i]) wout++;
    }
    cout << max(win, wout) << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}