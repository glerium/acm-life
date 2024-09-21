#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define endl '\n'
using namespace std;
typedef long long ll;
struct seg {
    int l,r;
    bool operator<(seg p) {
        if(l!=p.l)return l<p.l;
        else return (r-l)>(p.r-p.l);
    }
};
void solve() {
    int n;cin>>n;
    vector<seg> a(n);
    for(int i=0;i<n;i++)cin>>a[i].l>>a[i].r;
    sort(a.begin(),a.end());
    int ans=0;

    cout<<ans<<'\n';
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;while(t--)solve();
    return 0;
}