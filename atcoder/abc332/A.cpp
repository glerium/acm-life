#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=107;
ll n,s,k,p[maxn],q[maxn];
int main() {
    cin>>n>>s>>k;
    ll ans=0;
    for(int i=1;i<=n;i++) {
        cin>>p[i]>>q[i];
        ans+=p[i]*1ll*q[i];
    }
    if(ans<s) ans+=k;
    cout<<ans;
}