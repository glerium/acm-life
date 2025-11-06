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
auto f = Vec<ll>(20, 2520, 50, -1);
vector<int> mp(2525, -1);
ll calc(ll x) {
    vector<int> a(1);
    while(x) {
        a.push_back(x % 10);
        x /= 10;
    }
    int n = a.size() - 1;
    auto dfs = [&](auto &&dfs, int pos, int fzlcm, int fmlcm, bool top) -> ll {
        if(pos == 0) {
            if(fmlcm == 0) return 1;
            else return fzlcm % fmlcm == 0;
        }
        if(!top && f[pos][fzlcm][mp[fmlcm]] != -1)
            return f[pos][fzlcm][mp[fmlcm]];
        int lim = top ? a[pos] : 9;
        ll ans = 0;
        rep(i,0,lim) {
            bool ntop = top && a[pos] == i;
            int nfzlcm = (fzlcm * 10 + i) % 2520;
            int nfmlcm = !i ? fmlcm : lcm(fmlcm, i);
            ans += dfs(dfs, pos - 1, nfzlcm, nfmlcm, ntop);
        }
        if(!top) f[pos][fzlcm][mp[fmlcm]] = ans;
        return ans;
    };
    return dfs(dfs, n, 0, 1, true);
}
void solve() {
    ll l, r; cin >> l >> r;
    // cerr << calc(r) - calc(l - 1) << endl;
    cout << calc(r) - calc(l - 1) << endl;
}
void init() {
    int ct = 0;
    rep(i,1,2520) {
        if(2520 % i == 0) {
            mp[i] = ++ct;
        }
    }
}
int main() {
    init();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}