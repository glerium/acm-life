#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int a,b,c,d; cin >> a >> b >> c >> d;
    int ans = (b == 0 ? 1 : a % 2);
    ans = ans * c + d;
    cout << (ans % 2 ? "YES":"NO") << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
