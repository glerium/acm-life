#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int mp[300];
void solve() {
    int n; cin >> n;
    vector<pair<char, int>> ans;
    char st;
    int now;
    for(int i=1;i<=n;i++){
        char ch; int x;
        int chh;
        cin >> ch >> x;
        chh = mp[ch];
        if(i == 1) {
            st = ch;
            now = mp[ch];
            ans.push_back({'Z', x});
        } else {
            if((now + 1) % 4 == chh) {
                ans.push_back({'R', -1});
            }else{
                ans.push_back({'L', -1});
            }
            now = chh;
            ans.push_back({'Z', x});
        }
    }
    cout << ans.size() << ' ' << st << endl;
    for(const auto &[x,y]:ans) {
        if(x == 'R' || x == 'L') {
            cout << x << endl;
        }else{
            cout << x << ' ' << y << endl;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    mp['N'] = 0;
    mp['E'] = 1;
    mp['S'] = 2;
    mp['W'] = 3;
    int t; cin >> t;
    while(t--) solve();
    return 0;
}