#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while(t--) {
        int a,b,c;
        cin >> a >> b >> c;
        if(a * 2 + b != (a + b + c - 1)) {
            cout << -1 << endl;
            continue;
        }
        int ans = log2(a + 1);
        if((1 << ans) - 1 < a) ans++;
        int ones = 
    }
}