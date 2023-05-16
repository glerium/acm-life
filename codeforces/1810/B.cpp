#include <bits/stdc++.h>
using namespace std;
int t, n, a[100], ct;
int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        if(n % 2 == 0) {
            cout << "-1\n";
            continue;
        }
        ct = 0;
        while (n != 1 && ct <= 40) {
            if(((n+1)/2)%2==1) {
                a[++ct] = 1;
                n = (n+1)/2;
            } else {
                a[++ct] = 2;
                n = (n-1)/2;
            }
        }
        if(n==1) {
            cout << ct << endl;
            for(int i=ct;i>=1;i--) cout << a[i] << ' ';
            cout << endl;
        } else cout << -1 << endl;
    }
    return 0;
}