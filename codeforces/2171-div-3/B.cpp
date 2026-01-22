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
    rep(i,2,n-1) if(a[i] == -1) a[i] = 0;
    int ans = abs(a[1] - a[n]);
    if(a[1] == -1 && a[n] != -1) {
        a[1] = a[n];
        ans = 0;
    } else if(a[1] != -1 && a[n] == -1) {
        a[n] = a[1];
        ans = 0;
    } else if(a[1] == -1 && a[n] == -1) {
        a[1] = a[n] = 0;
        ans = 0;
    }
    cout << ans << endl;
    rep(i,1,n) cout << a[i] << ' ';
    cout << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}