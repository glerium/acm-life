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
    set<tuple<int,int,int>> st;
    vector<pair<int,int>> vec;
    string ans;
    vector<int> vx(n+5), vy(n+5);
    auto ok = Vec<bool>(n+5, n+5, true);
    rep(i,1,n*n) {
        int x,y; cin >> x >> y;
        if(!ok[x][y]) {
            putchar('0');
            continue;
        }
        putchar('1');
        vector<pair<int,int>> to;
        for(auto [x0, y0] : vec) {
            int dx = x - x0, dy = y - y0;
            if(dx < 0) dx = -dx, dy = -dy;
            int g = gcd(dx, dy);
            dx /= g, dy /= g;
            for(int xx = x, yy = y; xx <= n && yy <= n && xx >= 1 && yy >= 1; xx += dx, yy += dy) {
                ok[xx][yy] = false;
            }
            for(int xx = x, yy = y; xx <= n && yy <= n && xx >= 1 && yy >= 1; xx -= dx, yy -= dy) {
                ok[xx][yy] = false;
            }
        }
        vec.push_back({x, y});
    }
}
int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}