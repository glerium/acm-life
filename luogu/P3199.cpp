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
    int n,m; cin >> n >> m;
    vector<vector<pair<int,double>>> a(n+5);
    rep(i,1,m) {
        int x,y; double z;
        cin >> x >> y >> z;
        a[x].emplace_back(y, z);
    }
    auto check = [&](double x) -> bool {
        rep(i,1,n) {
            for(auto &[x_, y_] : a[i]) {
                y_ -= x;
            }
        }

        vector<bool> vis(n+5);
        vector<double> dis(n+5);
        vector<int> cnt(n+5);

        queue<int> q;
        rep(i,1,n) {
            q.push(i);
            vis[i] = true;
        }
        while(!q.empty()) {
            int u = q.front(); q.pop();
            vis[u] = 0;
            for(auto [v, d] : a[u]) {
                if(dis[v] > dis[u] + d) {
                    dis[v] = dis[u] + d;
                    cnt[v] = cnt[u] + 1;
                    if(cnt[v] >= n) {
                        rep(i,1,n) {
                            for(auto &[x_, y_] : a[i]) {
                                y_ += x;
                            }
                        }
                        return false;
                    }
                    if(!vis[v]) {
                        q.push(v);
                        vis[v] = true;
                    }
                }
            }
        }
        
        rep(i,1,n) {
            for(auto &[x_, y_] : a[i]) {
                y_ += x;
            }
        }
        return true;
    };

    double l = -1e7, r = 1e7, mid;
    int ct = 0;
    while(++ct <= 100) {
        mid = (l + r) / 2;
        if(check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    cout << fixed << setprecision(8) << mid << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}