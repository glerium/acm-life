#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
constexpr ll inf = 0x3f3f3f3f;
constexpr double eps = 1e-8;
template<class T, class... Args>
auto Vec(size_t n, Args... args) {
    if constexpr(sizeof...(args) == 1)
        return vector<T>(n, args...);
    else
        return vector(n, Vec<T>(args...));
}
void solve() {
    int n; cin >> n;
    ll px,py,qx,qy; cin >> px >> py >> qx >> qy;
    vector<ll> a(n+5);
    rep(i,1,n) cin >> a[i];
    double dis = sqrt((px - qx) * (px - qx) + (py - qy) * (py - qy));
    if(n == 1) {
        if(abs(dis - a[1]) <= eps) cout << "Yes" << endl;
        else cout << "No" << endl;
        return;
    }
    ll s = 0; rep(i,1,n) s += a[i];
    ll mx = *max_element(a.begin() + 1, a.begin() + 1 + n);
    if(s - mx <= mx) {
        if(s >= dis - eps && (n > 2 || n == 2 && abs(a[1] - a[2]) <= dis + eps)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    } else {
        if(dis <= s - 2 * mx + eps) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}