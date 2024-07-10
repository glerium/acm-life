#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int n,q; cin >> n >> q;
    int a[n+5]={}, s[n+5]={};
    rep(i,1,n) cin >> a[i];
    rep(i,1,n) s[i] = s[i-1] ^ a[i];
    map<int,vector<int>> mp;
    rep(i,1,n) mp[s[i]].push_back(i);
    while(q--) {
        int l,r; cin >> l >> r;
        if(s[l-1] == s[r]) {
            puts("YES");
            continue;
        }
        auto at = upper_bound(mp[s[l-1]].rbegin(), mp[s[l-1]].rend(), r, greater<int>());
        auto as = upper_bound(mp[s[r]].begin(), mp[s[r]].end(), l-1);
        if(at == mp[s[l-1]].rend() || as == mp[s[r]].end() || *as > *at)
            puts("NO");
        else
            puts("YES");
    }
    puts("");
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
