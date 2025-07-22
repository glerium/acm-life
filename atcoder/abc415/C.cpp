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
    string s; cin >> s;
    s = '0' + s;
    vector<bool> ok(s.size() + 5);
    ok[0] = true;
    rep(i,0,(1<<n)-1) {
        if(s[i] == '1')
            continue;
        rep(j,0,n-1) {
            if((i & (1 << j)) && ok[i ^ (1 << j)]) {
                ok[i] = true;
                break;
            }
        }
    }
    cout << (ok[(1 << n) - 1] ? "Yes" : "No") << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}