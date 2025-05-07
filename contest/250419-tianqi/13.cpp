#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
template<class T, class... Args>
auto Vec(size_t n, Args... args) {
    if constexpr (sizeof...(args) == 1) {
        return vector<T>(n, args...);
    }else{
        return vector(n, Vec<T>(args...));
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int b,n,m,q; cin >> b >> n >> m >> q;
    auto d = Vec<int>(n+5, n+5, 0x3f3f3f3f);
    auto h = Vec<int>(n+5, n+5, 0);
    rep(i,1,n) d[i][i] = 0;
    rep(i,1,m) {
        int x,y,z,w; cin >> x >> y >> z >> w;
        d[x][y] = d[y][x] = z;
        h[x][y] = h[y][x] = w;
    }
    rep(k,1,n) {
        rep(i,1,n) {
            rep(j,1,n) {
                if(d[i][k] + d[k][j] < d[i][j] || d[i][k] + d[k][j] == d[i][j] && h[i][k] + h[k][j] > h[i][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                    h[i][j] = h[i][k] + h[k][j];
                }
            }
        }
    }
    rep(_,1,q) {
        int x; cin >> x;
        vector<pair<int,int>> vec;
        rep(i,1,n) {
            if(i == x) continue;
            if(d[x][i] <= b) {
                vec.push_back({i, h[x][i]});
            }
        }
        if(vec.size()) {
            for(int i=0;i<vec.size();i++) cout << vec[i].first << " \n"[i == vec.size() - 1];
            int mx = 0;
            for(auto [x, y] : vec)
                mx = max(mx, y);
            vector<int> ans2;
            for(auto [x, y] : vec) {
                if(y == mx)
                    ans2.push_back(x);
            }
            for(int i=0;i<ans2.size();i++) cout << ans2[i] << " \n"[i == ans2.size() - 1];
        } else {
            cout << "T_T" << endl;
        }
    }
}