#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
bool is_square(int x) {
    int sq = sqrt(x);
    return sq * sq == x;
}
void solve() {
    int n; string s; cin >> n >> s;
    if(s.find('0') == string::npos) {
        if(n == 4 || n == 1)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        return;
    }
    int cols;
    {
        int i = 0;
        while(s[i] == '1')
            i++;
        int stt = i;
        while(i < s.size() && s[i] == '0')
            i++;
        cols = i - stt + 2;
    }
    if(n % cols != 0) {
        cout << "No" << endl;
        return;
    }
    int rows = n / cols;
    if(rows != cols) {
        cout << "No" << endl;
        return;
    }
    int a[n/cols+2][cols+2] = {};
    for(int i=1;i<=cols;i++)
        a[1][i] = a[rows][i] = 1;
    for(int i=1;i<=rows;i++)
        a[i][1] = a[i][cols] = 1;
    string cr;
    for(int i=1;i<=rows;i++) {
        for(int j=1;j<=cols;j++)
            cr.push_back(a[i][j] + '0');
    }
    if(cr == s)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
