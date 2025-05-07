#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
struct Item {
    int id;
    int x;
    int y;
};
void solve() {
    int n; cin >> n;
    Item a[n+5] = {};
    rep(i,1,n) cin >> a[i].x;
    rep(i,1,n) cin >> a[i].y;
    int lsame = 0;
    rep(i,1,n) {
        if(a[i].x == a[i].y) {
            lsame = i;
        }
    }
    vector<pair<int,int>> ans;
    map<int,int> mp;
    rep(i,1,n) mp[a[i].y] = i;
    auto doswap = [&](int x, int y) {
        ans.emplace_back(x, y);
        swap(a[x], a[y]);
        mp[a[x].y] = x;
        mp[a[y].y] = y;
    };
    if(lsame && lsame != (n+1)/2) {
        doswap(lsame, (n+1)/2);
    }
    rep(i,1,n/2) {
        if(a[n+1-i].y == a[i].x) continue;
        doswap(n+1-i, mp[a[i].x]);
    }
    bool ok = true;
    rep(i,1,n) {
        if(a[i].x != a[n+1-i].y) {
            ok = false;
            break;
        }
    }
    if(!ok) {
        cout << -1 << endl;
        return;
    }
    cout << ans.size() << endl;
    for(auto &[x, y] : ans) {
        cout << x << " " << y << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
