#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int n,x,y; cin >> n >> x >> y;
    int ct = 0;
    int a[n+5] = {};
    int now = x;
    if(n % 2 == 1) {
        a[now] = 2;
        ct++;
        while(ct < n) {
            now ++;
            if(now > n) now -= n;
            a[now] = ct % 2;
            ct++;
        }
    }else{
        rep(i,1,n) a[i] = i % 2;
        if(a[x] == a[y]) {
            a[x] = 2;
        }
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
