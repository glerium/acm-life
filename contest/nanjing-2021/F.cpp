#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 5e5+10;
int n, a[maxn];
struct SegmentTree {
    ll mx[maxn<<2];
    ll lz[maxn<<2];
    void pushup(int x) {
        mx[x] = max(mx[x<<1], mx[x<<1|1]);
    }
    void pushdown(int x, int l, int mid, int r) {
        if(lz[x]) {
            mx[x<<1] += lz[x];
            mx[x<<1|1] += lz[x];
            lz[x<<1] += lz[x];
            lz[x<<1|1] += lz[x];
            lz[x] = 0;
        }
    }
    void build(int x, int l, int r) {
        lz[x] = 0;
        if(l == r) {
            mx[x] = a[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(x<<1, l, mid);
        build(x<<1|1, mid+1, r);
        pushup(x);
    }
    void add(int x, int l, int r, int L, int R, ll val) {
        if(l > R || r < L) return;
        if(L <= l && r <= R) {
            mx[x] += val;
            lz[x] += val;
            return;
        }
        int mid = (l + r) >> 1;
        pushdown(x, l, mid, r);
        add(x << 1, l, mid, L, R, val);
        add(x << 1 | 1, mid+1, r, L, R, val);
        pushup(x);
    }
    ll query_one_item(int x, int l, int r, ll val) {
        if(mx[x] < val) return -1;
        if(l == r) return l;
        int mid = (l + r) >> 1;
        pushdown(x, l, mid, r);
        int ret = -1;
        if((ret = query_one_item(x<<1, l, mid, val)) != -1)
            return ret;
        else return query_one_item(x<<1|1, mid+1, r, val);
    }
    ll query(int x, int l, int r, int id) {
        if(id < l || id > r) return 0;
        if(l == r) return mx[x];
        int mid = (l + r) >> 1;
        pushdown(x, l, mid, r);
        if(id <= mid) return query(x<<1, l, mid, id);
        return query(x<<1|1, mid+1, r, id);
    }
}tr;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    rep(i,1,n) cin >> a[i];
    tr.build(1, 1, n);
    rep(i,1,n) {
        int select = tr.query_one_item(1, 1, n, n-1);
        if(select == -1) {
            rep(j,1,n) {
                cout << tr.query(1, 1, n, j) << " \n"[j==n];
            }
            return 0;
        } else {
            tr.add(1, 1, n, select, select, -(n-1));
            tr.add(1, 1, n, 1, select-1, 1);
            tr.add(1, 1, n, select+1, n, 1);
        }
    }
    cout << "Recurrent" << endl;
    return 0;
}