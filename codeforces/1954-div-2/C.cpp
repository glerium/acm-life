#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    string a,b; cin>>a>>b;
    int n=a.size();
    bool found = false;
    bool sel[n+5];
    rep(i,0,n-1) {
        if(found) sel[i] = 1;
        else {
            if(a[i] == b[i]) sel[i] = 1;
            else {
                sel[i] = 0;
                found = true;
            }
        }
    }
    rep(i,0,n-1) cout << (sel[i] ? max(a[i],b[i]) : min(a[i],b[i]));
    cout << endl;
    rep(i,0,n-1) cout << (!sel[i] ? max(a[i],b[i]) : min(a[i],b[i]));
    cout << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
