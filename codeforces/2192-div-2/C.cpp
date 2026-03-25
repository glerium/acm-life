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
    int n,h,k; cin >> n >> h >> k;
    vector<int> a(n+1);
    rep(i,1,n) cin >> a[i];
    ll s = accumulate(a.begin(), a.end(), 0ll);
    ll tm = 1ll * h / s * n + 1ll * max(h - 1, 0) / s * k;
    h %= s;
    if(h == 0) {
        cout << tm << endl;
        return;
    }
    vector<int> pre(n+5), aft(n+5);
    pre[0] = 0x3f3f3f3f;
    rep(i,1,n) pre[i] = min(pre[i-1], a[i]);
    for(int i=n;i>=1;i--) aft[i] = max(aft[i+1], a[i]);
    vector<ll> sm(n+1);
    rep(i,1,n) sm[i] = sm[i-1] + a[i];
    rep(i,1,n) {
        if(sm[i] >= h || sm[i] - pre[i] + aft[i+1] >= h) {
            cout << tm + i << endl;
            return;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}