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
ll f[114514][5];
void solve() {
    int n; cin >> n;
    ll ans = 0;
    rep(i,1,4) ans += f[n][i];
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    f[0][0] = 1;
    for(int i=1;i*i<=32768;i++) {
        rep(j,i*i,32768) {
            rep(k,1,4)
                f[j][k] += f[j - i*i][k-1];
        }
    }
    int t; cin>>t;
    while(t--) solve();
    return 0;
}