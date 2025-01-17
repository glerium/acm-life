#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int n; cin >> n;
    if(n == 1) cout << 1 << endl;
    else if(n <= 4) cout << 2 << endl;
    else {
        int ans = 2;
        int ones = 4;
        while(ones < n) {
            ones++;
            ans++;
            ones *= 2;
        }
        cout << ans << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
