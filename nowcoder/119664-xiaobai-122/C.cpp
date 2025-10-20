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
    vector<int> a(n+5);
    rep(i,1,n) cin >> a[i];
    int pos = 0, neg = 0, zero = 0;
    rep(i,1,n) {
        if(a[i] > 0) pos++;
        else if(a[i] < 0) neg++;
        else zero++;
    }
    if(zero && pos > m) {
        cout << pos - m << endl;
        return;
    }
    int t = pos + neg;
    if(m > t){
        cout << -1 << '\n';
        return;
    }
    if(neg == 0){
        if(m == pos) cout << 0 << '\n';
        else cout << -1 << '\n';
        return;
    }
    if(m > t - 1){
        cout << -1 << '\n';
        return;
    }
    cout << abs(m - pos) << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}