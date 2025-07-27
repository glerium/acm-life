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
void solve() {
    int n,m; cin >> n >> m;
    vector<int> a(n+5);
    rep(i,1,n) cin >> a[i];
    vector<int> b(m+5);
    rep(i,1,m) cin >> b[i];
    vector<ll> s(n+5);
    rep(i,1,n) s[i] = s[i-1] + a[i];
    vector<vector<int>> no(n+5);
    rep(i,1,n) rep(j,1,m) {
        int l = i, r = n, mid, ans = -1;
        while(l <= r) {
            mid = l + r >> 1;
            if(s[mid] - s[i - 1] <= b[j]) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        if(ans == -1) continue;
        if(s[ans] - s[i - 1] != b[j]) continue;
        no[ans].push_back(i);   // [l, ans] \in S
    }
    vector<ll> f(n+5);
    ll sum = 1;
    f[0] = 1;
    // f[i] = \sum f[j-1] where j ... i is legal
    rep(i,1,n) {
        f[i] = sum;
        for(auto j : no[i]) {
            f[i] -= f[j-1];
            f[i] = (f[i] % mod + mod) % mod;
        }
        sum += f[i];
        sum %= mod;
    }
    cout << f[n] << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}