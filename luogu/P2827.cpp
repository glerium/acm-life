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
    int n,m,q,u,v,t; cin >> n >> m >> q >> u >> v >> t;
    vector<int> a(n+5);
    rep(i,1,n) cin >> a[i];
    vector<queue<ll>> que(3);
    sort(a.begin() + 1, a.begin() + 1 + n, greater<>());
    rep(i,1,n) que[0].push(a[i]);
    ll offset = 0;
    rep(i,1,m) {
        ll mxi = -1, mx = LLONG_MIN;
        rep(j,0,2) {
            if(!que[j].empty() && mx < que[j].front()) {
                mx = que[j].front();
                mxi = j;
            }
        }
        ll now = que[mxi].front() + offset;
        if(i % t == 0) {
            cout << now << ' ';
        }
        que[mxi].pop();
        ll now1 = (now * u / v - q) - offset;
        ll now2 = (now - now * u / v - q) - offset;
        offset += q;
        que[1].push(now1);
        que[2].push(now2);
    }
    cout << endl;
    vector<ll> ans;
    int now = 0;
    while(!que[0].empty() || !que[1].empty() || !que[2].empty()) {
        int mxi = -1, mx = INT_MIN;
        rep(i,0,2) {
            if(que[i].empty()) continue;
            if(que[i].front() > mx) {
                mx = que[i].front();
                mxi = i;
            }
        }
        if(++now % t == 0)
            ans.push_back(mx + offset);
        que[mxi].pop();
    }
    for(auto i : ans) cout << i << ' ';
    cout << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}