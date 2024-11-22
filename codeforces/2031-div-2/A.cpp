#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    for(int i=1;i<=t;i++) {
        int n; cin >> n;
        map<int,int> mp;
        for(int j=1;j<=n;j++) {
            int tmp; cin >> tmp;
            mp[tmp]++;
        }
        int mx = 0;
        for(auto [x,y] : mp)
            mx = max(mx, y);
        cout << n - mx << endl;
    }
}