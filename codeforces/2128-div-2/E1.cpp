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
    int n,k; cin >> n >> k;
    vector<int> a(n+5);
    rep(i,1,n) cin >> a[i];
    int l=1, r=n, mid, ans=-1;
    auto check = [&](int x, pair<int,int>& interval) -> bool {
        vector<int> b(n+5);
        rep(i,1,n) {
            if(a[i] >= x)
                b[i] = 1;
            else
                b[i] = -1;
        }
        vector<int> s(n+5);
        rep(i,1,n) s[i] = s[i-1] + b[i];
        vector<int> f(n+5, -inf);
        vector<int> start(n+5);
        f[k] = s[k];
        int ans = f[k];
        start[k] = 1;
        if(ans >= 0) {
            interval = {1, k};
            return true;
        }
        rep(i,k+1,n) {
            if(f[i-1]+b[i] > s[i] - s[i-k]) {
                start[i] = start[i-1];
                f[i] = f[i-1] + b[i];
            } else {
                start[i] = i - k + 1;
                f[i] = s[i] - s[i-k];
            }
            ans = max(ans, f[i]);
            if(ans >= 0) {
                interval = {start[i], i};
                return true;
            }
        }
        return false;
    };
    pair<int,int> ansp;
    while(l <= r) {
        mid = (l + r) >> 1;
        if(check(mid, ansp)) {
            ans = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << ans << ' ' << ansp.first << ' ' << ansp.second << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}