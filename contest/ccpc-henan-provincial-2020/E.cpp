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
    vector<int> a(n+5), b(n+5), w(n+5);
    rep(i,1,n) cin >> a[i] >> b[i] >> w[i];
    int ans = -1;
    unordered_map<int,vector<int>> in,out;
    rep(i,1,n) {
        in[a[i]].push_back(w[i]);
        out[b[i]+1].push_back(w[i]);
    }
    vector<int> tm;
    rep(i,1,n) {
        tm.push_back(a[i]);
        tm.push_back(b[i]+1);
    }
    sort(tm.begin(), tm.end());
    tm.erase(unique(tm.begin(), tm.end()), tm.end());
    int now = 0;
    int ct = 0;
    for(auto i : tm) {
        for(auto j : in[i]) {
            now ^= j;
            ct ++;
        }
        for(auto j : out[i]) {
            now ^= j;
            ct --;
        }
        if(ct >= k)
            ans = max(ans, now);
        // if(ct >= k)
        //     ans = max(ans, now);
        // cerr << i << ' ' << ct << endl;
    }
    if(ct >= k)
        ans = max(ans, now);
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}