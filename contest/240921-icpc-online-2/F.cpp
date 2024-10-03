#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    ll now = 1500;
    for(int i=1;i<=n;i++) {
        int dlt; cin >> dlt;
        now += dlt;
        if(now >= 4000) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}