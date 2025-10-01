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
    int n,L; cin >> n >> L;
    vector<double> a(n+5), s(n+5);
    rep(i,1,n) cin >> a[i];
    rep(i,1,n) s[i] = s[i-1] + a[i];
    auto check = [&](double x) -> bool {
        vector<double> f(n+5);
        f[0] = inf;
        rep(i,1,n) f[i] = min(f[i-1], s[i - 1] - x * (i - 1));
        rep(r,1,n) {
            int lmx = r - L + 1;
            if(lmx <= 0) continue;
            double target = s[r] - x * r;
            double mi = f[lmx];
            if(mi <= target)
                return true;
        }
        return false;
    };
    double l = -1e4, r = 1e4, mid;
    int ct = 0;
    while(++ct <= 100) {
        mid = (l + r) / 2;
        if(check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << fixed << setprecision(5) << mid << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}