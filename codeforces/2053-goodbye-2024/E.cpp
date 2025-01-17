#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int n; cin >> n;
    vector<vector<int>> a(n+5);
    int du[n+5] = {};
    rep(i,1,n-1) {
        int x, y; cin >> x >> y;
        du[x]++;
        du[y]++;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    bool leaf[n+5] = {};
    rep(i,1,n) if(du[i] == 1) leaf[i] = true;
    int leafs = 0;
    rep(i,1,n) leafs += leaf[i];
    ll ans = 1ll * leafs * (n - leafs);

    int ost[n+5] = {};
    rep(i,1,n) {
        for(auto j : a[i])
            if(leaf[j])
                ost[i] = true;
    }
    int sz[n+5] = {};
    int sz_leaf[n+5] = {};
    int leafcc = 0;
    rep(i,1,n) leafcc += leaf[i] | ost[i];
    function<int(int, int)> dfs = [&](int x, int from) -> int {
        int ret = 0;
        sz[x] = 1;
        sz_leaf[x] = leaf[x] | ost[x];
        for(auto i : a[x]) {
            if(i == from) continue;
            int now = dfs(i, x);
            ret += now;
            sz[x] += sz[i];
            sz_leaf[x] += sz_leaf[i];
            if(!leaf[x] && !leaf[i] && ost[i])
                ans += now; 
        }
        if(ost[from] && !leaf[x])
            ans += n - sz[x] - (leafcc - sz_leaf[x]);
        return ret + (!ost[x] && !leaf[x]);
    };
    dfs(1, 0);
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
