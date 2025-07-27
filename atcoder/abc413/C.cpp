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
struct Numbers {
    ll cnt;
    ll x;
};
void solve() {
    int q; cin >> q;
    deque<Numbers> que;
    while(q--) {
        int type; cin >> type;
        if(type == 1) {
            ll c, x; cin >> c >> x;
            que.push_back({c, x});
        } else {
            ll k; cin >> k;
            ll ans = 0;
            while(k) {
                auto now = que.front();
                que.pop_front();
                ll delta = min(k, now.cnt);
                ans += delta * now.x;
                k -= delta;
                now.cnt -= delta;
                if(now.cnt)
                    que.push_front({now.cnt, now.x});
            }
            cout << ans << endl;
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