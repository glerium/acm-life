#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define per(i,x,y) for(int i=x;i>=y;i--)
using namespace std;
typedef long long ll;
constexpr int maxn = 1e5+10;
struct BIT {
    int lim = 0;
    int f[maxn];
    void init(int x) {
        lim = x;
        for(int i=0;i<=x;i++)
            f[i] = 0;
    }
    int lowbit(int x) {
        return x & -x;
    }
    int query(int x) {
        int ret = 0;
        while(x) {
            ret += f[x];
            x -= lowbit(x);
        }
        return ret;
    }
    void add(int x, int v) {
        while(x <= lim) {
            f[x] += v;
            x += lowbit(x);
        }
    }
} bit;
void solve() {
    int n; cin >> n;
    int a[n+5] = {};
    rep(i,1,n) cin>>a[i];
    ll f1[n+5]={}, f2[n+5]={};
    bit.init(1e5);
    rep(i,1,n) {
        f1[i] = bit.query(a[i]-1);
        bit.add(a[i], 1);
    }
    bit.init(1e5);
    per(i,n,1) {
        f2[i] = bit.query(a[i]-1);
        bit.add(a[i], 1);
    }
    ll ans = 0;
    rep(i,1,n) {
        ans += f1[i] * (n-i-f2[i]) + (i-1-f1[i]) * f2[i];
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}