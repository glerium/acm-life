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
    vector<int> a(n+5), b(n+5);
    rep(i,1,n) cin >> a[i];
    rep(i,1,n) cin >> b[i];
    vector<pair<int,int>> ans;
    rep(i,1,n) {
        if(a[i] > b[i]) {
            swap(a[i], b[i]);
            ans.emplace_back(3, i);
        }
    }
    rep(i,1,n) rep(j,1,n-1) {
        if(a[j] > a[j+1]) {
            swap(a[j], a[j+1]);
            ans.emplace_back(1, j);
        }
    }
    rep(i,1,n) rep(j,1,n-1) {
        if(b[j] > b[j+1]) {
            swap(b[j], b[j+1]);
            ans.emplace_back(2, j);
        }
    }
    cout << ans.size() << endl;
    for(auto [x, y] : ans) cout << x << ' ' << y << endl;
    // rep(i,1,n) cout << a[i] << ' ';
    // cout << endl;
    // rep(i,1,n) cout << b[i] << ' ';
    // cout << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
