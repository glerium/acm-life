#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
constexpr ll inf = 0x3f3f3f3f;
template<class T, class... Args>
auto Vec(size_t n, Args... args) {
    if constexpr(sizeof...(args) == 1)
        return vector<T>(n, args...);
    else
        return vector(n, Vec<T>(args...));
}
struct UFS {
    vector<int> fa;
    void init(int x) {
        fa.resize(x+5);
        rep(i,1,x) fa[i] = i;
    }
    int find(int x) {
        if(fa[x] == x) return x;
        return find(fa[x]);
    }
    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        fa[x] = y;
    }
};
void solve() {
    int n,m,k,w; cin >> n >> m >> k >> w;
    UFS ufs;
    ufs.init(k+1);
    vector<string> mp(k+5);
    rep(i,1,k) {
        mp[i] = ' ';
        rep(j,1,n) {
            string s; cin >> s;
            mp[i] += s;
        }
    }
    vector<tuple<int,int,int>> g;
    rep(i,1,k) g.emplace_back(n*m, k+1, i);
    rep(i,1,k) rep(j,i+1,k) {
        if(i == j) continue;
        int diff = 0;
        rep(k,1,n*m) diff += mp[i][k] != mp[j][k];
        g.emplace_back(diff * w, i, j);
    }
    sort(g.begin(), g.end());
    int ans = 0;
    vector<vector<int>> tr(k+5);
    for(auto [d,u,v] : g) {
        if(ufs.find(u) != ufs.find(v)) {
            ufs.merge(u, v);
            ans += d;
            tr[u].push_back(v);
            tr[v].push_back(u);
        }
    };
    cout << ans << endl;

    auto dfs = [&](auto&& dfs, int u, int fa) -> void {
        if(fa == k+1) cout << u << ' ' << 0 << endl;
        else if(fa != -1) cout << u << ' ' << fa << endl;
        for(auto v : tr[u]) {
            if(v == fa) continue;
            dfs(dfs, v, u);
        }
    };
    dfs(dfs, k+1, -1);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}