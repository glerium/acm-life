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
struct Query {
    int l,r,i;
    bool operator<(const Query& rhs) const {
        return r < rhs.r;
    }
};
struct BIT {
    vector<int> f;
    int n;
    void init(int x) {
        n = x;
        f.resize(n + 5);
    }
    int lowbit(int x) {
        return x & -x;
    }
    void add(int x, int v) {
        while(x <= n) {
            f[x] += v;
            x += lowbit(x);
        }
    }
    int query(int x) {
        if(x <= 0) return 0;
        int ans = 0;
        while(x) {
            ans += f[x];
            x -= lowbit(x);
        }
        return ans;
    }
} bit;
void solve() {
    int n,m; cin >> n >> m;
    bit.init(n);
    vector<int> a(n+5);
    rep(i,1,n) cin >> a[i];
    vector<vector<int>> mp(n+5);
    map<int,int> pos;
    rep(i,1,n) pos[a[i]] = i;
    auto b = a;
    sort(b.begin() + 1, b.begin() + 1 + n);
    vector<pair<int,int>> seg;
    if(n != 1) {
        seg.emplace_back(pos[b[1]], pos[b[2]]);
        seg.emplace_back(pos[b[n]], pos[b[n-1]]);
    }
    rep(i,2,n-1) {
        int l = b[i] - b[i-1],
            r = b[i+1] - b[i];
        if(l <= r) seg.emplace_back(pos[b[i]], pos[b[i-1]]);
        if(l >= r) seg.emplace_back(pos[b[i]], pos[b[i+1]]);
    }
    for(auto [x, y] : seg) {
        if(x > y) swap(x, y);
        mp[y].push_back(x);
    }
    vector<Query> q(m+5);
    rep(i,1,m) {
        cin >> q[i].l >> q[i].r;
        q[i].i = i;
    }
    sort(q.begin() + 1, q.begin() + 1 + m);

    int r = 0;
    vector<ll> ans(m+5);
    rep(i,1,m) {
        while(r < q[i].r) {
            r++;
            for(auto j : mp[r]) {
                bit.add(j, 1);
            }
        }
        ans[q[i].i] = bit.query(n) - bit.query(q[i].l - 1);
    }
    ll ret = 0;
    rep(i,1,m) {
        // cout << ans[i] << endl;
        ret += ans[i] * i;
    }
    cout << ret << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}