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
    int a; ll n; cin >> a >> n;
    ll ans = 0;
    rep(i,1,1e6) {
        ll tmp = i, now = i;
        while(tmp) {
            now = now * 10 + tmp % 10;
            tmp /= 10;
        }
        if(now < 1 || now > n) continue;
        ll now_ = now;
        string s;
        while(now) {
            s += '0' + (now % a);
            now /= a;
        }
        if(s == string(s.rbegin(), s.rend())) {
            ans += now_;
        }
    }
    
    rep(i,1,1e6) {
        ll tmp = i, now = i;
        bool first = true;
        while(tmp) {
            if(!first) now = now * 10 + tmp % 10;
            first = false;
            tmp /= 10;
        }
        if(now < 1 || now > n) continue;
        ll now_ = now;
        string s;
        while(now) {
            s += '0' + (now % a);
            now /= a;
        }
        if(s == string(s.rbegin(), s.rend())) {
            ans += now_;
        }
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}