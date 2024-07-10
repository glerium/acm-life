#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int n,a; cin >> n >> a;
    int t[n+5]={}, done[n+5]={};
    rep(i,1,n) cin >> t[i];
    rep(i,1,n) {
        done[i] = max(done[i-1], t[i]) + a;
        cout << done[i] << endl;
    }
    // cout << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
