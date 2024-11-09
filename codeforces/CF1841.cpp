#include <bits/stdc++.h>
#define yes s += '1'
#define no s += '0'
using namespace std;
constexpr int maxn = 1e5+10;
int n, a[maxn];
void solve() {
    cin >> n;
    bool first = true;
    int mi1 = -1, mx1 = -1, mx2 = -1;
    string s; 
    for(int i=1;i<=n;i++) {
        int x; cin >> x;
        if(i == 1) mi1 = x;
        if(first) {
            if(x >= mx1) {
                mx1 = x;
                yes;
            } else if (x <= mi1) {
                first = false;
                mx2 = x;
                yes;
            } else no;
        } else {
            if(x <= mi1 && x >= mx2) {
                mx2 = x;
                yes;
            }
            else no;
        }
    }
    cout << s << endl;
}
int main() {
    ios::sync_with_stdio(false);
    int t; 
    cin >> t;
    while(t--) solve();
    return 0;
}