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
    vector<set<int>> a(509);
    int ans = 0;
    rep(i,1,n) rep(j,1,m) {
        int x; cin >> x;
        if(x == min(i, j)) {
            ans++;
            continue;
        }
        a[x].insert(min(i, j));
    }

    int delta = 0;
    rep(i,1,500) {
        for(auto j : a[i]) {
            if(!a[j].empty())
                delta = max(delta, 1);
            if(a[j].count(i))
                delta = max(delta, 2);
        }
    }
    cout << ans + delta << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}