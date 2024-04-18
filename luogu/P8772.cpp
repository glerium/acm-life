#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
int n;
ll a[maxn];
int main() {
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
    ll ans = 0, sum = 0;
    for(int i=1;i<=n;i++) sum += a[i];
    for(int i=1;i<=n;i++) ans += a[i] * (sum - a[i]);
    cout << ans / 2 << endl;
    return 0;
}