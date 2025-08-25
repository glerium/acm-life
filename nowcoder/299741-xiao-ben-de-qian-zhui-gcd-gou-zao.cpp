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
    int n,m,x; cin >> n >> m >> x;
    bool ok = false;
    vector<pair<int,int>> vec;
    function<void(int,int,int)> dfs = [&](int now, int s, int idx) {
        // s = 1 ... idx - 1
        if(s > x) return;

        // last to idx, and to change at next
        rep(i,idx,n-1) {
            rep(j,1,now-1) {
                if(now % j != 0) continue;
                vec.push_back({i - idx + 1, now});
                dfs(j, s + (i - idx + 1) * now, i + 1);
                if(ok) return;
                vec.pop_back();
            }
        }

        // till the end
        if(s + (n - idx + 1) * now == x) {
            vec.push_back({n - idx + 1, now});
            for(auto [i, j] : vec)
                rep(k,1,i)
                    cout << j << ' ';
            cout << endl;
            ok = true;
        }
    };
    rep(i,1,m) {
        if(ok) break;
        vec.clear();
        dfs(i, 0, 1);
    }
    if(!ok) cout << -1 << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}