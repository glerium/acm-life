#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void solve() {
    ll n,k; cin >> n >> k;
    auto yes = [&](vector<ll> v) {
        cout << "YES" << endl;
        cout << v.size() << endl;
        for(auto i : v) cout << i << ' ';
        cout << endl;
    };
    auto no = [&]() {
        cout << "NO" << endl;
    };
    if(k > n) {
        no();
        return;
    }
    if(n / (n / k) == k) {
        yes({n / k});
        return;
    }
    if((n + 1) / 2 < k) {
        no();
        return;
    }
    yes({n-k+1, 1});
}
int main() {
    ios::sync_with_stdio(false);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}