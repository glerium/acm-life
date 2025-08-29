#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll inf = 0x3f3f3f3f3f3f3f3f;
template<class T, class... Args>
auto Vec(size_t n, Args... args) {
    if constexpr(sizeof...(args) == 1)
        return vector<T>(n, args...);
    else
        return vector(n, Vec<T>(args...));
}
void solve() {
    int m,d; cin >> m >> d;
    ll mod = d;
    auto f = Vec<ll>(m+5, 30, -inf);
    ll n = 0;
    ll ans = 0;
    while(m--) {
        char ch; ll x;
        cin >> ch >> x;
        if(ch == 'Q') {
            ll ret = 0;
            int l = n - x + 1;
            int now = n;
            for(int i=29;i>=0;i--) {
                if(now - (1 << i) + 1 >= l) {
                    ret = max(ret, f[now][i]);
                    now -= 1 << i;
                }
            }
            cout << ret << endl;
            ans = ret;
        } else {
            f[++n][0] = (x + ans) % mod;
            rep(i,1,29) {
                if(n - (1 << (i-1)) >= 0)
                    f[n][i] = max(f[n][i-1], f[n-(1<<(i-1))][i-1]);
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}