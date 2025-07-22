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
struct LinearBasis {
    ll p[64];
    void clear() {
        memset(p, 0, sizeof(p));
    }
    void insert(ll x) {
        for(int i = 63; i >= 0; i--) {
            if(!(x >> i)) continue;
            if(!p[i]) {
                p[i] = x;
                break;
            }
            x ^= p[i];
        }
    }
    ll getMax() {
        ll ans = 0;
        for(int i = 63; i >= 0; i--) {
            ans = max(ans, ans ^ p[i]);
        }
        return ans;
    }
} lb;
void solve() {
    int n; cin >> n;
    vector<ll> a(n+5);
    rep(i,1,n) cin >> a[i];
    vector<bool> vis(n+5);
    vector<ll> vec;
    ll ans = 0;
    function<void(int)> dfs = [&](int x) {
        if(x == n + 1) {
            lb.clear();
            for(auto i : vec)
                lb.insert(i);
            ans = max(ans, lb.getMax());
            return;
        }
        if(vis[x - 1]) {
            dfs(x + 1);
        } else {
            if(x - 2 >= 0 && !vis[x - 2]) {
                vis[x] = true;
                vec.push_back(a[x]);
                dfs(x + 1);
                vis[x] = false;
                vec.pop_back();
            } else {
                dfs(x + 1);
                
                vis[x] = true;
                vec.push_back(a[x]);
                dfs(x + 1);
                vis[x] = false;
                vec.pop_back();
            }
        }
    };
    dfs(1);
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}