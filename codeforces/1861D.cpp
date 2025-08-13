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
    int n; ll x; cin >> n >> x;
    ll target = 1;
    rep(i,1,n-1) target *= 10;
    set<ll> st;
    queue<pair<ll,int>> q;
    q.push({x,0});
    while(!q.empty()) {
        auto [now, step] = q.front();
        q.pop();
        if(now >= target) {
            cout << step << endl;
            return;
        }
        auto tmp = now;
        while(tmp) {
            int x = tmp % 10;
            tmp /= 10;
            if(st.count(x * now)) continue;
            st.insert(x * now);
            q.push({x * now, step + 1});
        }
    }
    cout << -1 << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}