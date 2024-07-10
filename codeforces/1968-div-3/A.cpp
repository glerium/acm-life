#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
int gcd(int x,int y) {
    return !y?x:gcd(y,x%y);
}
void solve() {
    int x,y; cin >> x;
    int ans=1;
    for(int i=1;i<x;i++) {
        if(gcd(x,i)+i > gcd(x,ans)+ans) {
            ans = i;
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
