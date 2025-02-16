#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int n; cin >> n;
    if(n <= 4) cout << -1 << endl;
    else {
        vector<int> ans;
        for(int i=1;i<=n;i+=2) {
            if(i == 5) continue;
            ans.push_back(i);
        }
        ans.push_back(5);
        ans.push_back(4);
        for(int i=2;i<=n;i+=2) {
            if(i == 4) continue;
            ans.push_back(i);
        }
        for(auto i : ans)
            cout << i << ' ';
        cout << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
