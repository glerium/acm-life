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
    string s; cin >> s;
    s = ' ' + s;
    auto f = Vec<int>(n+5, n+5, inf);
    rep(i,1,n) f[i][i] = 1;
    // f[i][j] = f[i][j-1] + 1
    // f[i][j] = f[i][k] + f[k+1][j-1] if s[k] == s[j]
    function<int(int,int)> dp = [&](int i, int j) -> int {
        if(f[i][j] != inf) return f[i][j];
        if(i > j) return f[i][j] = 0;
        if(i == j) return f[i][j] = 1;
        f[i][j] = min(f[i][j], dp(i, j-1) + 1);
        rep(k,1,j-1) {
            if(s[k] == s[j])
                f[i][j] = min(f[i][j], dp(i, k) + dp(k+1, j-1));
        }
        return f[i][j];
    };
    dp(1,n);
    // rep(i,1,n) {
    //     rep(j,1,n)
    //         cout << f[i][j] << '\t';
    //     cout << endl;
    // }
    cout << f[1][n] << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}