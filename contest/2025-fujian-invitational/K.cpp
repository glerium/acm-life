#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define endl '\n'
using namespace std;
typedef long long ll;
constexpr ll inf = 0x3f3f3f3f3f3f3f3f;
int main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n; cin >> n;
    vector<vector<pair<int,int>>> a(n+5);
    rep(i,1,n-1) {
        int x,y,z; cin >> x >> y >> z;
        a[x].push_back({y, z});
        a[y].push_back({x, z});
    }
    ll mina = inf, minb = inf;
    vector<pair<ll,bool>> ans(n+5);
    function<void(int,int,ll,bool)> dfs = [&](int x, int fa, ll k, bool pos) {
        if(pos == true) {
            mina = min(mina, k);
        } else {
            minb = min(minb, k);
        }
        ans[x] = {k, pos};
        for(auto [to, val] : a[x]) {
            if(to == fa) continue;
            dfs(to, x, val - k, !pos);
        }
    };
    dfs(1, -1, 0, true);
    // cout << mina << ' ' << minb << endl;
    if(minb >= 2 && -mina+1 <= minb-1) {
        // pos: a+x, !pos: b-x
        // x = minb - 1
        ll x = max(1ll, -mina+1);
        vector<int> anss;
        rep(i,1,n) {
            if(ans[i].second) anss.push_back(x + ans[i].first);
            else anss.push_back(ans[i].first - x);
        }
        for(auto i : anss) {
            if(i > 1e9) {
                cout << "NO" << endl;
                return 0;
            }
        }
        cout << "YES" << endl;
        for(auto i : anss) {
            cout << i << ' ';
        }
        cout << endl;
        // cout << endl;
    }else{
        cout << "NO" << endl;
    }
}