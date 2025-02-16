#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
template<class T, class... Arg>
auto Vec(size_t n, Arg... arg) {
    if constexpr (sizeof... (arg) == 1) {
        return vector<T>(n, arg...);
    } else {
        return vector(n, Vec<T>(arg...));
    }
}
void solve() {
    int n, d; cin >> n >> d;
    auto x = Vec<int>(n+5, d+5, 0);
    rep(i,1,n) rep(j,1,d) cin >> x[i][j];
    int ans = 0;
    auto check = [&](int x) -> bool {
        int tmp = sqrt(x);
        rep(i, tmp-1, tmp+1) {
            if(i * i == x)    
                return true;
        }
        return false;
    };
    rep(i,1,n) rep(j,i+1,n) {
        int dist2 = 0;
        rep(k, 1, d)
            dist2 += (x[i][k] - x[j][k]) * (x[i][k] - x[j][k]);
        ans += check(dist2);
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
