#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int n; cin >> n;
    vector<ll> a(n+5);
    rep(i,1,n) cin >> a[i];
    map<ll,int> ox, oy;
    vector<ll> ans;
    rep(i,1,n) {
        if(a[i] & 1)
            ox[a[i]]++;
        else
            oy[a[i]]++;
    }
    vector<ll> removed;
    function<bool(ll)> check = [&](ll x) -> bool {
        ll a = x / 2, b = x - a;
        // cout << x << ' ' << a << ' ' << b << endl;
        if(a % 2 == 0) swap(a, b);
        assert(a % 2 == 1 && b % 2 == 0);
        if(!oy.count(b) || oy[b] <= 0) {
            return false;
        }else{
            oy[b]--;
            if(oy[b] <= 0)
                oy.erase(b);
            removed.push_back(b);
        }
        if(ox.count(a) && ox[a] > 0) {
            ox[a]--;
            if(ox[a] <= 0)
                ox.erase(a);
            removed.push_back(a);
            return true;
        }else{
            return check(a);
        }
    };

    while(!oy.empty() && !ox.empty()) {
        ll mxy = oy.rbegin()->first;
        // cout << mxy << endl;
        removed.clear();
        if(check(mxy * 2 + 1)) {
            ox[mxy * 2 + 1]++;
        } else {
            for(auto i : removed) {
                if(i & 1) {
                    ox[i]++;
                }else{
                    oy[i]++;
                }
            }
            removed.clear();
            if(check(mxy * 2 - 1)) {
                ox[mxy * 2 - 1]++;
            }else{
                for(auto i : removed) {
                    if(i & 1) {
                        ox[i]++;
                    }else{
                        oy[i]++;
                    }
                }
                oy[mxy]--;
                if(oy[mxy] <= 0)
                    oy.erase(mxy);
                ans.push_back(mxy);
            }
        }
    }
    for(auto &[x, y] : ox) {
        rep(i,1,y)
            ans.push_back(x);
    }
    for(auto &[x, y] : oy) {
        rep(i,1,y)
            ans.push_back(x);
    }
    sort(ans.begin(), ans.end(), greater<ll>());
    cout << ans.size() << endl;
    for(auto i : ans)
        cout << i << ' ';
}
int main() {
    // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
