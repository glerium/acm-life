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
    vector<int> a(8), b(8);
    rep(i,1,6) cin >> a[i];
    rep(i,1,6) cin >> b[i];
    int x,y; cin >> x >> y;
    int ct = 0;
    rep(i,1,6) ct += (a[i] == y) + (b[i] == y);
    if(ct < x) cout << "win" << endl;
    else cout << "lose" << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}