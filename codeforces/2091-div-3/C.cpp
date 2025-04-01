#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int n; cin >> n;
    if(n % 2 == 0)
        cout << -1 << endl;
    else {
        int cur = 1;
        rep(i,1,n) {
            cout << cur << ' ';
            cur += 2;
            if(cur > n)
                cur -= n;
        }
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
