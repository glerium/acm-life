#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 5e5+10;
constexpr ll mod = 998244353;

struct BIT {
    int f[maxn];
    int lowbit(int x) {
        return x & -x;
    }
    void addi(int x, int v) {
        while(x <= maxn - 10) {
            f[x] += v;
            x += lowbit(x);
        }
    }
    int query(int x) {
        int ret = 0;
        while(x) {
            ret += f[x];
            x -= lowbit(x);
        }
        return ret;
    }
    void add(int l, int r, int v) {
        // cout << ":" << l << ' ' << r << ' ' << v << ":" <<endl;
        addi(l, v);
        addi(r+1, -v);
    }
} bit;

void solve() {
    int n; cin >> n;
    int a[n+5] = {};
    rep(i,1,n) cin >> a[i];
    int b[n+5] = {};
    b[1] = -(n-1);
    rep(i,2,n) b[i] = b[i-1] + 2;
    rep(i,1,n)
        bit.add(i, i, b[i]);
    rep(i,1,n) {
        int nowv = bit.query(i);
        if(a[i] + nowv < 0) {
            int delta = - (a[i] + nowv);
            bit.add(n - delta + 1, n, -1);
            bit.add(i, i, delta);
        }
    }
    rep(i,1,n) {
        cout << a[i] + bit.query(i) << ' ';
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
