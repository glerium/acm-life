#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 1e8-3;
constexpr ll mod = 1e8-3;
constexpr ll inf = 0x3f3f3f3f;
template<class T, class... Args>
auto Vec(size_t n, Args... args) {
    if constexpr(sizeof...(args) == 1)
        return vector<T>(n, args...);
    else
        return vector(n, Vec<T>(args...));
}
struct BIT {
    vector<int> f;
    int n;
    void init(int x) {
        n = x;
        f.resize(n + 5);
    }
    int lowbit(int x) {
        return x & -x;
    }
    void add(int x, int v) {
        while(x <= n) {
            f[x] += v;
            x += lowbit(x);
        }
    }
    int query(int x) {
        if(x <= 0) return 0;
        int ans = 0;
        while(x) {
            ans += f[x];
            x -= lowbit(x);
        }
        return ans;
    }
} bit;
void solve() {
    int n; cin >> n;
    bit.init(n);
    vector<int> a(n+5), b(n+5);
    rep(i,1,n) cin >> a[i];
    rep(i,1,n) cin >> b[i];
    auto lisan = [&](vector<int> &a) {
        auto b = a;
        sort(b.begin() + 1, b.begin() + 1 + n);
        b[0] = -1;
        int ct = 0;
        map<int,int> mp;
        rep(i,1,n) {
            if(b[i] != b[i-1]) {
                mp[b[i]] = ++ct;
            }
        }
        rep(i,1,n)
            a[i] = mp[a[i]];
    };
    lisan(a);
    lisan(b);
    vector<int> pos(n+5);
    rep(i,1,n) pos[b[i]] = i;
    rep(i,1,n) a[i] = pos[a[i]];
    ll ans = 0;
    rep(i,1,n) {
        ans += bit.query(n) - bit.query(a[i]);
        bit.add(a[i], 1);
        ans %= mod;
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}