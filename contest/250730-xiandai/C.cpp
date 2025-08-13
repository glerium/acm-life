#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
void solve() {
    int n,k; cin >> n >> k;
    vector<pair<int,int>> a(n+5), b(n+5);
    rep(i,1,n) {
        cin >> a[i].first;
        b[i].first = a[i].first ^ k;
        a[i].second = b[i].second = i;
    }
    sort(a.begin() + 1, a.begin() + 1 + n);
    sort(b.begin() + 1, b.begin() + 1 + n);
    vector<bool> v(n+5, false);
    int i = 1, j = 1;
    bool flag = true;   // true: b
    int ans = 0, ansflag = true;
    int ct = 0;
    while(i <= n && j <= n) {
        if(flag) {
            while(v[b[j].second]) j++;
            v[b[j].second] = true;
            ans = b[j].second;
            ansflag = false;
        } else {
            while(v[a[i].second]) i++;
            v[a[i].second] = true;
            ans = a[i].second;
            ansflag = true;
        }
        flag = !flag;
        ct++;
        if(ct == n) break;
    }
    if(ansflag == true) {
        rep(i,1,n) if(b[i].second == ans) {
            cout << b[i].first << endl;
        }
    } else {
        rep(i,1,n) if(a[i].second == ans) {
            cout << a[i].first << endl;
        }
    }
}
int main() {
    int t = 1;
    while(t--) {
        solve();
    }
}