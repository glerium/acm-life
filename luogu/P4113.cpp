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
    int l,r;
    int i;
    bool operator<(const Query& rhs) const {
        return r < rhs.r;
    }
};
struct BIT {
    vector<int> f;
    int n;
    void init(int x) {
        f.resize(x + 5);
        this->n = x;
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
    int n,c,m; cin >> n >> c >> m;
    bit.init(n);
    vector<int> a(n+5);
    vector<Query> q(m+5);
    rep(i,1,n) cin >> a[i];
    rep(i,1,m) {
        cin >> q[i].l >> q[i].r;
        q[i].i = i;
    }
    sort(q.begin() + 1, q.begin() + 1 + m);
    vector<int> last(c+5), llast(c+5), ans(m+5);
    int r = 0;
    rep(i,1,m) {
        while(r < q[i].r) {
            r++;
            int old = llast[a[r]], nw = last[a[r]];
            if(old) bit.add(old, -1);
            if(nw) bit.add(nw, 1);
            llast[a[r]] = last[a[r]];
            last[a[r]] = r;
        }
        ans[q[i].i] = bit.query(c) - bit.query(q[i].l - 1);
    }
    rep(i,1,m) cout << ans[i] << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}