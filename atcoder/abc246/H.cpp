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
typedef vector<vector<ll>> Matrix;
Matrix matmul(const Matrix& a, const Matrix& b) {
    Matrix res = Vec<ll>(3, 3, 0);
    rep(i,0,2) rep(j,0,2) {
        rep(k,0,2) {
            res[i][j] += a[i][k] * b[k][j] % mod;
            res[i][j] %= mod;
        }
    }
    return res;
}
Matrix operator*(const Matrix& a, const Matrix& b) {
    return matmul(a, b);
}

struct SegmentTree {
    Matrix val[maxn<<2];
    void up(int x) {
        val[x] = val[x << 1] * val[x << 1 | 1];
    }
    void build(int x, int l, int r, const vector<Matrix>& a) {
        if(l == r) {
            val[x] = a[l];
            return;
        }
        int mid = l + r >> 1;
        build(x<<1, l, mid, a);
        build(x<<1|1, mid+1, r, a);
        up(x);
    }
    void edit(int x, int l, int r, int pos, const Matrix &v) {
        if(l > pos || r < pos) return;
        int mid = l + r >> 1;
        if(l == r) {
            val[x] = v;
            return;
        }
        edit(x << 1, l, mid, pos, v);
        edit(x << 1 | 1, mid + 1, r, pos, v);
        up(x);
    }
} tr;
void solve() {
    int n,q; cin >> n >> q;
    string s; cin >> s; s = ' ' + s;
    const Matrix mat[3] = {
        {{1,0,0},{1,1,0},{1,0,1}},
        {{1,1,0},{0,1,0},{0,1,1}},
        {{1,1,0},{1,1,0},{1,1,1}}
    };
    const Matrix init = {{0,0,1},{0,0,0},{0,0,0}};
    vector<Matrix> a(n+5);
    a[0] = init;
    rep(i,1,n) {
        if(s[i] == '0') a[i] = mat[0];
        else if(s[i] == '1') a[i] = mat[1];
        else a[i] = mat[2];
    }
    tr.build(1, 0, n, a);

    rep(_,1,q) {
        int x; char c;
        cin >> x >> c;
        s[x] = c;
        if(c == '0') tr.edit(1, 0, n, x, mat[0]);
        else if(c == '1') tr.edit(1, 0, n, x, mat[1]);
        else tr.edit(1, 0, n, x, mat[2]);
        cout << (tr.val[1][0][0] + tr.val[1][0][1]) % mod << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}