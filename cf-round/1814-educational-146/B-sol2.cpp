#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
ll a, b;
inline ll compute(ll x) {
    return x-1 + (a/x+bool(a%x)) + (b/x+bool(b%x));
}
int main() {
    cin>>t;
    while(t--){
        cin>>a>>b;
        ll ans=LONG_LONG_MAX;
        for(int x=1;x<=100000;x++) ans=min(ans,compute(x));
        cout<<ans<<endl;
    }
}