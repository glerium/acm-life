#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr ll mod = 998244353;
void solve() {
    int n; cin >> n;
    vector<int> a(n+5);
    rep(i,1,n) cin >> a[i];
    vector<vector<int>> mp(n+5);
    vector<int> ct(n+5);
    int beg = -1;
    rep(i,1,n) {
        ct[a[i]]++;
        if(i == 1) {
            beg = i;
            continue;
        }
        if(a[i] != a[i-1]) {
            mp[a[i-1]].push_back(i - beg);
            beg = i;
        }
    }
    mp[a[n]].push_back(n - beg + 1);
    rep(k,1,n) {
        auto &v = mp[k];
        if(v.size() == 0) {
            continue;
        }
        if(v.size() > 1) {
            cout << "No" << endl;
            return;
        }
        for(auto i : v) {
            if(i % 2 == 0) {
                cout << "No" << endl;
                return;
            }
        }
    }
    rep(k,1,n) {
        int tmp = ct[k] + 1;
        // cout << ":" << tmp << endl;
        while(tmp != 1) {
            if(tmp % 2 == 1) {
                cout << "No" << endl;
                return;
            }
            tmp >>= 1;
        }
    }
    cout << "Yes" << endl;
}
int main() {
    // freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}