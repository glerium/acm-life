#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
int t;
void solve() {
    int n; cin>>n;
    vector<int> a(n+10);
    rep(i,1,n) cin>>a[i];
    vector<int> v;
    rep(i,1,n-1) {
        if(a[i]!=a[i+1])
            v.push_back(i);
    }
    int q; cin>>q;
    while(q--) {
        int l,r; cin>>l>>r;
        auto ls=lower_bound(v.begin(),v.end(),l);
        auto rs=lower_bound(v.rbegin(),v.rend(),r-1,greater<int>());
        // cout<<";";
        if(ls==v.end()||rs==v.rend()||*ls>*rs||*ls>r||*rs<l) cout<<"-1 -1\n";
        else cout<<(*ls)<<' '<<(*ls)+1<<endl;
    }
    cout<<endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--) solve();
    return 0;
}