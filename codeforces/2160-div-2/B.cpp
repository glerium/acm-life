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
    vector<ll> b(n+5);
    rep(i,1,n) cin >> b[i];
    vector<int> a(n+5);
    int now = 0;
    vector<int> pos(n+5);
    rep(i,1,n) {
        ll delta = b[i] - b[i-1];
        if(delta == i) {
            a[i] = i;
        } else {
            a[i] = a[i - delta];
        }
    }
    rep(i,1,n) {
        cout << a[i] << ' ';
    }
    cout << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}