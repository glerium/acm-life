#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 1e6+10;
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
    int n; cin >> n;
    vector<int> a(n+5);
    rep(i,1,n) cin >> a[i];
    bit.init(n);
    int m; cin >> m;
    vector<Query> q(m+5);
    rep(i,1,m) {
        cin >> q[i].l >> q[i].r;
        q[i].i = i;
    }
    sort(q.begin() + 1, q.begin() + 1 + m);
    vector<int> last(maxn);
    int nowr = 0;
    vector<int> ans(m+5);
    rep(i,1,m) {
        while(nowr < q[i].r) {
            nowr++;
            if(last[a[nowr]] != 0) {
                bit.add(last[a[nowr]], -1);
            }
            bit.add(nowr, 1);
            last[a[nowr]] = nowr;
        }
        ans[q[i].i] = bit.query(nowr) - bit.query(q[i].l - 1);
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