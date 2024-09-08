#include <bits/stdc++.h>
#define endl '\n'
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn = 2e5+10;
constexpr ll mod = 998244353;
void solve() {
    int n; cin>>n;
    int a[n+5]; rep(i,1,n) cin>>a[i];
    if(n>2) cout<<"NO"<<endl;
    else {
        if(abs(a[1]-a[2])<=1) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin>>t;
    while(t--) solve();
    return 0;
}
