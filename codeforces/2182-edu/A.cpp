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
    int ct5 = 0, ct6 = 0;
    rep(i,1,n-3) {
        if(s.substr(i, 4) == "2025")
            ct5 ++;
        else if(s.substr(i, 4) == "2026")
            ct6 ++;
    }
    int ans = INT_MAX;
    rep(i,1,n-3) {
        int now = 0;
        string tm = "2026";
        rep(j,0,3) {
            now += tm[j] != s[i+j];
        }
        ans = min(ans, now);
    }
    cout << min(ans, ct5) << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}