#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 1e9+7;
constexpr ll inf = 0x3f3f3f3f;
template<class T, class... Args>
auto Vec(size_t n, Args... args) {
    if constexpr(sizeof...(args) == 1)
        return vector<T>(n, args...);
    else
        return vector(n, Vec<T>(args...));
}
ll x1[maxn] = {1, 1145141919810%mod}, x2[maxn] = {1, 41511419491001%mod};
ll r1[maxn] = {1}, r2[maxn] = {1};
ll qpow(ll x, ll y) {
    if(!x) return 0;
    if(!y) return 1;
    if(y&1) return x * qpow(x, y - 1) % mod;
    return qpow(x * x % mod, y / 2);
}
ll frac(ll x, ll y) {
    return x * qpow(y, mod - 2) % mod;
}
struct SegmentTree {
    ll val[maxn << 2], lazy[maxn << 2];
    void up(int x) {
        val[x] = (val[x << 1] + val[x << 1 | 1]) % mod;
    }
    void down(int x, int l, int mid, int r) {
        if(lazy[x] != 1) {
            val[x << 1] *= lazy[x];
            val[x << 1 | 1] *= lazy[x];
            lazy[x << 1] *= lazy[x];
            lazy[x << 1 | 1] *= lazy[x];

            val[x << 1] %= mod;
            val[x << 1 | 1] %= mod;
            lazy[x << 1] %= mod;
            lazy[x << 1 | 1] %= mod;

            lazy[x] = 1;
        }
    }
    void build(int x, int l, int r, const vector<int> &a) {
        lazy[x] = 1;
        if(l == r) {
            val[x] = a[l];
            return;
        }
        int mid = l + r >> 1;
        build(x << 1, l, mid, a);
        build(x << 1 | 1, mid + 1, r, a);
        up(x);
    }
    void multiply(int x, int l, int r, int L, int R, ll v) {
        if(l > R || r < L) return;
        if(L <= l && r <= R) {
            val[x] *= v; val[x] %= mod;
            lazy[x] *= v; lazy[x] %= mod;
            return;
        }
        int mid = l + r >> 1;
        down(x, l, mid, r);
        multiply(x << 1, l, mid, L, R, v);
        multiply(x << 1 | 1, mid + 1, r, L, R, v);
        up(x);
    }
    ll query(int x, int l, int r, int L, int R) {
        if(l > R || r < L) return 0;
        if(L <= l && r <= R) return val[x];
        int mid = l + r >> 1;
        down(x, l, mid, r);
        return (query(x<<1, l, mid, L, R) + query(x<<1|1, mid+1, r, L, R)) % mod;
    }
} tr1, tr2, rt1, rt2;

struct SegmentTree2 {
    ll val[maxn << 2], lazy[maxn << 2];
    void up(int x) {
        val[x] = (val[x << 1] + val[x << 1 | 1]);
    }
    void down(int x, int l, int mid, int r) {
        if(lazy[x]) {
            val[x << 1] += lazy[x] * (mid - l + 1);
            val[x << 1 | 1] += lazy[x] * (r - mid);
            lazy[x << 1] += lazy[x];
            lazy[x << 1 | 1] += lazy[x];

            lazy[x] = 0;
        }
    }
    void build(int x, int l, int r, const vector<int> &a) {
        lazy[x] = 0;
        if(l == r) {
            val[x] = a[l];
            return;
        }
        int mid = l + r >> 1;
        build(x << 1, l, mid, a);
        build(x << 1 | 1, mid + 1, r, a);
        up(x);
    }
    void add(int x, int l, int r, int L, int R, ll v) {
        if(l > R || r < L) return;
        if(L <= l && r <= R) {
            val[x] += v * (r - l + 1);
            lazy[x] += v;
            return;
        }
        int mid = l + r >> 1;
        down(x, l, mid, r);
        add(x << 1, l, mid, L, R, v);
        add(x << 1 | 1, mid + 1, r, L, R, v);
        up(x);
    }
    ll query(int x, int l, int r, int L, int R) {
        if(l > R || r < L) return 0;
        if(L <= l && r <= R) return val[x];
        int mid = l + r >> 1;
        down(x, l, mid, r);
        return query(x<<1, l, mid, L, R) + query(x<<1|1, mid+1, r, L, R);
    }
} tr;


void solve() {
    int n,q; cin >> n >> q;
    vector<int> a(n+5);
    rep(i,1,n) cin >> a[i];
    vector<int> tmp(n+5);
    rep(i,1,n) tmp[i] = x1[a[i]];  tr1.build(1, 1, n, tmp);
    rep(i,1,n) tmp[i] = x2[a[i]];  tr2.build(1, 1, n, tmp);
    rep(i,1,n) tmp[i] = r1[a[i]];  rt1.build(1, 1, n, tmp);
    rep(i,1,n) tmp[i] = r2[a[i]];  rt2.build(1, 1, n, tmp);
    tr.build(1, 1, n, a);
    
    // ll x = 0, y = 0;
    // rep(i,1,n) x = (x + x1[a[i]]) % mod;
    // rep(i,1,n) y = (y + r1[a[i]]) % mod;
    // cout << x << ' ' << y * qpow(x1[1], 9) % mod << endl;

    while(q--) {
        int op, l, r; cin >> op >> l >> r;
        if(op == 1) {
            int v; cin >> v;
            tr1.multiply(1, 1, n, l, r, x1[v]);
            tr2.multiply(1, 1, n, l, r, x2[v]);
            rt1.multiply(1, 1, n, l, r, r1[v]);
            rt2.multiply(1, 1, n, l, r, r2[v]);
            tr.add(1, 1, n, l, r, v);
        } else {
            ll p1 = tr1.query(1, 1, n, l, r);
            ll p2 = tr2.query(1, 1, n, l, r);
            ll n1 = rt1.query(1, 1, n, l, r);
            ll n2 = rt2.query(1, 1, n, l, r);
            ll sum = tr.query(1, 1, n, l, r);
            // cout << p1 << ' ' << p2 << ' ' << n1 << ' ' << n2 << endl;
            // cout << "s=" << sum << endl;
            int len = r - l + 1;
            if(len % 2 == 1 || sum % (len / 2) != 0) {
                cout << "NO" << endl;
                continue;
            }
            ll m = sum / (len / 2);
            // cout << p1 << ' ' << n1 * qpow(x1[1], m) % mod << ' ' << p2 << ' ' << n2 * qpow(x2[1], m) % mod << endl;
            if(p1 == n1 * qpow(x1[1], m) % mod && p2 == n2 * qpow(x2[1], m) % mod) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
}
void init() {
    r1[1] = frac(1, x1[1]);
    r2[1] = frac(1, x2[1]);

    rep(i,2,2e5) x1[i] = x1[i-1] * x1[1] % mod;
    rep(i,2,2e5) x2[i] = x2[i-1] * x2[1] % mod;
    rep(i,2,2e5) r1[i] = r1[i-1] * r1[1] % mod;
    rep(i,2,2e5) r2[i] = r2[i-1] * r2[1] % mod;
}
int main() {
    init();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}
