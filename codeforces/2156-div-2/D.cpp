#include <bits/stdc++.h>
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
int query(int i, int x) {
    cout << "? " << i << ' ' << x << endl;
    int ret; cin >> ret;
    return ret;
}
void answer(int x) {
    cout << "! " << x << endl;
}
void solve() {
    int n; cin >> n;
    vector<int> now;
    rep(i,1,n-1) now.push_back(i);
    int ans = 0;
    rep(i,0,30) {
        int ct = 0;
        vector<int> one,zero;
        for(auto j : now) {
            int tmp = query(j, 1 << i);
            ct += tmp;
            if(tmp) one.push_back(j);
            else zero.push_back(j);
        }
        int realct = 0;
        rep(j,1,n) {
            if((j & ((1 << i) - 1)) != ans) continue;
            realct += (bool)(j & (1 << i));
        }
        if(ct == realct) {      // ans & (1 << i) == 0
            now = zero;
        } else {
            now = one;
            ans ^= 1 << i;
        }
    }
    // cout << ans << endl;
    answer(ans);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}