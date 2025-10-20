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
    sort(a.begin()+1, a.begin()+1+n);
    vector<int> b = {0};
    rep(i,1,k) b.push_back(a[i]);
    int ans = 114514;
    ans = min(ans, b[k] - b[(k+1)/2]);
    b.clear();
    b.push_back(0);
    rep(i,n-k+1,n) b.push_back(a[i]);
    ans = min(ans, b[k] - b[(k+1)/2]);
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}