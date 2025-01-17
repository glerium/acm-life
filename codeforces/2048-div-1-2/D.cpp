#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int n,m; cin >> n >> m;
    int a[n+5] = {}, b[m+5] = {};
    rep(i,1,n) cin >> a[i];
    rep(i,1,m) cin >> b[i];
    vector<int> vec;
    rep(i,1,n) vec.push_back(a[i]);
    rep(i,1,m) vec.push_back(b[i]);
    sort(vec.begin(), vec.end());
    map<int,int> st;
    int ct = 0;
    for(auto i : vec) {
        if(!st.count(i)) {
            st[i] = ++ct;
        }
    }
    rep(i,1,n) a[i] = st[a[i]];
    rep(i,1,m) b[i] = st[b[i]];
    int rt = a[1];
    sort(a+1, a+1+n);
    sort(b+1, b+1+m);
    int cta[ct+5] = {}, ctb[ct+5] = {}, sa[ct+5]={}, sb[ct+5]={};
    rep(i,1,n) cta[a[i]]++;
    rep(i,1,m) ctb[b[i]]++;
    rep(i,1,ct) sa[i] = sa[i-1] + cta[i];
    rep(i,1,ct) sb[i] = sb[i-1] + ctb[i];
    int nmsl[m+5] = {};
    rep(i,1,m) {
        if(b[i] <= rt)
            nmsl[i] = 0;
        else
            nmsl[i] = (sa[ct] - sa[b[i]-1]);
    }
    sort(nmsl+1, nmsl+1+m);
    ll ans[m+5] = {};
    rep(i,1,m) {
        ans[i] = m / i;
        for(int j=i;j<=m;j+=i) {
            ans[i] += nmsl[j];
        }
    }
    rep(i,1,m) cout << ans[i] << ' ';
    cout << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
