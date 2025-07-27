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
    vector<ll> a(n+5), b(n+5);
    rep(i,1,n) cin >> a[i];
    rep(i,1,n) cin >> b[i];
    sort(a.begin() + 1, a.begin() + n + 1);
    multiset<int> st;
    rep(i,1,n) st.insert(b[i]);
    ll ans = 0;
    rep(i,1,n) {
        auto fnd = st.lower_bound(m - a[i]);
        if(fnd != st.end()) {
            ans += (a[i] + *fnd) % m;
            st.erase(fnd);
        } else {
            ans += (a[i] + *st.begin()) % m;
            st.erase(st.begin());
        }
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