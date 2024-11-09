#include <bits/stdc++.h>
using namespace std;
int f[1005][1005];
int lcs(const string &s, const string &t, int n, int m) {
    if(n <= 0 || m <= 0)
        return 0;
    if(f[n][m] != -1)
        return f[n][m];
    if(s[n-1] == t[m-1])
        return f[n][m] = 1 + lcs(s, t, n-1, m-1);
    else
        return f[n][m] = max(lcs(s, t, n, m-1), lcs(s, t, n-1, m));
}
int main() {
    memset(f, -1, sizeof(f));
    string s; cin >> s;
    int n = s.size();
    string t(s.rbegin(), s.rend());
    cout << n - lcs(s, t, n, n) << endl;
    return 0;
}