#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int n,k; cin>>n>>k;
    if(n == 1) cout << k << endl;
    else {
        int a1 = 0;
        while(a1 <= k) {
            a1 = a1 << 1 | 1;
        }
        a1 >>= 1;
        cout << a1 << ' ' << k - a1 << ' ';
        for(int i=3;i<=n;i++) cout << 0 << ' ';
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
