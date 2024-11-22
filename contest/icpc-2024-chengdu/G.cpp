#include <bits/stdc++.h>


#define ll long long
#define rep(i, o, p) for(int i = o; i <= p; i ++) 

using namespace std;

map<int, int> mp;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int a[n + 5] ;
    rep(i, 1, n) cin >> a[i];
    rep(i, 1, n - 1) {
        int x = a[i], y = a[i + 1];
        mp[x] ++;
        mp[y] ++;
        mp[x | y] ++;
        mp[x & y] ++;
        mp[x ^ y] ++;
        mp[x & (x ^ y)] ++;
        mp[y & (x ^ y)] ++;
        mp[(x & y) & (x ^ y)] ++;
    }
    cout << mp.size();
    return 0;
}
