#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int n; cin >> n;
    int a[n+5][n+5];
    vector<array<int,4>> ans;
    for(int i=n;i>=1;i--) {
        ans.push_back({1,i});
        for(int j=1;j<=n;j++) a[i][j] = j;
        ans.push_back({2,i});
        for(int j=1;j<=n;j++) a[j][i] = j;
    }
    int s = 0;
    for(int i=1;i<=n;i++) {
        for(int j=1;j<=n;j++)
            s += a[i][j];
    }
    cout << s << ' ' << 2*n << endl;
    for(auto i : ans) {
        cout << i[0] << ' ' << i[1] << ' ';
        for(int j=1;j<=n;j++) cout << j << ' ';
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
