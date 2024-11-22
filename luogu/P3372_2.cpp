#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 1e5+10;
int n, m;
ll a[maxn];
struct SegmentTree {
    ll val[maxn << 2];
    ll lz[maxn << 2];
    void pushup(int x) {
        val[x] = val[x << 1] + val[x << 1 | 1];
    }
    void pushdown(int x, int l, int mid, int r) {
        if(lz[x]) {
            val[x << 1] += 1ll * lz[x] * (mid - l + 1);
            val[x << 1 | 1] += 1ll * lz[x] * (r - mid);
            lz[x << 1] += lz[x];
            lz[x << 1 | 1] += lz[x];
            lz[x] = 0;
        }
    }
    void build(int x, int l, int r) {
        lz[x] = 0;
        if(l == r) {
            val[x] = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(x << 1, l, mid);
        build(x << 1 | 1, mid+1, r);
        pushup(x);
    }
    void add(int x, int l, int r, int L, int R, int v) {
        if(l > R || r < L) return;
        if(L <= l && r <= R) {
            val[x] += 1ll * v * (r - l + 1);
            lz[x] += v;
            return;
        }
        int mid = (l + r) >> 1;
        pushdown(x, l, mid, r);
        add(x << 1, l, mid, L, R, v);
        add(x << 1 | 1, mid+1, r, L, R, v);
        pushup(x);
    }
    ll query(int x, int l, int r, int L, int R) {
        if(l > R || r < L) return 0;
        if(L <= l && r <= R) return val[x];
        int mid = (l + r) >> 1;
        pushdown(x, l, mid, r);
        return query(x << 1, l, mid, L, R) + query(x << 1 | 1, mid+1, r, L, R);
    }
}tr;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m;
    rep(i,1,n) cin >> a[i];
    tr.build(1, 1, n);
    rep(_,1,m) {
        int op, x, y, k; cin >> op;
        if(op == 1) {
            cin >> x >> y >> k;
            tr.add(1, 1, n, x, y, k);
        }else{
            cin >> x >> y;
            cout << tr.query(1, 1, n, x, y) << endl;
        }
    }
    return 0;
}