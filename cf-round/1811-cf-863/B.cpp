#include <bits/stdc++.h>
using namespace std;
int t, n, xa, ya, xb, yb;
int main() {
    cin >> t;
    while(t--) {
        cin >> n >> xa >> ya >> xb >> yb;
        int ima = min(min(n-xa,xa-1),min(n-ya,ya-1));
        int nxt = min(min(n-xb,xb-1),min(n-yb,yb-1));
        cout << abs(ima-nxt) << endl;
    }
    return 0;
}