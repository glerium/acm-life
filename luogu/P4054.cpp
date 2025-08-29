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
struct BIT2d {
    vector<vector<int>> f;
    int n,m;
    int lowbit(int x) {
        return x & -x;
    }
    void init(int n, int m) {
        this->n = n;
        this->m = m;
        f = Vec<int>(n+5, m+5, 0);
    }
    void modify(int x, int y, int v) {
        for(int i = x; i <= n; i += lowbit(i)) {
            for(int j = y; j <= m; j += lowbit(j)) {
                f[i][j] += v;
            }
        }
    }
    int query(int x, int y) {
        int ans = 0;
        for(int i = x; i > 0; i -= lowbit(i)) {
            for(int j = y; j > 0; j -= lowbit(j)) {
                ans += f[i][j];
            }
        }
        return ans;
    }
    int queryMatrix(int x1, int y1, int x2, int y2) {
        return query(x2, y2) - query(x1 - 1, y2) - query(x2, y1 - 1) + query(x1 - 1, y1 - 1);
    }
};
void solve() {
    int n,m; cin >> n >> m;
    auto r = Vec<int>(n+5, m+5, 0);
    vector<BIT2d> a(107);
    rep(i,1,100) a[i].init(n, m);
    rep(i,1,n) rep(j,1,m) {
        cin >> r[i][j];
        a[r[i][j]].modify(i, j, 1);
    }
    int q; cin >> q;
    while(q--) {
        int op; cin >> op;
        if(op == 1) {
            int x,y,c; cin >> x >> y >> c;
            a[r[x][y]].modify(x, y, -1);
            r[x][y] = c;
            a[c].modify(x, y, 1);
        } else {
            int x1, y1, x2, y2, c;
            cin >> x1 >> x2 >> y1 >> y2 >> c;
            cout << a[c].queryMatrix(x1, y1, x2, y2) << endl;
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