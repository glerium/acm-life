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
    int n,m; cin >> n >> m;
    vector<int> a(n);
    rep(i,0,n-1) cin >> a[i];
    int init = 0;
    for(int i=n-1;i>=0;i--) {
        init = init * 2 + a[i];
    }
    vector<vector<int>> g(n);
    rep(i,0,n-1) g[i].push_back(i);
    rep(i,1,m) {
        int x,y; cin >> x >> y;
        x--; y--;
        g[x].push_back(y);
    }
    int ans = INT_MAX, ansct = 114514;
    rep(i,0,(1<<n)-1) {
        int now = init;
        rep(j,0,n-1) {
            if(i & (1 << j)) {
                for(auto k : g[j]) {
                    now ^= 1 << k;
                }
            }
        }
        if(now) continue;
        int pct = __builtin_popcount(i);
        if(pct < ansct || (pct == ansct && i < ans)) {
            ans = i;
            ansct = pct;
        }
    }
    if(ansct == 114514) cout << -1 << endl;
    else {
        rep(i,0,n-1) {
            if(ans & (1 << i)) {
                cout << i + 1 << ' ';
            }
        }
        cout << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}