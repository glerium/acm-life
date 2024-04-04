#include <bits/stdc++.h>
using namespace std;
constexpr int maxn = 2e5+10;
int n, head[maxn], fa[maxn], ct, sz[maxn];
struct Edge{
    int to, nxt;
}a[maxn];
void add_edge(int x, int y) {
    a[++ct] = {y, head[x]};
    head[x] = ct;
    fa[y] = x;
}
struct Segment_Tree {
    int val[maxn << 2];
    int islazy[maxn << 2], lazy[maxn << 2];
    void pushup(int x) {
        val[x] = val[x << 1 | 1] + val[x << 1];
    }
    void pushdown(int x, int l, int mid, int r) {
        if(!islazy[x]) return;
        val[x << 1] = lazy[x] * (mid - l + 1);
        val[x << 1 | 1] = lazy[x] * (r - mid);
        lazy[x << 1] = lazy[x << 1 | 1] = lazy[x];
        islazy[x] = false;
        islazy[x << 1] = islazy[x << 1 | 1] = true;
    }
    void build(int x, int l, int r) {
        islazy[x] = false;
        if(l == r) {
            val[x] = 0;
            return;
        }
        int mid = l + r >> 1;
        build(x << 1, l, mid);
        build(x << 1 | 1, mid+1, r);
        pushup(x);
    }
    void modify(int x, int l, int r, int L, int R, bool v) {
        if(l > R || r < L) return;
        if(L <= l && r <= R) {
            val[x] = v * (r - l + 1);
            lazy[x] = v;
            islazy[x] = true;
            return;
        }
        int mid = l + r >> 1;
        pushdown(x, l, mid, r);
        modify(x << 1, l, mid, L, R, v);
        modify(x << 1 | 1, mid + 1, r, L, R, v);
        pushup(x);
    }
    int query(int x, int l, int r, int L, int R) {
        if(l > R || r < L) return 0;
        if(L <= l && r <= R) return val[x];
        int mid = l + r >> 1;
        pushdown(x, l, mid, r);
        return query(x << 1, l, mid, L, R) + 
               query(x << 1 | 1, mid + 1, r, L, R);
    }
}t;
namespace Heavy_Light_Decomposition {
    int cnt = 0;
    int tpos[maxn], dep[maxn], wson[maxn], top[maxn];
    void dfs1(int x) {
        sz[x] = 1;
        for(int i=head[x];i;i=a[i].nxt) {
            dep[a[i].to] = dep[x]+1;
            dfs1(a[i].to);
            sz[x] += sz[a[i].to];
            if(sz[a[i].to] > sz[wson[x]])
                wson[x] = a[i].to;
        }
    }
    void dfs2(int x, int chain) {
        tpos[x] = ++cnt;
        top[x] = chain;
        if(wson[x]) dfs2(wson[x], chain);
        for(int i=head[x];i;i=a[i].nxt) {
            if(a[i].to == wson[x]) continue;
            dfs2(a[i].to, a[i].to);
        }
    }
    int query(int x) {
        int ret = 0;
        while(top[x] != 1) {
            ret += t.query(1, 1, n, tpos[top[x]], tpos[x]);
            x = fa[top[x]];
        }
        ret += t.query(1, 1, n, tpos[top[x]], tpos[x]);
        return ret;
    }
    void do_install(int x) {
        while(top[x] != 1) {
            t.modify(1, 1, n, tpos[top[x]], tpos[x], true);
            x = fa[top[x]];
        }
        t.modify(1, 1, n, tpos[top[x]], tpos[x], true);
    }
    int install(int x) {
        int bef = t.query(1, 1, n, 1, n);
        do_install(x);
        int aft = t.query(1, 1, n, 1, n);
        return aft - bef;
    }
    int uninstall(int x) {
        int bef = t.query(1, 1, n, 1, n);
        // printf("modifying: %d, %d\n", x, x+sz[x]-1);
        // for(int i=1;i<=n;i++) cout << t.query(1, 1, n, i, i) << endl;
        t.modify(1, 1, n, tpos[x], tpos[x] + sz[x] - 1, false);
        int aft = t.query(1, 1, n, 1, n);
        // cout << bef << ' ' << aft << endl;
        return bef - aft;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin >> n;
    t.build(1, 1, n);
    // t.modify(1, 1, n, 1, 7, true);
    // cout << t.query(1, 1, n, 1, 3) << endl;
    // return 0;
    for(int i=2;i<=n;i++) {
        int x; cin >> x; x++;
        add_edge(x, i);
    }
    Heavy_Light_Decomposition::dfs1(1);
    Heavy_Light_Decomposition::dfs2(1, 1);
    
    int q; cin >> q;
    while(q--) {
        string op; cin >> op;
        int x; cin >> x; x++;
        if(op == "install") {
            cout << Heavy_Light_Decomposition::install(x) << endl;
        }else{
            cout << Heavy_Light_Decomposition::uninstall(x) << endl;
        }
    }
    return 0;
}