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
    int n; ll s,x;
    cin >> n >> s >> x;
    vector<ll> a(n+5);
    rep(i,1,n) cin >> a[i];
    vector<ll> sum(n+5);
    rep(i,1,n) sum[i] = sum[i-1] + a[i];
    map<ll,vector<int>> mp;
    rep(i,1,n) mp[sum[i]].push_back(i);
    int lef = -1, rig = -1;
    // lef: first eq x
    // rig: first gr x
    // r \in [max(lef, l), rig-1]
    ll ans = 0;
    rep(l_,0,n-1) {
        // l_: l-1
        int l = l_ + 1;
        if(lef < l) {
            lef = l;
            while(lef <= n && a[lef] != x)
                lef++;
        }
        if(rig < l) {
            rig = l;
            while(rig <= n && a[rig] <= x)
                rig++;
        }
        int left = max(lef, l);
        int right = rig - 1;
        if(left > right)
            continue;
        ll target = sum[l_] + s;
        auto pleft = lower_bound(mp[target].begin(), mp[target].end(), left);
        auto pright = prev(upper_bound(mp[target].begin(), mp[target].end(), right));
        ans += pright - pleft + 1;
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
