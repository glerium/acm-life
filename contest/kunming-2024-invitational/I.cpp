#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
using ll = long long;
void solve() {
    string s; cin >> s;
    int ls = s.size();
    char now = s[0]; 
    int cnt = 1;
    vector< pair<char, int> > mp;
    rep(i, 1, ls - 1) {
        if(now == s[i]) cnt ++; 
        else {
            mp.push_back({now, cnt});
            now = s[i];
            cnt = 1;
        }
    }
    mp.push_back({now, cnt});
    if(mp.size() == 1) {
        cout << mp[0].second / 2 << '\n';
        return ;
    }
    if(mp[0].first == mp[mp.size() - 1].first){
        mp[0].second += mp[mp.size() - 1].second;
        mp.pop_back();
    }
    ll ans = 0, flag = 0;
    for(auto [x, y] : mp) {
      //  cout << x << " " << y << '\n';
        ans += y / 2;
        if(y % 2 == 0) flag = 1;
    }
    cout << ans - flag << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--)
        solve();
}