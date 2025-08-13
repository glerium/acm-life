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
    string s; cin >> s; s = ' ' + s;
    int ct[n+5][2][2] = {};
    vector<int> t(n+5);
    rep(i,1,n) {
        t[i] = t[i-1];
        if(s[i] == '1')
            t[i] = !t[i];
    }
    for(int i=n;i>=0;i--) {
        memcpy(ct[i], ct[i+1], sizeof(ct[i]));
        ct[i][i%2][0] += t[i] == 0;
        ct[i][i%2][1] += t[i] == 1;
    }
    ll ans = 0;
    rep(i,0,n-1) {
        ans += ct[i+1][i%2][t[i]];
        ans += ct[i+1][!(i%2)][!t[i]];
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