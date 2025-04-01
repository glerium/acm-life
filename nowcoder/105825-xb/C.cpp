#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    int q; cin >> q;
    int mi=1e9+10, mx=0;
    set<int> a;
    for(int i=1;i<=q;i++) {
        int k; cin >> k;
        int last = -1;
        for(int j=1;j<=k;j++) {
            int x; cin >> x;
            if(x <= last) {
                cout << "NO" << endl;
                return 0;
            }
            last = x;
            mi = min(mi, x);
            mx = max(mx, x);
            if(a.count(x)) {
                cout << "NO" << endl;
                return 0;
            }
            a.insert(x);
        }
    }
    for(int i=mi;i<=mx;i++) {
        if(!a.count(i)) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}