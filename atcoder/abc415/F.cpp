#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 5e5+10;
constexpr ll mod = 998244353;
constexpr ll inf = 0x3f3f3f3f;
template<class T, class... Args>
auto Vec(size_t n, Args... args) {
    if constexpr(sizeof...(args) == 1)
        return vector<T>(n, args...);
    else
        return vector(n, Vec<T>(args...));
}
struct SegmentTree {
    int val[maxn << 2], lazy[maxn << 2];
    void up(int x) {
        val[x] = max(val[x << 1], val[x << 1 | 1]);
    }
    void down(int x, int l, int mid, int r) {
        if(lazy[x]) {
            val[x << 1] = lazy[x];
            val[x << 1 | 1] = lazy[x];
            lazy[x << 1] = lazy[x << 1 | 1] = lazy[x];
            lazy[x] = 0;
        }
    }
    void build(int x, int l, int r, const vector<int> &f) {
        lazy[x] = 0;
        if(l == r) {
            val[x] = f[l];
            return;
        }
        int mid = l + r >> 1;
        build(x << 1, l, mid, f);
        build(x << 1 | 1, mid + 1, r, f);
        up(x);
    }
    int query(int x, int l, int r, int L, int R) {
        if(l > R || r < L) return 0;
        if(L <= l && r <= R) return val[x];
        int mid = l + r >> 1;
        down(x, l, mid, r);
        return max(
            query(x << 1, l, mid, L, R),
            query(x << 1 | 1, mid + 1, r, L, R)
        );
    }
    void modify(int x, int l, int r, int L, int R, int v) {
        if(l > R || r < L) return;
        if(L <= l && r <= R) {
            val[x] = v;
            lazy[x] = v;
            return;
        }
        int mid = l + r >> 1;
        down(x, l, mid, r);
        modify(x << 1, l, mid, L, R, v);
        modify(x << 1 | 1, mid + 1, r, L, R, v);
        up(x);
    }
} tr, tri;
void solve() {
    int n,q; cin >> n >> q;
    string s; cin >> s; s = ' ' + s;
    vector<int> f(n+5), fidx(n+5), idx(n+5);
    int ct = 0;
    rep(i,1,n) {
        if(s[i] == s[i-1]) {
            idx[i] = idx[i-1];
            fidx[ct]++;
        } else {
            idx[i] = ++ct;
            fidx[ct] = 1;
        }
    }
    rep(i,1,n) f[i] = fidx[idx[i]];
    vector<pair<int,int>> indices(n + q * 10 + 5, {inf, -inf});
    rep(i,1,n) {
        indices[idx[i]].first = min(indices[idx[i]].first, i);
        indices[idx[i]].second = max(indices[idx[i]].second, i);
    }
    tr.build(1, 1, n, f);
    tri.build(1, 1, n, idx);
    while(q--) {
        int type; cin >> type;
        if(type == 1) {
            int i; char x;
            cin >> i >> x;
            s[i] = x;
            if(i - 1 > 1) {
                int idx = tri.query(1, 1, n, i - 1, i - 1);
                auto [l, r] = indices[idx];
                if(x == s[i - 1]) {
                    indices[++ct] = {l, i};
                    tri.modify(1, 1, n, l, i, ct);
                    fidx[ct] = i - l + 1;
                } else {
                    indices[++ct] = {l, i - 1};
                    tri.modify(1, 1, n, l, i - 1, ct);
                    fidx[ct] = i - l;

                    indices[++ct] = {i, i};
                    tri.modify(1, 1, n, i, i, ct);
                    fidx[ct] = 1;
                }
            }
            if(i + 1 < n) {
                int idxl = tri.query(1, 1, n, i - 1, i - 1);
                auto [l1, r1] = indices[idxl];
                int idxr = tri.query(1, 1, n, i + 1, i + 1);
                auto [l2, r2] = indices[idxr];
                if(x == s[i + 1]) {
                    indices[++ct] = {l1, r2};
                    tri.modify(1, 1, n, l1, r2, ct);
                    fidx[ct] = r2 - l1 + 1;
                } else {
                    indices[++ct] = {i + 1, r2};
                    tri.modify(1, 1, n, i + 1, r2, ct);
                    fidx[ct] = r2 - i;
                }
            }
        } else {
            int l, r; cin >> l >> r;
            int ans = 0;
            {
                int idx = tri.query(1, 1, n, l, l);
                auto [L, R] = indices[idx];
                ans = max(ans, R - l + 1);
                if(R + 1 > n) {
                    cout << ans << endl;
                    continue;
                } else {
                    l = indices[tri.query(1, 1, n, R+1, R+1)].first;
                }
            }
            {
                int idx = tri.query(1, 1, n, r, r);
                auto [L, R] = indices[idx];
                ans = max(ans, r - L + 1);
                if(L - 1 < 1) {
                    cout << ans << endl;
                    continue;
                } else {
                    r = indices[tri.query(1, 1, n, L-1, L-1)].second;
                }
            }
            ans = max(ans, tr.query(1, 1, n, l, r));
            cout << ans << endl;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}