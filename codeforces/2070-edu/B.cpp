#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    ll n,x,k; cin >> n >> x >> k;
    string s; cin >> s; s = ' ' + s;
    int tt = -1;
    rep(i,1,n) {
        if(s[i] == 'L') {
            x--;
        }else{
            x++;
        }
        if(x == 0) {
            tt = i;
            break;
        }
    }
    if(tt == -1) cout << 0 << endl;
    else {
        k -= tt;
        tt = -1;
        x = 0;
        rep(i,1,n) {
            if(s[i] == 'L') {
                x--;
            }else{
                x++;
            }
            if(x == 0) {
                tt = i;
                break;
            }
        }
        if(tt == -1) {
            cout << 1 << endl;
        }else{
            cout << 1 + k / tt << endl;
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
