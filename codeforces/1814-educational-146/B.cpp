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
        ll l=1, r=1e9, ans;
        int ct=0;
        while(l<r && ct<=10000){
            if(compute((2*l+r)/3) >= compute((l+2*r)/3)) {
                l = (2*l+r)/3;
                ans = compute((l+2*r)/3);
            }else{
                r = (l+2*r)/3;
                ans = compute((2*l+r)/3);
            }
            // cout<< l << ' '<<r<<endl;
            ct++;
        }
        cout<<ans<<endl;
    }
}