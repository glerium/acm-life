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
    int n,q; cin >> n >> q;
    vector<int> a(n+5);
    auto cnt = [&](const vector<int>& vec) -> int {
        int ret = 0;
        rep(i,0,vec.size()-2) {
            ret += (vec[i] != vec[i+1] && vec[i+1] == 1);
        }
        return ret;
    };
    int ans = 0;
    rep(_,1,q) {
        int x; cin >> x;
        vector<int> bef, aft;
        bef.push_back(0);
        aft.push_back(0);
        if(x != 1) {
            bef.push_back(a[x-1]);
            aft.push_back(a[x-1]);
        }
        bef.push_back(a[x]);
        aft.push_back(!a[x]);
        if(x != n) {
            bef.push_back(a[x+1]);
            aft.push_back(a[x+1]);
        }
        a[x] = !a[x];
        bef.push_back(0);
        aft.push_back(0);
        ans += cnt(aft) - cnt(bef);
        cout << ans << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}