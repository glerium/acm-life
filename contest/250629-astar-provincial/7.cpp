#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
void solve() {
    ll n,s; cin >> n >> s;
    vector<int> p(n+5);
    rep(i,1,n) cin >> p[i];
    rep(i,1,n) {
        if(p[i] > s) {
            s = (s + p[i] + 1) / 2;
        }
    }
    cout << s << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}