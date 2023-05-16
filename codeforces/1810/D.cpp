#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
int main() {
    // freopen("out.txt", "w", stdout);
    cin >> t;
    while(t--) {
        int q; cin >> q;
        ll mi=1, ma=LONG_LONG_MAX;
        int op;
        ll a, b, n;
        while(q--) {
            cin >> op;
            if(op == 1) {
                cin >> a >> b >> n;
                ll new_mi, new_ma;
                if(n != 1) {
                    new_mi = (a-b)*(n-2)+a+1,
                    new_ma = (a-b)*(n-1)+a;
                } else {
                    new_mi = 1;
                    new_ma = a;
                }
                if(new_ma < mi || new_mi > ma) cout << 0 << ' ';
                else {
                    ma = min(ma, new_ma);
                    mi = max(mi, new_mi);
                    cout << 1 << ' ';
                    // cout << '(' << mi << ' ' << ma << ')';
                }
            } else {
                cin >> a >> b;
                ll day_mi, day_ma;
                if(mi-a<=0 && ma-a<=0) {
                    day_mi = day_ma = 1;
                } else {
                    day_mi = (mi-b-1)/(a-b) + 1;
                    day_ma = (ma-b-1)/(a-b) + 1;
                }
                if(day_mi == day_ma) cout << day_mi << ' ';
                else cout << -1 << ' ';
            }
        }
        cout << endl;
    }
    return 0;
}