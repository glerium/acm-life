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
    int n,d; cin >> n >> d;
    string a, b; cin >> a >> b;
    a = '0' + a + "   ";
    b = '0' + b + "   ";
    auto f = Vec<int>(n+5, d+5, 0);
    f[0][0] = 1;
    auto iszero = [](char ch) -> bool {
        return ch == '0' || ch == '?';
    };
    auto isone = [](char ch) -> bool {
        return ch == '1' || ch == '?';
    };
    rep(i,0,n-1) rep(k,0,d) {
        int x = i + 1;
        int y = x - d + 2 * k;
        if(iszero(a[x]) && (y < 1 || y > n || iszero(b[y]))) {
            f[i+1][k] += f[i][k];
            f[i+1][k] %= mod;
        }
        if(isone(a[x]) && isone(b[y]) && (1 <= y && y <= n)) {
            f[i+1][k] += f[i][k];
            f[i+1][k] %= mod;
        }
        if(isone(a[x]) && (y < 1 || y > n || iszero(b[y])) && (y+1 < 1 || y+1>n || iszero(b[y+1])) && (y+2<1 || y+2>n || iszero(b[y+2]))) {
            f[i+1][k+1] += f[i][k];
            f[i+1][k+1] %= mod;
        }
    }
    cout << f[n][d] << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--) solve();
    return 0;
}