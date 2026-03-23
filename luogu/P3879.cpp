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
    map<string, set<int>> mp;
    rep(i,1,n) {
        int ct; cin >> ct;
        rep(j,1,ct) {
            string s; cin >> s;
            mp[s].insert(i);
        }
    }
    int m; cin >> m;
    rep(i,1,m) {
        string s; cin >> s;
        auto &nmp = mp[s];
        for(auto j = nmp.begin(); j != nmp.end(); j++) {
            cout << *j;
            if(j != nmp.end()) cout << ' ';
        }
        cout << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}