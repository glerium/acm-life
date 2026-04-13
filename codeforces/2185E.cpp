#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
void solve() {
    int n,m,k; cin >> n >> m >> k;
    vector<int> a(n+5), b(m+5);
    rep(i,1,n) cin >> a[i];
    rep(i,1,m) cin >> b[i];
    string s; cin >> s;
    s = ' ' + s;

    sort(a.begin() + 1, a.begin() + 1 + n);
    sort(b.begin() + 1, b.begin() + 1 + m);

    vector<bool> alive(n+5, true);
    int ct = n;

    map<int,vector<int>> mp;
    rep(i,1,n) {
        if(a[i] < b[1]) {
            mp[b[1] - a[i]].push_back(i);
        } else if(a[i] > b[m]) {
            mp[b[m] - a[i]].push_back(i);
        } else {
            auto pnxt = lower_bound(b.begin() + 1, b.begin() + 1 + m, a[i]);
            assert(pnxt != b.begin() + 1 + m);      // greater than all
            if(*pnxt == a[i]) {          // die at begin
                alive[i] = false;
                ct--;
                continue;
            } else {
                int nxt = *pnxt;
                int bef = *prev(pnxt);
                mp[nxt - a[i]].push_back(i);
                mp[bef - a[i]].push_back(i);
            }
        }
        }

    int now = 0;
    rep(i,1,k) {
        if(s[i] == 'L') now--;
        else now++;
        for (auto j : mp[now]) {
            if(!alive[j]) continue;
            alive[j] = false;
            ct--;
        }
        mp.erase(now);
        cout << ct << ' ';
    }
    cout << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--)
        solve();
    return 0;
}