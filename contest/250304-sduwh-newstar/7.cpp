#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
int s[4][maxn] = {};
bool check(const string& str) {
    int n = str.size() - 1;
    rep(i,1,n) {
        rep(j,0,3) s[j][i] = s[j][i-1];
        s[str[i] - 'A'][i] ++;
    }
    rep(i,10,n) {
        int ct = s[1][i] - s[1][i - 10] + s[2][i] - s[2][i - 10] + s[3][i] - s[3][i - 10];
        if(!ct) return false;
    }
    rep(i,90,n) {
        int ct = s[2][i] - s[2][i - 90] + s[3][i] - s[3][i - 90];
        if(!ct) return false;
    }
    rep(i,180,n) {
        int ct = s[3][i] - s[3][i - 180];
        if(!ct) return false;
    }
    return true;
}
void solve() {
    int n,x,y,z; cin >> n >> x >> y >> z;
    string s = string(n - x - y - z, 'A') + string(x, 'B') + string(y, 'C') + string(z, 'D');
    s = ' ' + s;
    while(!check(s)) {
        random_shuffle(next(s.begin()), s.end());
    }
    cout << s.substr(1) << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}
