#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while(t--) {
        int n,a,b;
        cin >> n >> a >> b;
        int ans = n / a + bool(n % a);
        if(b < a) ans = min(ans, 1);
        cout << ans << endl;
    }
}