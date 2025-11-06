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
struct Edge {
    int x,y;
    int w;
    bool operator<(const Edge& rhs) const {
        return w < rhs.w;
    }
};
struct UFS {
    vector<int> fa;
    void init(int x) {
        fa.resize(x + 5);
        rep(i,1,x) fa[i] = i;
    }
    int find(int x) {
        if(fa[x] == x) return x;
        return fa[x] = find(fa[x]);
    }
    void merge(int x, int y) {
        x = find(x);
        y = find(y);
        fa[x] = y;
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
};
int lowbit(int x) {
    return x & -x;
}
void solve() {
    int n,m,k; cin >> n >> m >> k;
    vector<Edge> edg(m+5);
    rep(i,1,m)
        cin >> edg[i].x >> edg[i].y >> edg[i].w;
    sort(edg.begin() + 1, edg.begin() + 1 + m);
    vector<int> c(k+5);
    auto a = Vec<Edge>(k+5, n+5, Edge{0,0,0});
    rep(i,1,k) {
        cin >> c[i];
        rep(j,1,n) {
            cin >> a[i][j].w;
            a[i][j].x = i + n;
            a[i][j].y = j;
        }
        sort(a[i].begin() + 1, a[i].begin() + 1 + n);
    }
    UFS ufs;
    ufs.init(n);
    vector<vector<Edge>> mtree(1 << k);
    vector<ll> ans(1 << k);
    mtree[0].push_back(Edge{});
    rep(i,1,m) {
        if(ufs.same(edg[i].x, edg[i].y))
            continue;
        ufs.merge(edg[i].x, edg[i].y);
        ans[0] += edg[i].w;
        mtree[0].push_back(edg[i]);
    }
    rep(i, 1, (1 << k) - 1) {
        rep(j,0,k-1) {
            if(i & (1 << j))
                ans[i] += c[j + 1];
        }
        mtree[i].push_back(Edge{});
        ufs.init(n + k);
        int prev = i ^ lowbit(i);
        // cerr << i << ' ' << prev << endl;
        // if(i == 1) rep(j,1,n-1) cerr << mtree[prev][j].w << endl;
        int nw = __builtin_ctz(i) + 1;
        // cerr << i << ' ' << nw << endl;
        int j1 = 1, j2 = 1;
        while(j1 <= (int)mtree[prev].size() - 1 || j2 <= n) {
            // cerr << j1 << ' ' << j2 << ' ' << mtree[prev].size() << ' ' << a[nw].size() << endl;
            // cerr << j1 << ' ' << j2 << endl;
            Edge sel;
            if(j2 > n || j1 <= (int)mtree[prev].size() - 1 && mtree[prev][j1].w <= a[nw][j2].w) {
                sel = mtree[prev][j1];
                j1++;
            } else if(j1 > (int)mtree[prev].size() - 1 || j2 <= n && mtree[prev][j1].w > a[nw][j2].w) {
                sel = a[nw][j2];
                j2++;
            }
            if(ufs.same(sel.x, sel.y)) continue;
            ufs.merge(sel.x, sel.y);
            ans[i] += sel.w;
            mtree[i].push_back(move(sel));
        }
    }
    // rep(j,1,n-1) cerr << mtree[1][j].w << endl;
    ll out = LLONG_MAX;
    rep(i,0,(1<<k)-1) {
        out = min(out, ans[i]);
        // cerr << i << ' ' << ans[i] << endl;
    }
    cout << out << endl;
}
int main() {
    // freopen("road3.in", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}