#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int maxn=2e5+10;
int t,n,x,y,a[maxn];
map<array<int,2>,int> ct;
void solve() {
    ct.clear();
    cin>>n>>x>>y;
    ll ans=0;
    for(int i=1;i<=n;i++) cin>>a[i];
    for(int i=n;i>=1;i--) {
        ans+=ct[{(x-a[i]%x)%x,(y+a[i]%y)%y}];
        ct[{{a[i]%x,a[i]%y}}]++;
    }
    cout<<ans<<endl;
}
int main(){
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--) solve();
}