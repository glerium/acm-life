#include <bits/stdc++.h>
using namespace std;
int t, n, a[1008];
int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        bool yes = false;
        for(int i=1;i<=n;i++) {
            cin >> a[i];
            if(a[i] <= i) yes = true;
        }
        cout << (yes ? "YES" : "NO") << endl;
    }
    return 0;
}