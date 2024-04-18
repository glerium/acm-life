#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int n,q; cin >> n >> q;
    vector<int> a(n+5);
    for(int i=1;i<=n;i++) cin >> a[i];
    while(q--) {
        int x; cin >> x;
        cout << min(x, a[1]-1) << ' ';
    }
    cout << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
