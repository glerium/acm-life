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
    a[1] = n;
    rep(i,2,n) a[i] = i - 1;
    bool ok = true;
    rep(i,2,n) {
        if(max(a[i], a[i-1]) % i != i-1) {
            ok = false;
            break;
        }
    }
    if(!ok) {
        cout << -1 << endl;
        return;
    }
    rep(i,1,n) cout << a[i] << ' ';
    cout << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
