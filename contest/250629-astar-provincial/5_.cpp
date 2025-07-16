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
    map<vector<int>,int> mp;
    for(int i=0;i<(1<<n);i++) {
        vector<int> vec;
        for(int j=0;j<n;j++) {
            if((1<<j)&i) {
                vec.push_back(a[j+1]);
            }
        }
        mp[vec]++;
    }
    for(auto &[k,v] : mp) {
        if(v % 2 == 0) {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}
int main() {
    freopen("in.txt", "r", stdin);
    freopen("ans.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}