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
ll calcNextStep(ll x) {
    for(int i=0;i<60;i++) {
        if(x&(1ll<<i)) continue;
        return (1ll<<i);
    }
    return -1;
}
void solve() {
    ll n,k; cin >> n >> k;
    vector<ll> a(n+5);
    rep(i,1,n) cin >> a[i];
    int ans = 0;
    rep(i,1,n) ans += __popcount(a[i]);
    priority_queue<pair<ll,ll>> q;
    rep(i,1,n) {
        q.push({-calcNextStep(a[i]), a[i]});
    }
    int ct = 0;
    while(k > 0 && !q.empty()) {
        auto [step, val] = q.top();
        // cout << -step << ' ' << val << endl;
        q.pop();
        step = -step;
        if(k < step) break;
        k -= step;
        rep(i,0,60) {
            if(val & (1ll << i)) continue;
            val |= 1ll << i;
            break;
        }
        ans++;
        q.push({-calcNextStep(val), val});
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
