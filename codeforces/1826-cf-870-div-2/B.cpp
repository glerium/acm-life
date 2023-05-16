#include <bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int t,n,a[maxn];
int gcd(int x,int y){
    return !y?x:gcd(y,x%y);
}
int main(){
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++) cin>>a[i];
        int ans=abs(a[1]-a[n]);
        for(int i=2,j=n-1;i<j;i++,j--) ans=gcd(ans,int(abs(a[i]-a[j])));
        cout<<ans<<endl;
    }
    return 0;
}