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
    ll n,S,x; cin >> n >> S >> x;
    vector<ll> a(n+5);
    rep(i,1,n) cin >> a[i];
    auto st = Vec<ll>(30, n+5, -0x3f3f3f3f);
    a[0] = -0x3f3f3f3f;
    rep(i,0,n) st[0][i] = a[i];
    rep(j,1,20) rep(i,0,n) {
        st[j][i] = max(st[j-1][i], st[j-1][min(n, i + (1ll<<(j-1)))]);
    }
    auto query = [&](int l, int r) {
        ll ans = -0x3f3f3f3f;
        int now = l;
        for(int j=20;j>=0;j--) {
            int x = now + (1ll<<j) - 1;
            if(x <= r) {
                ans = max(ans, st[j][now]);
                now += (1ll << j);
            }
        }
        return ans;
    };
    map<ll,vector<int>> mp;
    vector<ll> s(n+5);
    rep(i,1,n) s[i] = s[i-1] + a[i];
    mp[0].push_back(0);
    rep(i,1,n) mp[s[i]].push_back(i);
    ll ans = 0;
    rep(r,1,n) {
        if(query(1, r) < x) continue;
        int L = 0, R = r - 1, mid, highl = -1;
        while(L <= R) {
            mid = L + R >> 1;
            // if(r == 6)
            // cout << "query " << mid+1 << ' ' << r << endl;
            if(query(mid + 1, r) <= x) {
                highl = mid;
                L = mid + 1;
            } else {
                R = mid - 1;
            }
        }
        if(highl == -1) continue;
        L = 0, R = highl;
        int lowl = -1;
        while(L <= R) {
            mid = L + R >> 1;
            // cout << "query " << mid+1 << ' ' << r << ' ' << query(mid+1,r) << endl;
            if(query(mid + 1, r) >= x) {
                lowl = mid;
                R = mid - 1;
            } else {
                L = mid + 1;
            }
        }
        cout << r << ' ' << highl << ' ' << lowl << endl;
        auto &tmp = mp[s[r] - S];
        auto fnd2 = lower_bound(tmp.begin(), tmp.end(), lowl);   // >= fnd2
        auto fnd3 = upper_bound(tmp.begin(), tmp.end(), highl);     // <= fnd3
        if(fnd3 == tmp.begin() || fnd2 == tmp.end()) {
            continue;
        }
        fnd3 = prev(fnd3);
        ans += fnd3 - fnd2 + 1;
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
