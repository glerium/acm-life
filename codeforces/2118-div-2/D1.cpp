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
    int n,k; cin >> n >> k;
    vector<ll> p(n+5); rep(i,1,n) cin >> p[i];
    p[n+1] = p[n] + 1;
    vector<ll> d(n+5); rep(i,1,n) cin >> d[i];
    int q; cin >> q;
    vector<ll> a(q+5); rep(i,1,q) cin >> a[i];
    rep(i,1,q) {
        if(a[i] > p[n]) {
            cout << "YES" << endl;
            continue;
        }
        bool dir = true;
        ll tim = 0, pos = a[i];
        int fnd = lower_bound(p.begin() + 1, p.begin() + n + 1, pos) - p.begin();
        if(p[fnd] == pos && d[fnd] % k == 0) {
            dir = !dir;
        }
        set<ll> vis;
        bool yes = false;
        while(true) {
            bool initDir = dir;

            int fnd;
            if(dir) {
                fnd = upper_bound(p.begin(), p.begin() + n + 2, pos) - p.begin();
            } else {
                fnd = lower_bound(p.begin(), p.begin() + n + 2, pos) - p.begin() - 1;
            }
            if(fnd == 0 || fnd == n + 1) {      // yes
                yes = true;
                break;
            }
            ll nexTim = tim + abs(p[fnd] - pos);
            if((nexTim - d[fnd]) % k == 0) {
                dir = !dir;
            }
            if(initDir != dir) {
                if(vis.count(pos * 2 + dir))
                    break;
                vis.insert(pos * 2 + dir);
            }
            pos = p[fnd];
            tim = nexTim;
        }
        cout << (yes ? "YES" : "NO") << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
