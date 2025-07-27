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
    int a,b,x,y; cin >> a >> b >> x >> y;
    if(a > b) {
        if((a ^ 1) == b)
            cout << y << endl;
        else
            cout << -1 << endl;
    } else {
        ll ans = 0;
        while(a != b) {
            if((a ^ 1) > a && y < x) {
                ans += y;
            } else {
                ans += x;
            }
            a ++;
        }
        cout << ans << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}