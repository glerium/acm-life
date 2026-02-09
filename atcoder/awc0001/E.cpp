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
    int n,k; cin >> n >> k;
    vector<int> a(n+5);
    rep(i,1,n) cin >> a[i];
    multiset<int> st;
    rep(i,1,k) st.insert(a[i]);
    int ans = *prev(st.end()) - *st.begin();
    rep(i,k+1,n) {
        st.erase(st.find(a[i-k]));
        st.insert(a[i]);
        ans = max(ans, *prev(st.end()) - *st.begin());
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}