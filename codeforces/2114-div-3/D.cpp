#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
constexpr ll inf = 0x3f3f3f3f;
void solve() {
    int n; cin >> n;
    vector<ll> a(n+5), b(n+5);
    rep(i,1,n) cin >> a[i] >> b[i];
    ll ans = 0;
    ll minx = inf, maxx = 0, miny = inf, maxy = 0;
    rep(i,1,n) {
        minx = min(minx, a[i]);
        maxx = max(maxx, a[i]);
        miny = min(miny, b[i]);
        maxy = max(maxy, b[i]);
    }
    ans = (maxx - minx + 1) * (maxy - miny + 1);
    int ct = 0, x, y;
    rep(i,1,n) {
        if(a[i] == maxx) {
            ct++;
            x = a[i], y = b[i];
        }
    }
    vector<pair<int,int>> vec;
    if(ct == 1) {
        vec.push_back({x, y});
    }
    
    ct = 0;
    rep(i,1,n) {
        if(a[i] == minx) {
            ct++;
            x = a[i], y = b[i];
        }
    }
    if(ct == 1) {
        vec.push_back({x, y});
    }

    ct = 0;
    rep(i,1,n) {
        if(b[i] == miny) {
            ct++;
            x = a[i], y = b[i];
        }
    }
    if(ct == 1) {
        vec.push_back({x, y});
    }
    
    ct = 0;
    rep(i,1,n) {
        if(b[i] == maxy) {
            ct++;
            x = a[i], y = b[i];
        }
    }
    if(ct == 1) {
        vec.push_back({x, y});
    }

    for(auto [x, y] : vec) {
        ll minx = inf, maxx = 0, miny = inf, maxy = 0;
        rep(i,1,n) {
            if(a[i] == x && b[i] == y)
                continue;
            minx = min(minx, a[i]);
            maxx = max(maxx, a[i]);
            miny = min(miny, b[i]);
            maxy = max(maxy, b[i]);
        }
        if((maxx - minx + 1) * (maxy - miny + 1) != n - 1) {
            ans = min(ans, (maxx - minx + 1) * (maxy - miny + 1));
        } else {
            ans = min({ans, (maxx - minx + 2) * (maxy - miny + 1), (maxx - minx + 1) * (maxy - miny + 2)});
        }
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
