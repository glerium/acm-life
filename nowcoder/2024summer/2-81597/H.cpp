#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void mov(char ins, int& dx, int& dy) {
    dx = dy = 0;
    if(ins == 'W') dy = 1;
    else if(ins == 'D') dx = 1;
    else if(ins == 'S') dy = -1;
    else if(ins == 'A') dx = -1;
}
void solve() {
    int n,x,y; cin>>n>>x>>y;
    if(x==0 && y==0) {
        cout << (ll)n * (n+1) / 2 << endl;
        return;
    }
    map<pair<int,int>,vector<int>> mp;
    string ins; cin >> ins;
    ins = ' ' + ins;
    pair<int,int> s[n+5];
    s[0] = {0,0};
    for(int i=1;i<=n;i++) {
        s[i] = s[i-1];
        int dx, dy;
        mov(ins[i], dx, dy);
        s[i].first += dx; 
        s[i].second += dy;
        mp[s[i]].push_back(i);
    }
    // for(auto [k,v] : mp) {
    //     cout << k.first << ' ' << k.second << ":\n";
    //     for(auto i : v) cout << i << ' ';
    //     cout << endl;
    // }
    ll ans = 0;
    for(int i=1;i<=n;i++) {
        pair<int,int> target;
        target.first = s[i-1].first + x;
        target.second = s[i-1].second + y;
        auto &v = mp[target];
        // for(auto i : v) cout << ":" << i << endl;
        // cout << i << endl;
        auto got = upper_bound(v.begin(), v.end(), i, less<int>());
        if(got == v.end()) continue;
        else {
            ans += n - *got + 1;
        }
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
