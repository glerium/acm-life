#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    for(int i=40;i>=0;i--) {
        if((1ll << i) <= n) {
            cout << (1ll << i) << endl;
            return 0;
        }
    }
}