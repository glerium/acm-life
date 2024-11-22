#include <bits/stdc++.h>
#define endl '\n'
#define no cout << "No" << endl
using namespace std;
void solve() {
    string s; cin >> s;
    int n = s.size();
    s = ' ' + s;
    if(s[1] != '>') {
        no;
        return;
    }
    if(s[n] != '>' || s[n-1] != '>' || s[n-2] != '>') {
        no;
        return;
    }
    bool ok = false;
    for(int i=1;i<=n;i++) {
        if(s[i] == '-') {
            ok = true;
            break;
        }
    }
    if(!ok) {
        no;
        return;
    }
    int start = n;
    for(start=n;start>=1;start--) {
        if(s[start] != '>')
            break;
    }
    int end = start + 3;
    vector<pair<int,int>> ans;
    // string str(n, '*');
    // str = ' ' + str;
    for(int i=n;i>=end+1;i--) {
        ans.push_back({1, i});
        // for(int j=1;j<=i;j++) {
        //     if(j == 1 || j >= i-2)
        //         str[j] = '>';
        //     else
        //         str[j] = '-';
        // }
    }
    for(int i=1;i<=end-3;i++) {
        if(s[i] == '-')
            continue;
        ans.push_back({i, end});
        // for(int j=i;j<=end;j++) {
        //     if(j == i || j >= end-2)
        //         str[j] = '>';
        //     else
        //         str[j] = '-';
        // }
    }
    cout << "Yes " << ans.size() << endl;
    for(auto [x, y] : ans) {
        cout << x << ' ' << y - x + 1 << endl;
    }
    // cout << "Final: " << str << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}
