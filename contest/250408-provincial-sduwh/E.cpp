#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
template<class T, class... Args> 
auto Vec(size_t n, Args... args) {
    if constexpr (sizeof...(args) == 1) {
        return vector<T>(n, args...);
    } else {
        return vector(n, Vec<T>(args...));
    }
}
void solve() {
    string s; cin >> s;
    int n = s.size();
    s = ' ' + s;
    int ct[26] = {};
    rep(i,1,n) ct[s[i] - 'a']++;
    rep(i,0,25) {
        if(ct[i] >= 100) {
            cout << string(100, i + 'a') << endl;
            return;
        }
    }
    // n <= 2600
    string r = s;
    reverse(r.begin() + 1, r.end());
    auto f = Vec<int>(n+5, n+5, 0);
    auto fa = Vec<pair<int,int>>(n+5, n+5, make_pair(0, 0));
    rep(i,1,n) {
        rep(j,1,n) {
            if(s[i] == r[j] && f[i][j] < f[i-1][j-1] + 1) {
                f[i][j] = f[i-1][j-1] + 1;
                fa[i][j] = {i-1, j-1};
            }
            if(f[i][j] < f[i][j-1]) {
                f[i][j] = f[i][j-1];
                fa[i][j] = {i, j-1};
            }
            if(f[i][j] < f[i-1][j]) {
                f[i][j] = f[i-1][j];
                fa[i][j] = {i-1, j};
            }
        }
    }
    string ans;
    int x=n, y=n;
    while(x || y) {
        auto &[fx, fy] = fa[x][y];
        if(fx == x - 1 && fy == y - 1) {
            ans += s[x];
        }
        x = fx;
        y = fy;
    }
    if(ans.length() > 100) {
        string nans;
        for(int i=0;i<50;i++) {
            nans += ans[i];
        }
        for(int i=ans.size()-50;i<=ans.size()-1;i++) {
            nans += ans[i];
        }
        cout << nans << endl;
        return;
    }
    cout << ans << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}