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
    vector<string> s(n+1);
    rep(i,1,n) cin >> s[i];
    vector<int> ans(n+1);
    rep(i,1,n) {
        rep(j,0,i-1) {
            if(s[i].substr(0, s[j].length()) == s[j]) {
                ans[i] = max(ans[i], ans[j] + 1);
            }
        }
    }
    cout << *max_element(ans.begin(), ans.end()) << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while(t--) solve();
    return 0;
}