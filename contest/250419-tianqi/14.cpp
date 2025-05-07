#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
template<class T, class... Args>
auto Vec(size_t n, Args... args) {
    if constexpr (sizeof...(args) == 1) {
        return vector<T>(n, args...);
    }else{
        return vector(n, Vec<T>(args...));
    }
}
inline ll f(ll x) {
    return x * (x+1) / 2;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m; cin >> n >> m;
    auto v = Vec<ll>(n+5, m+5, 0);
    rep(i,1,n) rep(j,1,m) cin >> v[i][j];
    auto a = Vec<ll>(n+5, m+5, 0);
    rep(i,0,n) rep(j,0,m) {
        a[i][j] = max(i, j);
    }
    auto s = Vec<ll>(n+5, m+5, 0);
    rep(i,1,n) s[i][0] = s[i-1][0] + a[i][0];
    rep(j,1,m) s[0][j] = s[0][j-1] + a[0][j];
    rep(i,1,n) rep(j,1,m) {
        s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + a[i][j];
    }
    // ll ans = 0;
    rep(i,1,n) rep(j,1,m) {
        ll ct = s[i-1][j-1] + s[n-i][j-1] + s[i-1][m-j] + s[n-i][m-j];
        ct -= f(i-1) + f(j-1) + f(n-i) + f(m-j);
        cout << ct * v[i][j] << " \n"[j == m];
    }
    // cout << ct << endl;
}