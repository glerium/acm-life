#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define endl '\n'
using namespace std;
typedef long long ll;
constexpr ll mod = 1e9+7;
constexpr int maxn = 1e7+10;
int n,a[maxn];
int st[maxn], st2[maxn];
int main() {
    // freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    rep(i,1,n) cin >> a[i];
    ll ans1 = 0, ans2 = 0;
    ll ctz = 0;
    rep(i,1,n) {
        st[a[i]]++;
        st2[a[i]*a[i]]++;
    }
    rep(i,1,n) {
        rep(j,1,n) {
            ans1 += st[a[i]+a[j]];
        }
    }
    rep(i,1,n) {
        rep(j,1,n) {
            ans2 += st2[a[i]*a[i]+a[j]*a[j]];
        }
    }
    ll ans0 = 0;
    rep(i,1,n) {
        rep(j,1,n) {
            if(a[i] != 0 && a[j] != 0)
                continue;
            ans0 += st[a[i]+a[j]];
        }
    }
    rep(i,1,n) ctz += a[i] == 0;
    int k; cin >> k;
    while(k--) {
        int x; cin >> x;
        if(x == 1) cout << ans1 << endl;
        else if(x == 2) cout << ans2 << endl;
        else cout << ans0 << endl;
    }
    return 0;
}
