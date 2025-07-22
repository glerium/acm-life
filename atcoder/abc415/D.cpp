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
struct Rule {
    ll a, b; 
    bool operator<(const Rule& rhs) const {
        return a - b < rhs.a - rhs.b;
    }
};

ll div_glerium(ll a, ll b) {
    return (a + b - 1) / b;
}

void solve() {
    ll n,m; cin >> n >> m;
    vector<Rule> rules(m+5);
    rep(i,1,m) cin >> rules[i].a >> rules[i].b;
    sort(rules.begin() + 1, rules.begin() + 1 + m);
    ll ans = 0;
    rep(i,1,m) {
        ll a = rules[i].a, b = rules[i].b;
        if(n < a) continue;
        ll ct = (n - a) / (a - b) + 1;
        ans += ct;
        n -= ct * (a - b);
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}