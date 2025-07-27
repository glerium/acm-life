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
    vector<int> ct(n+5);
    rep(i,1,n) ct[i] = ct[i-1] + (a[i] == k);
    int mx = *max_element(a.begin(), a.end());
    vector<vector<int>> pos(mx+5);
    rep(i,1,n) {
        pos[a[i]].push_back(i);
    }
    vector<int> b;
    vector<int> f;
    int ctall = ct[n];
    int ans = ctall;
    rep(i,1,mx) {
        if(i == k) continue;
        if(pos[i].empty()) continue;
        b.clear();
        b.push_back(1);
        rep(j,1,pos[i].size()-1) {
            b.push_back(-(ct[pos[i][j]] - ct[pos[i][j-1]]));
            b.push_back(1);
        }
        f.clear();
        f.resize(b.size());
        f[0] = b[0];
        int maxDelta = f[0];
        rep(j,1,b.size()-1) {
            f[j] = max(f[j-1]+b[j], 0);
            maxDelta = max(maxDelta, f[j]);
        }
        ans = max(ans, ctall + maxDelta);
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