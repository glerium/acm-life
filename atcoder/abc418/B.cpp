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
    string s; cin >> s;
    s = ' ' + s;
    double ans = 0;
    int n = s.size();
    rep(i,1,n) rep(j,i,n) {
        int len = j - i + 1;
        if(len < 3) continue;
        if(s[i] != 't' || s[j] != 't') continue;
        int ct = 0;
        rep(k,i,j) ct += s[k] == 't';
        ans = max(ans, 1.0 * (ct - 2) / (len - 2));
    }
    cout << fixed << setprecision(17) << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}