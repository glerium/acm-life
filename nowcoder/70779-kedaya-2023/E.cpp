#include <bits/stdc++.h>
#define rep(i,x,y) for(int i=x;i<=y;i++)
using namespace std;
const int maxn=1e6+10;
int n,a[maxn],ct[maxn],s[maxn];
int main() {
    ios::sync_with_stdio(false);
    cin>>n;
    rep(i,1,n) {
        cin>>a[i];
        ct[a[i]]++;
    }
    for(int i=1e6;i>=0;i--) s[i]=s[i+1]+ct[i];
    long long ans=-1;
    int idx=-1;
    rep(i,1,1e6) {
        if(1ll*s[i]*i>ans) {
            ans=1ll*s[i]*i;
            idx=i;
        }
    }
    cout<<ans<<' '<<idx<<endl;
}