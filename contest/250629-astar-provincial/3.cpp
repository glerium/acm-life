#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr ll mod = 998244353;
void solve() {
    int n; cin >> n;
    vector<int> a(n+5);
    rep(i,1,n) cin >> a[i];
    int m = *max_element(a.begin() + 1, a.begin() + 1 + n);
    vector<int> ct(m+5);
    rep(i,1,n) ct[a[i]]++;
    vector<int> ans1(n+5), ans2(n+5);

    // gcd != 1 && mex == 1/0 (depending on if zero in the set)
    vector<int> gct(m+5);
    rep(g,1,m) {
        gct[g] = ct[0];
        for(int i=g;i<=m;i+=g)
            gct[g] += ct[i];
    }
    for(int g=m;g>=1;g--)
        gct[g] = max(gct[g], gct[g+1]);
    rep(i,1,n) {
        int l=1,r=m,mid,ans=-1;
        while(l<=r) {
            mid = l + r >> 1;
            if(gct[mid] >= i) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }   // zero in the set
        if(i != 1 && ct[0] > 0)
            ans1[i] = ans ^ 1;
        else    // if zero not exist, then not in the set
            ans1[i] = ans;
    }

    // mex != 1 && gcd == 1/0 (depending on whether all numbers are zero)
    bool ok = true;
    rep(i,1,n) {
        ans2[i] = ans2[i-1];
        if(ok && ct[i-1] > 0) {
            if(i == 1)
                ans2[i] = max(ans2[i], i);          // [0] gcd == 0
            else
                ans2[i] = max(ans2[i], i ^ 1);      // [0 .. i] gcd == 1
        } else {
            ok = false;
        }
    }
    rep(i,1,n) cout << ans1[i] << ' ';
    cout << endl;
    rep(i,1,n) cout << ans2[i] << ' ';
    cout << endl;
    rep(i,1,n) cout << max(ans1[i], ans2[i]) << ' ';
    cout << endl;
}
int main() {
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    while(t--) solve();
    return 0;
}