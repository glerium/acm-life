#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    string a, b; cin >> a >> b;
    int n = a.size();
    a = ' ' + a;
    b = ' ' + b;
    int ans = 0;
    for(int i=1;i<=n;i++) {
        if(a[i] == b[i])
            continue;
        // a[i] != b[i]
        // swap block in a
        if(a[i] == a[i-1]) {
            cout << -1 << endl;
            return;
        }
        ans++;
        int j = i+1;
        while(a[j] != b[i] && j <= n) j++;
        if(j > n) {
            cout << -1 << endl;
            return;
        }
        int j2 = j;
        while(a[j2+1] == a[j2] && j2 < n) j2++;
        // i ... j-1, j ... j2
        char ch1 = a[i], ch2 = 1 - (a[i] - '0') + '0';
        int ct1 = j - i, ct2 = j2 - j + 1;
        rep(k,i,i+ct2-1) a[k] = ch2;
        rep(k,i+ct2,j2) a[k] = ch1;
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
