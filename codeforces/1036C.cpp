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

// 题意：求[l,r]内有不超过3个非零数位的数字个数
auto f = Vec<ll>(20, 5, -1);    // 前i位，有j个非零数字
ll calc(ll x) {
    vector<int> a(20);
    int ct = 0;
    while(x) {
        a[++ct] = x % 10;
        x /= 10;
    }

    auto dfs = [&](auto &&dfs, int pos, int k, bool top) -> ll {
        if(pos == 0) return 1;
        if(!top && f[pos][k] != -1) return f[pos][k];
        int lim = top ? a[pos] : 9;
        ll ans = 0;
        rep(i,0,lim) {
            int ntop = top && a[pos] == i;
            if(i == 0) ans += dfs(dfs, pos - 1, k, ntop);
            else if(k != 3) ans += dfs(dfs, pos - 1, k + 1, ntop);
        }
        if(!top) f[pos][k] = ans;
        return ans;
    };

    return dfs(dfs, ct, 0, true);
}
void solve() {
    ll l,r; cin >> l >> r;
    cout << calc(r) - calc(l-1) << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}