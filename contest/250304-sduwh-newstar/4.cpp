#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int n,m; cin >> n >> m;
    vector<int> c(n+5);
    rep(i,1,n) cin >> c[i];
    vector<vector<int>> a(n+5);
    rep(i,1,m) {
        int x, y; cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    vector<int> nd;
    vector<int> cn(n+5, -1);
    function<void(int)> dfs = [&](int u) {
        // cout << u << endl;
        nd.push_back(u);
        for (auto v : a[u]) {
            if(cn[v] == -1) {
                cn[v] = 1 - cn[u];
                dfs(v);
            } else if (cn[u] == cn[v]) {
                cout << "Impossible" << endl;
                exit(0);
            }
        }
    };
    int ans = 0;
    rep(i,1,n) {
        if(cn[i] == -1) {
            nd.clear();
            cn[i] = 0;
            dfs(i);
            int cur = 0;
            for(auto j : nd) {
                cur += abs(c[j] - cn[j]);
                cn[j] = -1;
            }

            nd.clear();
            cn[i] = 1;
            dfs(i);
            int cur2 = 0;
            for(auto j : nd) {
                cur2 += abs(c[j] - cn[j]);
            }
            ans += min(cur, cur2);
        }
    }
    cout << ans << endl;
}
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}
