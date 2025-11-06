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
    auto a = Vec<int>(n+5, 3, 0);
    rep(i,1,n) cin >> a[i][0] >> a[i][1] >> a[i][2];
    ll ans = 0;
    vector<int> ct(3), sel(n+5);
    rep(i,1,n) {
        int mx = -1, mxi;
        rep(j,0,2) {
            if(a[i][j] > mx) {
                mx = a[i][j];
                mxi = j;
            }
        }
        ct[mxi]++;
        sel[i] = mxi;
        ans += mx;
    }
    rep(j,0,2) {
        if(ct[j] <= n / 2) continue;
        vector<int> vec;
        rep(i,1,n) {
            if(sel[i] != j) continue;
            int mx = max({a[i][0], a[i][1], a[i][2]});
            int mi = min({a[i][0], a[i][1], a[i][2]});
            int mid = a[i][0] + a[i][1] + a[i][2] - mx - mi;
            vec.push_back(mx - mid);
        }
        sort(vec.begin(), vec.end());
        rep(i,0,ct[j] - n / 2 - 1) {
            ans -= vec[i];
        }
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