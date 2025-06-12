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
    int p,s; cin >> p >> s;
    rep(i,1,5000) {
        rep(j,1,5000/i) {
            int x = 2 * (i + j), y = i * j;
            int g = gcd(x, y);
            x /= g, y /= g;
            if(x == p && y == s) {
                cout << i * j << endl;
                rep(x, 1, i) rep(y, 1, j) {
                    cout << x << ' ' << y << endl;
                }
                return;
            }
        }
    }
    cout << -1 << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
