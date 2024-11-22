#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        ll n, a, b; cin >> n >> a >> b;
        ll x = n * a / b, y = n - 1 - x;
        if(x * b <= a * (x + y))
            cout << x + 1 << endl;
        else
            cout << x << endl;
    }
    return 0;
}
