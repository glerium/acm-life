#include <bits/stdc++.h>
#define endl '\n'

#define rep(i, o, p) for(int i = o ; i <= p; i ++)
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int cnt1 = 0 , cnt2 = 0;
    rep(i, 0, s.length() - 1) {
        cnt1 += (s[i] == 'C');
        cnt2 += (s[i] == 'P');
    }
    if(cnt1 < 3 || cnt2 < 1) cout << 0;
    else cout << min((cnt1 - 1) / 2, cnt2);
    return 0;
}
