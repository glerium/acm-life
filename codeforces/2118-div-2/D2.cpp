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
ll domod(ll x, ll k) {
    return ((x - k) % k + k) % k;
}
void solve() {
    ll n,k; cin >> n >> k;
    vector<ll> p(n+5);
    rep(i,1,n) cin >> p[i];
    vector<ll> d(n+5);
    rep(i,1,n) cin >> d[i];
    int q; cin >> q;
    map<ll,vector<ll>> mp1, mp2;
    rep(i,1,n) {
        mp1[(((p[i] - d[i]) % k) + k) % k].push_back(p[i]);
        mp2[(p[i] + d[i]) % k].push_back(p[i]);
    }
    map<pair<ll,bool>,bool> ans;
    while(q--) {
        ll x; cin >> x;
        bool dir = true;
        ll pos = x;
        ll tim = 0;
        set<pair<ll,bool>> vec;
        // find first red light
        auto &mpItem = mp1[pos % k];
        int nowAns = -1;
        auto fnd = lower_bound(mpItem.begin(), mpItem.end(), x);
        if(fnd == mpItem.end()) {
            cout << "YES" << endl;
            continue;
        } else {
            tim += abs(pos - *fnd);
            pos = *fnd;
            dir = !dir;
        }
        
        while(true) {
            if(ans.count({pos, dir})) {
                nowAns = ans[{pos, dir}];
                break;
            }
            if(vec.count({pos, dir})) {
                nowAns = false;
                break;
            }
            vec.insert({pos, dir});
            if(dir) {
                auto &mpItem = mp1[domod(pos - tim, k)];
                auto fnd = upper_bound(mpItem.begin(), mpItem.end(), pos);
                if(fnd == mpItem.end()) {
                    nowAns = true;
                    break;
                } else {
                    tim += abs(pos - *fnd);
                    pos = *fnd;
                    dir = !dir;
                }
            } else {
                auto &mpItem = mp2[domod(pos + tim, k)];
                auto fnd = lower_bound(mpItem.begin(), mpItem.end(), pos);
                if(fnd == mpItem.begin()) {
                    nowAns = true;
                    break;
                } else {
                    fnd = prev(fnd);
                    tim += abs(pos - *fnd);
                    pos = *fnd;
                    dir = !dir;
                }
            }
        }
        for(auto [x, y] : vec)
            ans[{x, y}] = nowAns;
        assert(nowAns != -1);
        if(nowAns) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}