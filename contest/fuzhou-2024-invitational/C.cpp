#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define endl '\n'
using namespace std;
using ll = long long;
constexpr int maxn = 1e5+10;
struct SegmentTree1 {
    ll val[maxn<<2], lazy[maxn<<2];
    void up(int x) {
        val[x] = val[x<<1] + val[x<<1|1];
    }
    void down(int x, int l, int mid, int r) {
        if(lazy[x] != -1) {
            val[x<<1] = lazy[x] * (mid - l + 1);
            val[x<<1|1] = lazy[x] * (r - mid);
            lazy[x<<1] = lazy[x];
            lazy[x<<1|1] = lazy[x];
            lazy[x] = -1;
        }
    }
    void build(int x, int l, int r, const vector<ll> &a) {
        lazy[x] = -1;
        if(l == r) {
            val[x] = a[l];
            return;
        }
        int mid = l + r >> 1;
        build(x << 1, l, mid, a);
        build(x << 1 | 1, mid + 1, r, a);
        up(x);
    }
    void modify(int x, int l, int r, int L, int R, ll v) {
        if(l > R || r < L) return;
        if(L <= l && r <= R) {
            val[x] = v * (r - l + 1);
            lazy[x] = v;
            return;
        }
        int mid = l + r >> 1;
        down(x, l, mid, r);
        modify(x << 1, l, mid, L, R, v);
        modify(x << 1 | 1, mid + 1, r, L, R, v);
        up(x);
    }
    ll query(int x, int l, int r, int L, int R) {
        if(l > R || r < L) return 0;
        if(L <= l && r <= R) return val[x];
        int mid = l + r >> 1;
        down(x, l, mid, r);
        return query(x<<1, l, mid, L, R) + query(x<<1|1, mid+1, r, L, R);
    }
} segSum, segZero;
void solve()
{
    int n,m; cin >> n >> m;
    vector<ll> a(n+5);
    rep(i,1,n) cin >> a[i];
    vector<ll> tmp(n+5);
    rep(i,1,n) tmp[i] = max(1ll, a[i]);
    vector<ll> tmp2(n+5);
    rep(i,1,n) tmp2[i] = (a[i] == 0);
    segSum.build(1, 1, n, tmp);
    segZero.build(1, 1, n, tmp2);

    bool inv = false;
    rep(i,1,m) {
        int op; cin >> op;
        if(op == 1) {
            int l,r; ll k;
            cin >> l >> r >> k;
            segSum.modify(1, 1, n, l, r, max(k, 1ll));
            segZero.modify(1, 1, n, l, r, k == 0);
        } else {
            inv = !inv;
        }
        int l = 1, r = n, mid, ans = 0;
        while(l <= r) {
            mid = l + r >> 1;
            ll ret = segSum.query(1, 1, n, 1, mid);
            if(ret <= mid) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        ll ret2 = segZero.query(1, 1, n, 1, ans);
        // cout << ans << ' ' << ret2 << ' ' << inv << endl;
        if(ans >= n) {
            if((ans - ret2 + inv) % 2 == 0)
                cout << "homura" << endl;
            else
                cout << "madoka" << endl;
        } else {
            if((ans - ret2) % 2 == 0)
                cout << "madoka" << endl;
            else
                cout << "homura" << endl;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);

    solve();
    return 0;
}