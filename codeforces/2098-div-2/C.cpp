#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int n; cin >> n;
    vector<int> a(n+5);
    rep(i,1,n) cin >> a[i];
    map<int,int> mp;
    rep(i,1,n) mp[a[i]]++;
    int last = -1;
    bool in = false;
    for(auto [val, ct] : mp) {
        if(val - last != 1)
            in = false;
        if(ct >= 4) {
            cout << "Yes" << endl;
            return;
        }else if(ct >= 2) {
            if(in){
                cout << "Yes" << endl;
                return;
            } else {
                in = true;
            }
        }
        last = val;
    }
    cout << "No" << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
