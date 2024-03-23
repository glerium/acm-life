#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int t; cin >> t;
    while(t--) {
        ll a, b, m; cin >> a >> b >> m;
        ll ans = m / a + 1 + m / b + 1;
        cout << ans << endl;
    }
    return 0;
}