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
    vector<ll> a(n+5);
    rep(i,1,n) cin >> a[i];
    map<int,int> ct;
    rep(i,1,n) ct[a[i]]++;
    ll sm = 0;
    int ctt = 0;
    ll ans = 0;
    for(auto [x,y] : ct) {
        sm += 1ll * x * (y / 2) * 2;
        ctt += y / 2;
    }
    if(ctt > 1) ans = sm;
    vector<int> vec;
    for(auto [x, y] : ct) {
        if(y % 2 == 1) {
            vec.push_back(x);
        }
    }
    for(int i=vec.size()-1; i>0; i--) {
        if(vec[i] - vec[i-1] < sm) {
            ans = max(ans, sm + vec[i] + vec[i-1]);
        }
    }
    for(int i=vec.size()-1; i>=0; i--) {
        if(vec[i] < sm) {
            ans = max(ans, sm + vec[i]);
        }
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}