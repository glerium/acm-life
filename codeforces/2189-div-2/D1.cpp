#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 1e9+7;
constexpr ll inf = 0x3f3f3f3f;
template<class T, class... Args>
auto Vec(size_t n, Args... args) {
    if constexpr(sizeof...(args) == 1)
        return vector<T>(n, args...);
    else
        return vector(n, Vec<T>(args...));
}
void solve() {
    int n,c; cin >> n >> c;
    string s; cin >> s;
    if(s[0] == '0' || s[n-1] == '0') {
        cout << -1 << endl;
        return;
    }
    int now = 1;
    ll ans = 1;
    rep(i,0,n-2) {
        int cur;
        if(s[i] == '0') {
            cur = now - 1;
        } else {
            cur = 2;
        }
        now++;
        ans = ans * cur % mod;
        int g = gcd(c, cur);
        c /= g;
    }
    if(c == 1) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}