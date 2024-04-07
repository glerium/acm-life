#include <bits/stdc++.h>
using namespace std;
int main() {
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        if(k == n) {
            for(int i=1;i<=n;i++) cout << 1 << ' ';
            cout << endl;
        }else if(k == 1) {
            for(int i=1;i<=n;i++) cout << i << ' ';
            cout << endl;
        }else {
            cout << -1 << endl;
        }
    }
    return 0;
}