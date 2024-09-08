#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int n,q; cin>>n>>q;
    string a,b; cin>>a>>b;
    int s1[n+3][26] = {}, s2[n+3][26] = {};
    rep(i,0,n-1) {
        rep(j,0,25) {
            s1[i+1][j] = s1[i][j] + (a[i] == j + 'a');
            s2[i+1][j] = s2[i][j] + (b[i] == j + 'a');
        }
    }
    while(q--) {
        int l,r; cin>>l>>r;
        int delta = 0;
        rep(i,0,25) {
            delta += abs(s1[r][i] - s1[l-1][i] - (s2[r][i] - s2[l-1][i]));
        }
        cout << delta / 2 << endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
