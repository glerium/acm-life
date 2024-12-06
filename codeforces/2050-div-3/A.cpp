#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int n,m; cin >> n >> m;
    int sum = 0;
    int ans = 0;
    bool ok = true;
    while(n--) {
        string s; cin >> s;
        if(!ok) continue;
        if(sum + s.size() <= m) {
            sum += s.size();
            ans++;
        }else {
            ok = false;
        }
    }
    cout << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
