#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int maxn = 1e6 + 10;
int n, q, mod, a[maxn];
struct SegmentTree {
    ll val[maxn<<2], lazy1[maxn<<2], lazy2[maxn<<2];
    void pushup(int x) {                                            // 假设已获得下层节点的val，将其传递至本层
        val[x] = (val[x << 1] + val[x << 1 | 1]) % mod;
    }
    void pushdown(int x, int l, int r) {
        int mid = (l + r) / 2;
        lazy1[x << 1] = (lazy1[x << 1] * lazy2[x] + lazy1[x]) % mod;
        lazy1[x << 1 | 1] = (lazy1[x << 1 | 1] * lazy2[x] + lazy1[x]) % mod;
        lazy2[x << 1] = lazy2[x << 1] * lazy2[x] % mod;
        lazy2[x << 1 | 1] = lazy2[x << 1 | 1] * lazy2[x] % mod;
        val[x << 1] = (val[x << 1] * lazy2[x] + lazy1[x] * (mid - l + 1)) % mod;
        val[x << 1 | 1] = (val[x << 1 | 1] * lazy2[x] + lazy1[x] * (r - mid)) % mod;
        lazy1[x] = 0;
        lazy2[x] = 1;
    }
    void build(int x, int l, int r) {
        lazy1[x] = 0;
        lazy2[x] = 1;
        if(l == r) {
            val[x] = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(x << 1, l, mid);
        build(x << 1 | 1, mid + 1, r);
        pushup(x);
    }
    void add(int x, int l, int r, int L, int R, ll v) {
        if(l > R || r < L) return;
        pushdown(x, l, r);
        if(L <= l && r <= R) {
            lazy1[x] = (lazy1[x] + v) % mod;
            val[x] = (val[x] + (r - l + 1) * v) % mod;
            return;
        }
        int mid = (l + r) / 2;
        add(x << 1, l, mid, L, R, v);
        add(x << 1 | 1, mid+1, r, L, R, v);
        pushup(x);
    }
    void mul(int x, int l, int r, int L, int R, ll v) {
        if(l > R || r < L) return;
        pushdown(x, l, r);
        if(L <= l && r <= R) {
            lazy1[x] = (lazy1[x] * v) % mod;
            lazy2[x] = (lazy2[x] * v) % mod;
            val[x] = (val[x] * v) % mod;
            return;
        }
        int mid = (l + r) / 2;
        mul(x << 1, l, mid, L, R, v);
        mul(x << 1 | 1, mid+1, r, L, R, v);
        pushup(x);
    }
    ll query_sum(int x, int l, int r, int L, int R) {
        if(l > R || r < L) return 0;
        if(L <= l && r <= R) return val[x];
        int mid = (l + r) / 2;
        pushdown(x, l, r);
        return (query_sum(x << 1, l, mid, L, R) + 
                query_sum(x << 1 | 1, mid+1, r, L, R)) % mod;
    }
} t;
int main() {
    cin>>n>>q>>mod;
    for(int i=1;i<=n;i++) cin>>a[i];
    t.build(1, 1, n);
    while(q--) {
        int op, x, y; cin >> op >> x >> y;
        if(op == 1) {
            int k; cin >> k;
            t.mul(1, 1, n, x, y, k);
        }else if(op == 2) {
            int k; cin >> k;
            t.add(1, 1, n, x, y, k);
        }else {
            cout << t.query_sum(1, 1, n, x, y) << endl;
        }
    }
    return 0;
}