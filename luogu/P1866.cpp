#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
typedef long long ll;
const ll p=1e9+7;
using namespace std;
int n,m[100000];
map<int,int> mp;
int main() {
    cin>>n;
    rep(i,1,n) cin>>m[i];
    sort(m+1,m+1+n);
    ll ans=1;
    rep(i,1,n) ans=ans*(m[i]+1-i)%p;
    cout<<ans<<endl;
    return 0;
}