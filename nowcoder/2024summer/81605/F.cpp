#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
pair<int,int> operator+(const pair<int,int> lhs, const pair<int,int> rhs) {
    return make_pair(lhs.first + rhs.first, lhs.second + rhs.second);
}
pair<int,int> operator-(const pair<int,int> lhs, const pair<int,int> rhs) {
    return make_pair(lhs.first - rhs.first, lhs.second - rhs.second);
}
void solve() {
    int n; cin >> n;
    bool f[n+1][n+1] = {};
    vector<pair<int,int>> vec;
    rep(i,1,n*n) {
        int x,y; cin >> x >> y;
        if(!f[x][y]) {
            cout << 1;
            f[x][y] = true;
            for(auto [u,v] : vec) {
                auto dt = make_pair(x-u, y-v);
                if(!(x-u)) {
                    dt.first = 0;
                    dt.second = 1;
                } else {
                    int tt = gcd(x-u, y-v);
                    dt.first /= tt; dt.second /= tt;
                }
                auto now = make_pair(x, y);
                while(now.first >= 1 && now.first <= n && now.second >= 1 && now.second <= n) {
                    // cout << ":" << now.first << ' ' << now.second << endl;
                    f[now.first][now.second] = true;
                    now = now + dt;
                }
                now = make_pair(x, y);
                while(now.first >= 1 && now.first <= n && now.second >= 1 && now.second <= n) {
                    // cout << ":" << now.first << ' ' << now.second << endl;
                    f[now.first][now.second] = true;
                    now = now - dt;
                }
            }
            vec.push_back({x,y});
        } else {
            cout << 0;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}
