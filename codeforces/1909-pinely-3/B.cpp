#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
typedef long long ll;
constexpr int maxn=1003;
int t,n;
ll a[maxn];
int check(){
    bool odd=true, even=true;
    rep(i,1,n) {
        if(a[i]&1) even=false;
        else odd=false;
    }
    if(!odd&&!even) return 0;
    else if(odd) return 1;
    else return 2;
}
int main() {
    ios::sync_with_stdio(false);
    cin>>t;
    while(t--) {
        cin>>n;
        rep(i,1,n) cin>>a[i];
        if(n<=2) {
            cout<<(ll)1e18<<endl;
            continue;
        }
        ll ans=2;
        int flag;
        while(flag=check()) {
            if(flag==1) rep(i,1,n) a[i]--;
            else {
                ans*=2;
                rep(i,1,n) a[i]/=2;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}