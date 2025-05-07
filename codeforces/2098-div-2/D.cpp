#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 1e6+10;
constexpr ll mod = 1e9+7;
template<class T, class... Args>
auto Vec(size_t n, Args... args) {
    if constexpr(sizeof...(args) == 1) {
        return vector<T>(n, args...);
    } else {
        return vector(n, Vec<T>(args...));
    }
}
struct DSU {
    int fa[maxn];
    int sz[maxn], vn[maxn];
    bool loop[maxn];
    void init(int x) {
        rep(i,0,x) {
            fa[i] = i;
            vn[i] = 0;
            sz[i] = 1;
            loop[i] = false;
        }
    }
    int find(int x) {
        if(fa[x] == x) return x;
        return fa[x] = find(fa[x]);
    }
    void merge(int x, int y) {
        // cout << "merge " << x << ' ' << y << endl;
        x = find(x);
        y = find(y);
        if(x == y) return;
        fa[x] = y;
        sz[y] += sz[x];
        vn[y] += vn[x];
        loop[y] |= loop[x];
    }
} dsu;
void solve() {
    int n,m,k; cin >> n >> m >> k;
    k++;
    dsu.init(n * m + 5);
    vector<int> x(k+5), y(k+5);
    rep(i,1,k) cin >> x[i] >> y[i];
    rep(i,2,k) {
        if(abs(x[i] - x[i-1]) + abs(y[i] - y[i-1]) != 2) {
            cout << 0 << endl;
            return;
        }
        if(x[i] == x[i-1]) {
            int pt = (x[i] - 1) * m + (y[i] + y[i-1]) / 2 - 1;
            pt = dsu.find(pt);
            dsu.vn[pt]++;
            dsu.loop[pt] = true;
        } else if(y[i] == y[i-1]) {
            int pt = ((x[i] + x[i-1]) / 2 - 1) * m + y[i] - 1;
            pt = dsu.find(pt);
            dsu.vn[pt]++;
            dsu.loop[pt] = true;
        } else {
            int pt1 = (x[i] - 1) * m + y[i-1] - 1;
            int pt2 = (x[i-1] - 1) * m + y[i] - 1;
            dsu.merge(pt1, pt2);
            dsu.vn[dsu.find(pt1)]++;
        }
    }
    auto vis = Vec<bool>(n*m+5, false);
    ll ans = 1;
    rep(i,1,n) rep(j,1,m) {
        int b = dsu.find(m * (i - 1) + j - 1);
        if(vis[b]) continue;
        vis[b] = true;
        if(dsu.vn[b] == 0 && dsu.loop[b] == 0) continue;
        if(dsu.vn[b] > dsu.sz[b]) ans = 0;
        else if(dsu.vn[b] == dsu.sz[b]) {
            if(dsu.loop[b]) ans *= 1;
            else ans *= 2;
        } else {
            ans *= dsu.sz[b];
        }
        ans %= mod;
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
