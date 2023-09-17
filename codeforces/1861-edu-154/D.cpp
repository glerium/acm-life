#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
#define per(i,x,y) for(int i=x;i>=y;i--)
using namespace std;
const int maxn=2e5+10;
int _,n,a[maxn],s1[maxn],s2[maxn];
int main() {
    ios::sync_with_stdio(false);
    cin>>_;
    while(_--) {
        cin>>n;
        rep(i,1,n) cin>>a[i];
        rep(i,0,n) s1[i]=s2[i]=0;
        per(i,n-1,1) s1[i]=s1[i+1]+(a[i+1]<=a[i]);
        rep(i,2,n) s2[i]=s2[i-1]+(a[i]>=a[i-1]);
        int ans=INT_MAX;
        rep(i,1,n) ans=min(ans,s1[i+1]+s2[i]+1);
        ans=min(ans,s1[1]);
        cout<<ans<<endl;
    }
    return 0;
}