#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int n; cin >> n;
    int a[n+5]={}; rep(i,2,n) cin >> a[i];
    int s[n+5]={};
    rep(i,1,n) s[i] = s[i-1] + a[i];
    rep(i,1,n) cout << (100000000 + s[i]) << ' ';
    cout << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
