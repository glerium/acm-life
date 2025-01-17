#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
struct Number {
    int x; 
    int ct;
    bool operator<(const Number& rhs) const {
        return ct > rhs.ct;
    }
};
void solve() {
    int n; cin >> n;
    string g[n+5];
    rep(i,1,n) cin >> g[i];
    rep(i,1,n) g[i] = ' ' + g[i];
    Number ct[n+5] = {};
    rep(i,1,n) ct[i].x = i;
    rep(i,1,n) rep(j,1,i-1) {
        if(g[i][j] == '0') {
            ct[i].ct++;
        }else{
            ct[j].ct++;
        }
    }
    sort(ct+1, ct+1+n);
    rep(i,1,n) cout << ct[i].x << ' ';
    cout << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
