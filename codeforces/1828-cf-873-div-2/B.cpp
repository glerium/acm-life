#include <bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int t,n,a[maxn];
int gcd(int x,int y) {
    return !y?x:gcd(y,x%y);
}
int main() {
    cin>>t;
    while(t--) {
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i], a[i]=abs(a[i]-i);
        int ans=a[1];
        for(int i=1;i<=n;i++) ans=gcd(ans,a[i]);
        cout<<ans<<endl;
    }
    return 0;
}