#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
template<class T, class... Args> auto Vec(size_t n, Args&&... args) {
    if constexpr(sizeof... (args) == 1) {
        return vector<T>(n, args...);
    }else{
        return vector(n, Vec<T>(args...));
    }
}
void solve() {
    string s; cin >> s;
    int n = s.size();
    s = ' ' + s;
    auto ct = Vec<int>(26, n+5, 0);
    rep(i,1,n) {
        rep(j,0,25) {
            ct[j][i] = ct[j][i-1] + (s[i] == ('a' + j));
        }
    }
    int ans = 0;
    rep(i,2,n) {
        if(ct[s[i] - 'a'][n] - ct[s[i] - 'a'][i] > 0) {
            ans = max(ans, i);
        }
    }
    rep(i,1,n-1) {
        if(ct[s[i] - 'a'][i-1] > 0) {
            ans = max(ans, n-i+1);
        }
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}
