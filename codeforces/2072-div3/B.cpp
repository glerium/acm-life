#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int n; cin >> n;
    string s; cin >> s;
    int a=0,b=0;
    rep(i,0,n-1) {
        a += s[i] == '-';
        b += s[i] == '_';
    }
    cout << 1ll * b * (a / 2) * (a - a / 2) << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
