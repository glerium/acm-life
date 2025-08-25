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
    string s; cin >> s; s = ' ' + s;
    string t; cin >> t; t = ' ' + t;
    vector<int> f(n+5), pre(n+5);
    rep(i,1,m) {
        int l,r; cin >> l >> r;
        f[l]++; f[r+1]--;
    }
    rep(i,1,n) pre[i] = pre[i-1] + f[i];
    rep(i,1,n) {
        if(pre[i] % 2 == 0) {
            cout << s[i];
        } else {
            cout << t[i];
        }
    }
    cout << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}