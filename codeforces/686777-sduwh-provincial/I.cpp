#include <bits/stdc++.h>
#define M_PI		3.14159265358979323846
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr long double inf = INFINITY;
void solve() {
    int n,m; cin >> n >> m;
    auto enc = [&](int x, int y) {
        // cerr << (x - 1) * (2 * m) + (y - 1) + 1 << ' ' << 2*n*m << endl;
        return (x - 1) * (2 * m) + (y - 1) + 1;
    };

    auto dis = vector(2*m*n+5, vector(2*m*n+5, inf));
    rep(j,1,2*m) dis[0][enc(1,j)] = dis[enc(1,j)][0] = 1;
    rep(i,1,n) {
        rep(j,1,2*m-1)
            dis[enc(i,j)][enc(i,j+1)] = dis[enc(i,j+1)][enc(i,j)] = M_PI * i / m;
        dis[enc(i,2*m)][enc(i,1)] = dis[enc(i,1)][enc(i,2*m)] = M_PI * i / m;
    }
    rep(j,1,2*m) {
        rep(i,1,n-1) {
            dis[enc(i,j)][enc(i+1,j)] = dis[enc(i+1,j)][enc(i,j)] = 1;
        }
    }

    int tot = 2*n*m;
    rep(i,0,tot) dis[i][i] = 0;
    rep(k,0,tot) rep(i,0,tot) rep(j,0,tot) {
        dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    }
    long double ans = 0;
    rep(i,0,tot) rep(j,i,tot) ans += dis[i][j];
    // rep(i,0,tot) rep(j,i,tot) cerr << i << ' ' << j << ' ' << dis[i][j] << endl;
    cout << fixed << setprecision(10) << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}