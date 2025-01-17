#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int l,r; cin >> l >> r;
    int ans = 0;
    for(int i=30;i>=0;i--) {
        if((l&(1<<i)) == (r&(1<<i))) {
            ans += (1 << i) * bool(l & (1 << i));
        } else {
            int x = ans + (1 << i),
                y = ans + (1 << i) - 1,
                z = ans + (1 << i) - 2;
            if(z < l)
                z = ans + (1 << i) + 1;
            cout << x << ' ' << y << ' ' << z << endl;
            return;
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
