#include <bits/stdc++.h>
#define endl '\n'

#define rep(i, o, p) for(int i = o; i <= p; i ++ )

using namespace std;
void solve() {
    vector<long long> a, b;
    int n; 
    cin >> n;
    int x = sqrt(n);
    rep(i, 1, x){
        if(n % i == 0) {
            a.push_back(i);
            b.push_back(n / i);
        }
    }
    for(int i = b.size() - 1; i >= 0 ; i --){
        a.push_back(b[i]);
    }
    unsigned long long ans = 0;
    rep(i, 1, a.size() - 1){
        ans += n / a[i - 1] * (a[i] - a[i - 1]);
    }
    ans += 1;
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}