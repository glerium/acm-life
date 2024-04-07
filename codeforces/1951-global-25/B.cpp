#include <bits/stdc++.h>
using namespace std;
void solve() {
    int n, k; cin >> n >> k;
    int my;
    vector<int> a(n+5);
    for(int i=1;i<=n;i++) cin>>a[i];
    swap(a[1], a[k]);
    int winner = -1;
    int ans1 = 0;
    for(int i=2;i<=n;i++) {
        if(a[1] < a[i]) break;
        ans1++;
    }
    swap(a[1], a[k]);
    int swapped = false;
    int ans2 = 0;
    for(int i=1;i<=k;i++) {
        if(a[i] > a[k]) {
            swap(a[i], a[k]);
            swapped = i;
            break;
        }
    }
    if(swapped) {
        ans2 = (swapped != 1);
        for(int i=swapped+1;i<=n;i++) {
            if(a[swapped] < a[i]) break;
            ans2++;
        }
    }
    cout << max(ans1, ans2) << endl;
}
int main() {
    int t; cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
