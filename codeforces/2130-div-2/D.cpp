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
    int n; cin >> n;
    vector<int> a(n+5);
    rep(i,1,n) cin >> a[i];
    rep(i,1,n) {
        int x = 0, y = 0;
        rep(j,1,n) {
            if((i - j) * (a[i] - a[j]) < 0) {
                x++;
            }
            if((i - j) * ((2 * n - a[i]) - a[j]) < 0) {
                y++;
            }
        }
        if(x >= y) a[i] = 2 * n - a[i];
    }
    // rep(i,1,n) cout << a[i] << ' ';
    // cout << endl;
    int ans = 0;
    rep(i,1,n) rep(j,i+1,n) {
        if((i - j) * (a[i] - a[j]) < 0)
            ans++;
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}