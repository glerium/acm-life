#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    ll n;
    int m,a,b; cin >> n >> m >> a >> b;
    n--;
    ll l[m+5] = {}, r[m+5] = {};
    rep(i,1,m) cin >> l[i] >> r[i];
    rep(i,1,m) l[i]--, r[i]--;
    if(a == b) {
        rep(i,1,m) {
            if(r[i] / a - (l[i] - 1) / a > 0) {
                cout << "No" << endl;
                return;
            }
        }
        if(n % a != 0) {
            cout << "No" << endl;
            return;
        }
        cout << "Yes" << endl;
        return;
    }
    rep(i,1,m) {
        if(r[i]-l[i] > b) {
            cout << "No" << endl;
            return;
        }
    }
    ll lr[m*2+5] = {};
    // l[1], r[1], l[2], r[2], ..., l[m], r[m]
    rep(i,1,m) {
        lr[2*i-1] = l[i];
        lr[2*i] = r[i];
    }
    lr[2*m+1] = n;

    ll clr[m*2+5] = {};
    rep(i,1,2*m+1) clr[i] = lr[i] - lr[i-1];

    rep(i,1,m) {
        // 2*i-1 -> l[i]
        // 2*i -> r[i]
        if(clr[2*i-1] > 200) {
            clr[2*i-1] = 200;
        }
        if(clr[2*i] + 2 > b) {
            cout << "No" << endl;
            return;
        }
    }
    if(clr[2*m+1] > 200) clr[2*m+1] = 200;

    rep(i,1,m) {
        l[i] = r[i-1] + clr[2*i-1];
        r[i] = l[i] + clr[2*i];
    }
    n = r[m] + clr[2*m+1];

    bool block[n+5] = {};
    rep(i,1,m) {
        rep(j,l[i],r[i])
            block[j] = true;
    }

    bool ok[n+5] = {};
    ok[0] = true;
    rep(i,0,n) {
        if(!ok[i]) continue;
        rep(j,i+a,min(i+b,int(n))) {
            if(!block[j])
                ok[j] = true;
        }
    }

    cout << (ok[n] ? "Yes" : "No") << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
