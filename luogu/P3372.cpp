#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int maxn = 1e5 + 10;
int n, m, a[maxn];
struct SegmentTree {
    ll val[maxn << 2], lazy[maxn << 2];
    void pushup(int x) {                                // 用下层节点的val更新当前节点
        val[x] = val[x << 1 | 1] + val[x << 1];
    }

    void pushdown(int x, int l, int mid, int r) {       // 将本层的lazy值向下传递
        if(lazy[x]) {
            val[x << 1] += 1ll * lazy[x] * (mid - l + 1);
            val[x << 1 | 1] += 1ll * lazy[x] * (r - mid);
            lazy[x << 1] += lazy[x];
            lazy[x << 1 | 1] += lazy[x];
            lazy[x] = 0;
        }
    }

    void build(int x, int l, int r) {
        lazy[x] = 0;
        if(l == r) {
            val[x] = a[l];
            return;
        }
        int mid = (l + r) / 2;
        build(x << 1, l, mid);
        build(x << 1 | 1, mid + 1, r);
        pushup(x);                                  // 用下层的数字之和更新当前节点的val
    }
    
    // 将一个区间的所有数字更新，x是当前节点，[l,r]是当前节点掌管的区间，[L,R]是需要更新的区间，v是更新值
    void add(int x, int l, int r, int L, int R, int v) {
        if(l > R || r < L) return;                  // 区间不重叠
        if(L <= l && r <= R) {                      // 当前区间完全被包含
            val[x] += 1ll * (r - l + 1) * v;
            lazy[x] += v;
            return;
        }
        int mid = (l + r) / 2;
        pushdown(x, l, mid, r);
        add(x << 1, l, mid, L, R, v);
        add(x << 1 | 1, mid+1, r, L, R, v);

        // 此时x的lazy=0，所有子节点的val都已确定
        pushup(x);
    }

    ll query_sum(int x, int l, int r, int L, int R) {
        if(l > R || r < L) return 0;
        if(L <= l && r <= R) return val[x];
        int mid = (l + r) / 2;
        pushdown(x, l, mid, r);
        return query_sum(x << 1, l, mid, L, R) + query_sum(x << 1 | 1, mid + 1, r, L, R);
    }
} t;
int main() {
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin>>a[i];
    t.build(1, 1, n);
    while(m--) {
        int op; cin>>op;
        if(op == 1) {
            int x, y, k; cin>>x>>y>>k;
            t.add(1, 1, n, x, y, k);
        }else{
            int x, y; cin>>x>>y;
            cout << t.query_sum(1, 1, n, x, y) << endl;
        }
    }
    return 0;
}