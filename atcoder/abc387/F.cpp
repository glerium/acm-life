#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 5e3+10;
constexpr ll mod = 998244353;
int n,m,a[maxn],dfn[maxn],low[maxn],dft,scc,cnt[maxn],flag[maxn];
int in[maxn], out[maxn];
ll f[maxn][maxn];   // at point i, with a value of j
ll pre[maxn][maxn]; // suffix sum of f[][]
// dp: u->v    f[v][j] = sum i in j..m f[u][i] (i.e. suf[u][i])
vector<int> g[maxn], g2[maxn];
bitset<maxn> instk;
stack<int> stk;
void dfs(int x) {
    dfn[x] = low[x] = ++dft;
    instk[x] = 1;
    stk.push(x);
    for(auto v : g[x]) {
        if(!dfn[v]) {
            dfs(v);
            low[x] = min(low[x], low[v]);
        }else if(instk[v]) {
            low[x] = min(low[x], dfn[v]);
        }
    }
    if(dfn[x] == low[x]) {
        scc++;
        while(1) {
            int tmp = stk.top();
            flag[tmp] = scc;
            instk[tmp] = 0;
            cnt[scc]++;
            stk.pop();
            if(tmp == x) break;
        }
    }
}
ll dfs2(int x) {
    for(auto i : g2[x])
        dfs2(i);
    ll ans = 0;
    rep(j,1,m) {    // f[x][j]
        ll tmp = 1;
        for(auto i : g2[x]) {
            tmp *= pre[i][j];
            tmp %= mod;
        }
        f[x][j] = tmp;
        // f[x][j] %= mod;
        ans += f[x][j];
        ans %= mod;
    }
    rep(j,1,m) {
        pre[x][j] = pre[x][j-1] + f[x][j];
        pre[x][j] %= mod;
    }
    return ans;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    rep(i,1,n) cin >> a[i];
    rep(i,1,n)
        g[a[i]].push_back(i);
    // tarjan 
    rep(i,1,n) {
        if(!dfn[i])
            dfs(i);
    }
    // create new graph which is DAG
    set<pair<int,int>> st;
    rep(i,1,n) {
        for(auto v : g[i]) {
            if(flag[i] == flag[v])
                continue;
            if(st.count({flag[i], flag[v]}))
                continue;
            g2[flag[i]].push_back(flag[v]);
            st.insert({flag[i], flag[v]});
            in[flag[v]]++;
            out[flag[i]]++;
        }
    }
    rep(i,1,scc) rep(j,1,m) f[i][j] = 1;
    // dp
    ll ans = 1;
    rep(i,1,scc) {
        if(in[i] == 0) {
            ans *= dfs2(i);
            ans %= mod;
        }
    }
    cout << ans << endl;
    return 0;
}
