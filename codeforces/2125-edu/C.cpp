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
ll solve_(ll x) {
    ll ans = x;
    ans = ans - x / 2 - x / 3 - x / 5 - x / 7 + x / 6 + x / 10 + x / 14 + x / 35 + x / 21 + x / 15
              - x / 30 - x / 42 - x / 70 - x / 105 + x / 210;
    return ans;
}
void solve() {
    ll l, r; cin >> l >> r;
    // cout << solve_(r) << ' ' << solve_(l - 1) << endl;
    cout << solve_(r) - solve_(l - 1) << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
