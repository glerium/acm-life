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
    int a,b; cin >> a >> b;
    auto calc = [](int x, int y) -> int {
        // cerr << x << ' ' << y << ' ' ;
        int now = 1;
        bool f = true;
        int ans = 0;
        while(true) {
            if(f) {
                if(x < now) break;
                else {
                    x -= now;
                    now *= 2;
                }
            } else {
                if(y < now) break;
                else {
                    y -= now;
                    now *= 2;
                }
            }
            f = !f;
            ans++;
        }
        // cerr << ans << endl;
        return ans;
    };
    cout << max(calc(a, b), calc(b, a)) << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}