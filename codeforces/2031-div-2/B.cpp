#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int a[n+5] = {};
        for(int i=1;i<=n;i++)   cin >> a[i];
        for(int i=1;i<=n-1;i++) {
            if(a[i] > a[i+1] and (a[i] - a[i+1] == 1))
                swap(a[i], a[i+1]);
        }
        bool ok = true;
        for(int i=1;i<=n;i++)
            if(a[i] != i)
                ok = false;
        cout << (ok ? "YES" : "NO") << endl;
    }
}