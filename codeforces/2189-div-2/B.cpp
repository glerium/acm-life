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
struct Jump {
    ll a,b,c;
};
void solve() {
    ll n,x; cin >> n >> x;
    vector<Jump> p(n+5);
    rep(i,1,n) cin >> p[i].a >> p[i].b >> p[i].c;
    ll now = 0;
    rep(i,1,n) {
        now += (p[i].b - 1) * p[i].a;
    }
    if(now >= x) {
        cout << 0 << endl;
        return;
    }

    vector<ll> a(n+5);
    rep(i,1,n) {
        a[i] = p[i].b * p[i].a - p[i].c;
    }
    sort(a.begin() + 1, a.begin() + 1 + n, greater<>());
    if(a[1] <= 0) {
        cout << -1 << endl;
    } else {
        cout << (x - now + a[1] - 1) / a[1] << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}