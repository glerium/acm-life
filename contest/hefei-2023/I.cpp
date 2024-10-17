#include <bits/stdc++.h>
using namespace std;
vector<int> cvt(int x, int k) {
    vector<int> s;
    while(x) {
        int c = x % k;
        x /= k;
        s.push_back(c);
    }
    if(s.size())
        s = vector(s.rbegin(), s.rend());
    else
        s = {0};
    return s;
}
void solve() {
    int n;
    cin >> n;
    int ct[n+5][n+5] = {};
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            auto vec = cvt(i*j, n);
            for(int k=0;k<vec.size();k++) {
                ct[vec[k]][k]++;
            }
        }
    }
    
    int ct2[n+5][n+5] = {};
    for(int i=1;i<=n*n;i++) {
        string s; cin >> s;
        for(int k=0;k<s.size();k++) {
            if(islower(s[k]))
                ct2[s[k]-'a'][k]++;
            else
                ct2[s[k]-'A'+26][k]++;
        }
    }

    bool v[n+5] = {};
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            if(v[j]) continue;
            bool ok = true;
            for(int k=0;k<n;k++) {
                if(ct[i][k] != ct2[j][k]) {
                    ok = false;
                    break;
                }
            }
            if(ok) {
                v[j] = true;
                if(j < 26)
                    cout << char(j + 'a');
                else
                    cout << char(j - 26 + 'A');
                break;
            }
        }
    }
    cout << '\n';
}
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}