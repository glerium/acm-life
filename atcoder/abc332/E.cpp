#include <bits/stdc++.h>
using namespace std;
int n,m,ct;
long long a[111],s[111];
int main() {
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    double d=0;
    for(int i=1;i<=n;i++) d+=a[i];
    d/=m;
    int l=1;
    for(int i=n;i>l;i--) {
        if(a[i]>d) s[++ct]=a[i];
        else{
            ct++;
            s[ct]=a[i];
            while(s[ct]+a[l]<=d&&l<i) {
                s[ct]+=a[l];
                l++;
            }
        }
    }
    double ans=0;
    for(int i=1;i<=ct;i++) (cout<<s[i]<<endl),ans+=(s[i]-d)*(s[i]-d);
    ans/=ct;
    cout<<fixed<<setprecision(10)<<ans<<endl;
    return 0;
}