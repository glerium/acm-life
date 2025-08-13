#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
void solve() {
    int n; cin >> n;
    vector<int> a(30);
    rep(i,0,25) cin >> a[i];
    string s; cin >> s;
    s = ' ' + s;
    vector<int> f(30);
    rep(i,1,n) {
        if(f[s[i]-'a'] == 0) {
            f[s[i]-'a'] += a[s[i]-'a'] - 1;
        } else {
            if(s[i] != s[i-1])
            rep(j,0,25) {
                if(j + 'a' == s[i]) continue;
                if(f[j] == 0) continue;
                cout << "No" << endl;
                return;
            }
            f[s[i]-'a']--;
        }
    }
    rep(i,0,25) {
        if(f[i] != 0) {
            cout << "No" << endl;
            return;
        }
    }
    cout << "Yes" << endl;
}
int main() {
    int t; cin >> t;
    while(t--) {
        solve();
    }
}