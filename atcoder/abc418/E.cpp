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
    vector<int> x(n+5), y(n+5);
    rep(i,1,n) cin >> x[i] >> y[i];
    vector<pair<int,int>> mp, mp2;
    rep(i,1,n) {
        rep(j,i+1,n) {
            int dx = x[i] - x[j],
                dy = y[i] - y[j];
            if(dx == 0) dy = 1;
            else if(dy == 0) dx = 1;
            if(dx < 0) {
                dx = -dx;
                dy = -dy;
            }
            int g = gcd(dx, dy);
            dx /= g;
            dy /= g;
            mp.push_back({dx,dy});
            mp2.push_back({x[i] + x[j], y[i] + y[j]});
        }
    }
    ll ans = 0;
    auto getPairs = [&](vector<pair<int,int>> &vec) -> ll {
        sort(vec.begin(), vec.end());
        ll ans = 0;
        int idx = 0;
        while(idx < vec.size()) {
            int j = idx;
            while(j < vec.size() && vec[j] == vec[idx]) j++;
            int len = j - idx;
            ans += 1ll * len * (len - 1) / 2;
            idx = j;
        }
        return ans;
    };
    ans += getPairs(mp);
    ans -= getPairs(mp2);
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}